RTOS Communicating Tasks Project (ELC 2080)

Objective: Apply embedded RTOS concepts — tasks, timers, queues, and semaphores — using FreeRTOS on an emulated target board (Eclipse CDT Embedded).

What's Covered


4 tasks communicating through a fixed-size queue:

3 sender tasks (2 equal priority, 1 higher priority), each waking at a random interval to send a timestamped message, tracking sent/blocked message counts
1 receiver task, waking at a fixed interval to read one message at a time from the queue



Timers & semaphores control task wake-up: each task blocks on a dedicated semaphore released by its timer's callback function
Reset logic, triggered every 1000 received messages (and once at startup):

Prints total sent/blocked messages and per-sender-task statistics
Resets counters and clears the queue
Advances the sender timer's random period range to the next value in a predefined schedule
Stops execution ("Game Over") once all period ranges are exhausted



Experiments: run with queue sizes of 3 and 10, and plot sent/blocked message counts vs. average sender period (overall and per priority level)


Key Takeaway

The project demonstrates producer-consumer synchronization under RTOS scheduling — how task priority, queue size, and timing variability affect message throughput and blocking behavior.




Tools

FreeRTOS · Eclipse CDT Embedded
