Rate-Monotonic Scheduling Assignment (ELC-4030)

Objective: Implement and analyze Rate-Monotonic (RM) Scheduling of periodic real-time tasks on Linux using POSIX threads and the SCHED_FIFO policy.

What's Covered


POSIX time handling — using clock_gettime, clock_nanosleep (TIMER_ABSTIME), and helper functions (timespec_add_us, timespec_cmp) to implement precise periodic task timing that stays correct despite variable execution time or interruptions
Rate-Monotonic Scheduling — creating 3 periodic threads (e.g. 100/200/300 ms periods), each simulating CPU load via a compute-bound nested loop, scheduled with fixed priorities assigned by RM (shorter period → higher priority) under SCHED_FIFO
Deadline monitoring — tracing task start times and detecting/reporting missed deadlines (deadline = period)
RM optimality demonstration — showing a case where RM priority assignment meets all deadlines, while an alternative fixed-priority assignment (same periods/execution times) misses deadlines
System-level observation using top -H / htop — estimating per-task CPU utilization, identifying which core each thread runs on, and observing whether background threads or other applications interfere with the periodic tasks' timing (with and without explicit core affinity)


Key Takeaway

RM scheduling is provably optimal among fixed-priority assignments for periodic tasks (shorter period = higher priority), but real-world scheduling behavior — core placement, background interference, and CPU affinity — can still affect whether deadlines are actually met in practice.

Tools

Linux · POSIX threads · SCHED_FIFO · top -H / htop

