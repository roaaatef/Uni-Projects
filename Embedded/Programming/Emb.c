#define_GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sched.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<string.h>
//====================Configuration====================
//Taskperiodsinmilliseconds
constlongperiods_ms[3]= {100,200, 300};
//RMSpriorities (shorterperiod=higherpriority)
intrms_priorities[3]= {90,80,70};
//Globalflagsandcounters
staticintdeadline_miss_detected=0;
staticintusing_realtime=0;
//Workloadloopsizes(simulatedCPUload)
constlongn1=10000;
constlongn2=2500;
//Timestampmarking programstart
staticstructtimespecprogram_start_time;
//Cyclecounters
staticinttask1_cycles=0;
staticinttask2_cycles=0;
staticinttask3_cycles=0;
//Deadlinemisscounters
staticintdeadline_misses_task1= 0;
staticintdeadline_misses_task2= 0;
staticintdeadline_misses_task3= 0;
//====================TimeHelpers====================
//GetCPUtimeforthecurrentthread(excludestimewhen preempted)
longget_thread_cpu_time_us(){
structtimespects;
clock_gettime(CLOCK_THREAD_CPUTIME_ID,&ts);
returnts.tv_sec*1000000+ts.tv_nsec /1000;
}
//Addmicrosecondstoatimespecstructure
voidtimespec_add_us(structtimespec*t, longus) {
t->tv_sec+=us/1000000;
t->tv_nsec +=(us% 1000000)* 1000;
if(t->tv_nsec>=1000000000){
t->tv_sec++;
t->tv_nsec-=1000000000;
}
}
//Comparetwotimespecvalues
inttimespec_cmp(structtimespec*a,structtimespec*b) {
if(a->tv_sec!=b->tv_sec)
return(a->tv_sec> b->tv_sec) ?1:-1;
if(a->tv_nsec !=b->tv_nsec)
return(a->tv_nsec>b->tv_nsec)?1 :-1;
return0;
}
//Millisecondssinceprogramstart(wallclocktime)
longget_elapsed_ms(){
structtimespeccurrent_time;
clock_gettime(CLOCK_MONOTONIC,&current_time);
longsec=current_time.tv_sec-program_start_time.tv_sec;
longnsec= current_time.tv_nsec-program_start_time.tv_nsec;
if(nsec<0){
sec--;
nsec +=1000000000;
}
returnsec*1000 +nsec/ 1000000;
}
//Currentwall clocktimeinmicroseconds
longget_time_us(){
structtimespects;
clock_gettime(CLOCK_MONOTONIC,&ts);
returnts.tv_sec*1000000 +ts.tv_nsec/1000;
}
//====================WorkloadSimulation====================
//Simplenestedloopsused togenerateCPUload
voidsimulate_workload(){
volatileinta;
for(longi =0;i< n1;i++){
for(longj= 0; j<n2;j++){
a= j/2;
}
}
(void)a;
}
//====================TaskFunction====================
//Periodictaskexecutedbyeachthread
void*task_function(void *arg) {
inttask_id =*(int*)arg;
structtimespecnext_wakeup=program_start_time;
printf("Task%dthreadstartedsuccessfully\n",task_id);
for(intk=0;k <500;k++){
//Updatecyclecount
if(task_id==1)task1_cycles++;
if(task_id==2)task2_cycles++;
if(task_id==3)task3_cycles++;
//Printstarttimestamp(wallclock)
long start_wall_ms=get_elapsed_ms();
printf("Task%dstartedat%ldms(Cycle%d)\n",
task_id,start_wall_ms,k+1);
//MeasureACTUALCPUexecutiontime(excludespreemptiontime)
longcpu_start_us=get_thread_cpu_time_us();
longwall_start_us= get_time_us();
simulate_workload();
longcpu_end_us= get_thread_cpu_time_us();
longwall_end_us=get_time_us();
longcpu_time_us=cpu_end_us-cpu_start_us;
longwall_time_us=wall_end_us-wall_start_us;
//Printendtimestamp(wallclock)
longfinish_wall_ms=get_elapsed_ms();
printf("Task%dfinishedat%ldms(Cycle%d)\n",
task_id,finish_wall_ms,k+1);
//Executiondurationinms(actualCPUtimeonly)
printf(" Executiontime:%.0fms\n", cpu_time_us/1000.0);
//Computenextactivationtime
next_wakeup.tv_sec+=periods_ms[task_id-1]/1000;
next_wakeup.tv_nsec+=(periods_ms[task_id-1]% 1000) *1000000;
if(next_wakeup.tv_nsec >=1000000000){
next_wakeup.tv_sec++;
next_wakeup.tv_nsec-=1000000000;
}
//Checkfordeadlinemiss
structtimespecnow;
clock_gettime(CLOCK_MONOTONIC,&now);
if(timespec_cmp(&now,&next_wakeup)>0){
printf("DEADLINEMISS:Task %d(Cycle%d)\n", task_id,k+ 1);
deadline_miss_detected= 1;
if(task_id==1)deadline_misses_task1++;
if(task_id==2)deadline_misses_task2++;
if(task_id==3)deadline_misses_task3++;
}
//Sleepuntilnextperiod
clock_nanosleep(CLOCK_MONOTONIC,TIMER_ABSTIME,&next_wakeup,NULL);
}
printf("Task%dcompletedallcycles\n",task_id);
returnNULL;
}
//====================Main Function====================
intmain(){
printf("RateMonotonicScheduling\n");
printf("=========================\n");
inttask1_id=1,task2_id=2,task3_id=3;
pthread_tthread1,thread2,thread3;
pthread_attr_tattr1,attr2,attr3;
cpu_set_tcpu1,cpu2,cpu3;
structsched_parammyparam;
intret;
printf("TaskSetup:\n");
printf("Task1->Period:100msPriority:%d\n",rms_priorities[0]);
printf("Task2->Period:200msPriority:%d\n",rms_priorities[1]);
printf("Task3->Period:300msPriority:%d\n\n",rms_priorities[2]);
printf("Workload:n1=%ldn2=%ld\n\n",n1,n2);
//--------Task1 (highestpriority)--------
pthread_attr_init(&attr1);
pthread_attr_setinheritsched(&attr1,PTHREAD_EXPLICIT_SCHED);
ret=pthread_attr_setschedpolicy(&attr1,SCHED_FIFO);
if(ret!=0){
printf("Warning:CannotsetSCHED_FIFO(needroot).Usingdefaultscheduling.\n");
pthread_attr_setschedpolicy(&attr1,SCHED_OTHER);
}else {
using_realtime=1;
}
CPU_ZERO(&cpu1);
CPU_SET(0,&cpu1);
pthread_attr_setaffinity_np(&attr1,sizeof(cpu_set_t),&cpu1);
if(using_realtime){
myparam.sched_priority=rms_priorities[0];
pthread_attr_setschedparam(&attr1,&myparam);
}
//--------Task2--------
pthread_attr_init(&attr2);
pthread_attr_setinheritsched(&attr2,PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr2,using_realtime?SCHED_FIFO:SCHED_OTHER);
CPU_ZERO(&cpu2);
CPU_SET(0,&cpu2);
pthread_attr_setaffinity_np(&attr2,sizeof(cpu_set_t),&cpu2);
if(using_realtime){
myparam.sched_priority=rms_priorities[1];
pthread_attr_setschedparam(&attr2,&myparam);
}
//--------Task3--------
pthread_attr_init(&attr3);
pthread_attr_setinheritsched(&attr3,PTHREAD_EXPLICIT_SCHED);
pthread_attr_setschedpolicy(&attr3,using_realtime?SCHED_FIFO:SCHED_OTHER);
CPU_ZERO(&cpu3);
CPU_SET(0,&cpu3);
pthread_attr_setaffinity_np(&attr3,sizeof(cpu_set_t),&cpu3);
if(using_realtime){
myparam.sched_priority=rms_priorities[2];
pthread_attr_setschedparam(&attr3,&myparam);
}
printf("Startingexecution...\n");
if(using_realtime){
printf("UsingSCHED_FIFOreal-timescheduling\n");
}else{
printf("UsingSCHED_OTHER(run withsudoforreal-timescheduling)\n");
}
printf("=====================\n");
//Setstarttime thenimmediatelystarttasks
clock_gettime(CLOCK_MONOTONIC,&program_start_time);
ret= pthread_create(&thread1,&attr1,task_function,&task1_id);
if(ret!=0){
printf("ERROR:pthread_createfailedfortask 1:%s\n",strerror(ret));
return1;
}
ret= pthread_create(&thread2,&attr2,task_function,&task2_id);
if(ret!=0){
printf("ERROR:pthread_createfailedfortask 2:%s\n",strerror(ret));
return1;
}
ret= pthread_create(&thread3,&attr3,task_function,&task3_id);
if(ret!=0){
printf("ERROR:pthread_createfailedfortask 3:%s\n",strerror(ret));
return1;
}
//Waitforalltaskstocomplete
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
pthread_join(thread3,NULL);
pthread_attr_destroy(&attr1);
pthread_attr_destroy(&attr2);
pthread_attr_destroy(&attr3);
//Summary
printf("\n=====================\n");
printf("EXECUTION SUMMARY\n");
printf("=====================\n");
printf("Task1 cycles:%d\n",task1_cycles);
printf("Task2 cycles:%d\n",task2_cycles);
printf("Task3 cycles:%d\n",task3_cycles);
if(!deadline_miss_detected)
printf("\n✓Alldeadlineswere met.\n");
else
printf("\n⚠Deadlinemissesoccurred.\n");
printf("Task1 deadlinemisses:%d\n",deadline_misses_task1);
printf("Task2 deadlinemisses:%d\n",deadline_misses_task2);
printf("Task3 deadlinemisses:%d\n",deadline_misses_task3);
return0;
}