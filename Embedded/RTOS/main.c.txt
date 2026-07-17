/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2014 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h"
#include "diag/trace.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#define CCM_RAM __attribute__((section(".ccmram")))

//The tasks priorities
#define SENDER_ONE_PRIORITY     (1)
#define SENDER_TWO_PRIORITY     (1)
#define SENDER_HIGH_PRIORITY    (2)  //The highest priority task
#define RECEIVER_PRIORITY       (3)
//the queue size
#define QUEUE_SIZE              (3) // experiment1:size = 3    experiment2:size = 10


// Semaphore handles declaration
xSemaphoreHandle task1Semphr = 0;
xSemaphoreHandle task2Semphr = 0;
xSemaphoreHandle taskHighSemphr = 0;
xSemaphoreHandle taskRecSemphr = 0;


// Global queue handle declaration
xQueueHandle Global_Queue_Handle = 0;


// Timer handles declaration
static TimerHandle_t xTimer1 = NULL;
static TimerHandle_t xTimer2 = NULL;
static TimerHandle_t xTimer3 = NULL;
static TimerHandle_t xTimer4 = NULL;

/*these variables are used to store the starting status of the timers
 *These variables help in verifying whether the timers were successfully started*/
BaseType_t xTimer1Started, xTimer2Started, xTimer3Started, xTimer4Started;


//This function takes lower and upper limit as parameters and return a random value to be used as Tsender period
int randomTime(int,int);


//this function calculates the average sender period
int getAverageTsender(int,int);



// Global variables
int Tsender ;
int successfullySent1 = 0;
int successfullySent2 = 0;
int successfullySentHigh = 0;

int blockedMessages1 = 0;
int blockedMessages2 = 0;
int blockedMessagesHigh = 0;

int receivedMessage = 0;

int lowerLimit;
int upperLimit;

//Arrays to set the boundaries of Tsender
const int arr1[6] = {50, 80, 110, 140, 170, 200};
const int arr2[6] = {150, 200, 250, 300, 350, 400};

//iterations:from 1 to 6
int iteration = 0;

// Global variables for tracking Tsender sum and count (for average calculations)
int totalTsender = 0;
int tsenderCount = 0;

//Global variables for each sender task (for average calculations)
int totalTsender1 = 0;
int totalTsender2 = 0;
int totalTsender3 = 0;
int tsenderCount1 = 0;
int tsenderCount2 = 0;
int tsenderCount3 = 0;


int randomTime(int lower, int upper)
{
    return ((rand() % (upper - lower + 1)) + lower);
}


// This function is executed at the end of each iteration to print total sent and blocked messages and reset the global variables
void printStats()
{
    printf("Total number of successfully sent messages: %d\n", successfullySent1 + successfullySent2 + successfullySentHigh);
    printf("Total number of blocked messages: %d\n", blockedMessages1 + blockedMessages2 + blockedMessagesHigh);
    printf("Total number of sent messages: %d\n", successfullySent1 + successfullySent2 + successfullySentHigh + blockedMessages1 + blockedMessages2 + blockedMessagesHigh);
    printf("Sender 1 - Sent: %d,susSent: %d, Blocked: %d\n", successfullySent1 + blockedMessages1, successfullySent1, blockedMessages1);
    printf("Sender 2 - Sent: %d,susSent: %d, Blocked: %d\n", successfullySent2 + blockedMessages2, successfullySent2, blockedMessages2);
    printf("Sender High - Sent: %d,susSent: %d, Blocked: %d\n", successfullySentHigh + blockedMessagesHigh, successfullySentHigh, blockedMessagesHigh);
    printf("Total Average Tsender: %d ms\n", getAverageTsender(totalTsender,tsenderCount));
    printf("Average Tsender for task1: %d ms\n", getAverageTsender(totalTsender1,tsenderCount1));
    printf("Average Tsender for task2: %d ms\n", getAverageTsender(totalTsender2,tsenderCount2));
    printf("Average Tsender for taskHigh: %d ms\n", getAverageTsender(totalTsender3,tsenderCount3));

    //Reserting the global variables
    successfullySent1 = 0;
    successfullySent2 = 0;
    successfullySentHigh = 0;
    blockedMessages1 = 0;
    blockedMessages2 = 0;
    blockedMessagesHigh = 0;
    receivedMessage = 0;

    //Reserting the variables that track Tsender (for Average calculation)
    totalTsender = 0;
    tsenderCount = 0;

    totalTsender1 = 0;
    totalTsender2 = 0;
    totalTsender3 = 0;
    tsenderCount1 = 0;
    tsenderCount2 = 0;
    tsenderCount3 = 0;
}

void resetSystem()
{
    xQueueReset(Global_Queue_Handle); // Clear queue

    if (iteration < 6) // Configure upper and lower limits
    {
        lowerLimit = arr1[iteration];
        upperLimit = arr2[iteration];
        iteration++;
    }
    //you have reached the ends of the arrays of the bounds
    else
    {
        // Destroy all timers
        xTimerDelete(xTimer1, 0);
        xTimerDelete(xTimer2, 0);
        xTimerDelete(xTimer3, 0);
        xTimerDelete(xTimer4, 0);

        printStats();

        printf("Game over\n");

        // exit(0): ends the execution of the program (terminates it)
        exit(0);
    }
}


/*These 3 functions start execution when sender tasks are awake to send messages inside the queue*/
void sender1_task(void *p)   //Sender Task1
{
    char str[20];
    TickType_t XYZ;
    BaseType_t status;

    while (1)
    {
        XYZ = xTaskGetTickCount();

        if (xSemaphoreTake(task1Semphr, portMAX_DELAY) == pdTRUE)   //portMAX_DELAY:waiting forever till getting the semaphore
        {
            sprintf(str, "Time is %lu", XYZ);
            printf("%s\n", str);
            status = xQueueSend(Global_Queue_Handle, &str, 0);

            if (status != pdPASS)
            {
                blockedMessages1++;
            }
            else
            {
                successfullySent1++;
            }
        }
    }
}

void sender2_task(void *p)   //Sender Task2
{
    char str[20];
    TickType_t XYZ;
    BaseType_t status;

    while (1)
    {
        XYZ = xTaskGetTickCount();

        if (xSemaphoreTake(task2Semphr, portMAX_DELAY) == pdTRUE)
        {
            sprintf(str, "Time is %lu", XYZ);
            printf("%s\n", str);
            status = xQueueSend(Global_Queue_Handle, &str, 0);

            if (status != pdPASS)
            {
                blockedMessages2++;
            }
            else
            {
                successfullySent2++;
            }
        }
    }
}

void senderHigh_task(void *p)   //Sender Task3(The highest priority)
{
    char str[20];
    TickType_t XYZ;
    BaseType_t status;

    while (1)
    {
        XYZ = xTaskGetTickCount();

        if (xSemaphoreTake(taskHighSemphr, portMAX_DELAY) == pdTRUE)
        {
            sprintf(str, "Time is %lu", XYZ);
            printf("%s\n", str);
            status = xQueueSend(Global_Queue_Handle, &str, 0);

            if (status != pdPASS)
            {
                blockedMessagesHigh++;
            }
            else
            {
                successfullySentHigh++;
            }
        }
    }
}

/*This function starts execution when receiver task is awake to read messages from the queue
 * it only reads one message at a time*/
void receiver_task(void *p)   //Receiver Task
{
    char str[20];
    BaseType_t status;

    while (1)
    {
    	if (xSemaphoreTake(taskRecSemphr, portMAX_DELAY) == pdTRUE)
        {
            status = xQueueReceive(Global_Queue_Handle, &str, 0);

            if (status == pdPASS)
            {
                receivedMessage++;
            }
        }
    }
}



/*These functions are used for sleep/wake control of tasks by giving the semaphores*/
static void timer1Callback(TimerHandle_t xTimer)   //Sender1
{
    xSemaphoreGive(task1Semphr);
    Tsender = randomTime(lowerLimit, upperLimit);

    // Update the average total tracking variables for Tsender
    totalTsender += Tsender;
    tsenderCount++;

    //update average tracking variables for this task
    totalTsender1 += Tsender;
    tsenderCount1++;

    if (!xTimerChangePeriod(xTimer, pdMS_TO_TICKS(Tsender), 0))
    {
        puts("Failed to change the period\n");
    }
}

static void timer2Callback(TimerHandle_t xTimer)   //sender2
{
    xSemaphoreGive(task2Semphr);
    Tsender = randomTime(lowerLimit, upperLimit);

    // Update the average total tracking variables for Tsender
    totalTsender += Tsender;
    tsenderCount++;

    //update average tracking variables for this task
    totalTsender2 += Tsender;
    tsenderCount2++;

    if (!xTimerChangePeriod(xTimer, pdMS_TO_TICKS(Tsender), 0))
    {
        puts("Failed to change the period\n");
    }
}

static void timerHighCallback(TimerHandle_t xTimer)   //Highest priority sender
{
    xSemaphoreGive(taskHighSemphr);
    Tsender = randomTime(lowerLimit, upperLimit);

    // Update the average total tracking variables for Tsender
    totalTsender += Tsender;
    tsenderCount++;

    //update average tracking variables for this task
    totalTsender3 += Tsender;
    tsenderCount3++;

    if (!xTimerChangePeriod(xTimer, pdMS_TO_TICKS(Tsender), 0))
    {
        puts("Failed to change the period\n");
    }
}

//It controls the end of each iteration by reseting the system when receivedMessage = 1000
static void timer4Callback(TimerHandle_t xTimer)   //Receiver
{
    xSemaphoreGive(taskRecSemphr);
    if (receivedMessage == 1000)
    {
    	printStats();
        resetSystem();
    }
}

int getAverageTsender(totalTsender,tsenderCount)
{
    if (tsenderCount == 0)
    {
        return 0; // Avoid division by zero
    }
    return (totalTsender / tsenderCount);
}




/**************************************The main function***********************************/
int main(int argc, char *argv[])
{
	//srand(time(0));    //can be used to have a different sequence everytime we generate random numbers (if wanted)
    vSemaphoreCreateBinary(task1Semphr);
    vSemaphoreCreateBinary(task2Semphr);
    vSemaphoreCreateBinary(taskHighSemphr);
    vSemaphoreCreateBinary(taskRecSemphr);

    Global_Queue_Handle = xQueueCreate(QUEUE_SIZE, sizeof(char) * 20); // Queue size variable.

    if (Global_Queue_Handle != NULL)
    {
        int Treceiver = 100;

        resetSystem(); // Configure the boundaries as it is required to be used in main

        Tsender = randomTime(lowerLimit, upperLimit); //for initializing

        xTimer1 = xTimerCreate("TimerSender1", (pdMS_TO_TICKS(Tsender)), pdTRUE, (void *)0, timer1Callback);
        xTimer2 = xTimerCreate("TimerSender2", (pdMS_TO_TICKS(Tsender)), pdTRUE, (void *)1, timer2Callback);
        xTimer3 = xTimerCreate("TimerSenderHigh", (pdMS_TO_TICKS(Tsender)), pdTRUE, (void *)2, timerHighCallback);
        xTimer4 = xTimerCreate("TimerReceiver", (pdMS_TO_TICKS(Treceiver)), pdTRUE, (void *)3, timer4Callback);

        xTimerStart(xTimer1, 0);
        xTimerStart(xTimer2, 0);
        xTimerStart(xTimer3, 0);
        xTimerStart(xTimer4, 0);

        xTaskCreate(sender1_task, "Sender 1", 1024, NULL, SENDER_ONE_PRIORITY, NULL);
        xTaskCreate(sender2_task, "Sender 2", 1024, NULL, SENDER_TWO_PRIORITY, NULL);
        xTaskCreate(senderHigh_task, "Sender High", 1024, NULL, SENDER_HIGH_PRIORITY, NULL);
        xTaskCreate(receiver_task, "Receiver", 1024, NULL, RECEIVER_PRIORITY, NULL);

        vTaskStartScheduler();
    }
    else
    {
        puts("Queue can not be created\n");
    }

    return 0;
}



void vApplicationMallocFailedHook( void )
{
	/* Called if a call to pvPortMalloc() fails because there is insufficient
	free memory available in the FreeRTOS heap.  pvPortMalloc() is called
	internally by FreeRTOS API functions that create tasks, queues, software
	timers, and semaphores.  The size of the FreeRTOS heap is set by the
	configTOTAL_HEAP_SIZE configuration constant in FreeRTOSConfig.h. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
	( void ) pcTaskName;
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
	configconfigCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	function is called if a stack overflow is detected. */
	for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
volatile size_t xFreeStackSpace;

	/* This function is called on each cycle of the idle task.  In this case it
	does nothing useful, other than report the amout of FreeRTOS heap that
	remains unallocated. */
	xFreeStackSpace = xPortGetFreeHeapSize();

	if( xFreeStackSpace > 100 )
	{
		/* By now, the kernel has allocated everything it is going to, so
		if there is a lot of heap remaining unallocated then
		the value of configTOTAL_HEAP_SIZE in FreeRTOSConfig.h can be
		reduced accordingly. */
	}
}

void vApplicationTickHook(void) {
}

StaticTask_t xIdleTaskTCB CCM_RAM;
StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE] CCM_RAM;

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
  /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
  state will be stored. */
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

  /* Pass out the array that will be used as the Idle task's stack. */
  *ppxIdleTaskStackBuffer = uxIdleTaskStack;

  /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
  Note that, as the array is necessarily of type StackType_t,
  configMINIMAL_STACK_SIZE is specified in words, not bytes. */
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

static StaticTask_t xTimerTaskTCB CCM_RAM;
static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH] CCM_RAM;

/* configUSE_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so the
application must provide an implementation of vApplicationGetTimerTaskMemory()
to provide the memory that is used by the Timer service task. */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize) {
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
  *ppxTimerTaskStackBuffer = uxTimerTaskStack;
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}


