Lab 9: Tuning from Open Loop Tests

Objective: Practice open-loop process identification and calculate PID tuning parameters from the resulting data.

What's Covered


Manual trial-and-error PID tuning as a baseline
Identifying process gain, dead time, and time constant from an open-loop step test
Calculating and comparing tuning parameters using multiple methods:

Heuristic
Ziegler-Nichols
Lambda tuning
Ciancone-Marlin
Myke King (P on PV)



Evaluating each method against setpoint changes and load upsets (overshoot, decay ratio, settling time, ITAE)
Effects of measurement noise and filtering on identification and control performance
Verifying identified parameters using the area method (MATLAB) or Excel Solver


Key Takeaway

Formal tuning methods can be directly compared for aggressiveness vs. robustness, and are far more repeatable than manual trial-and-error tuning.

Tool

PC-ControLAB
