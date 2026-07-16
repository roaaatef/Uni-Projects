Lab 25: Modifications to the Textbook PID

Objective: Explore practical PID modifications used in real commercial controllers, beyond the idealized "textbook" algorithm.

What's Covered


Derivative on measurement vs. on error — eliminating the "derivative spike" on setpoint changes
Proportional on measurement vs. on error — eliminating the "proportional kick" for smoother output
Internal derivative filter — reducing noise amplification using derivative gain (K_D)
Setpoint softening — ramping the setpoint to reduce overshoot without retuning
Interacting vs. non-interacting PID forms — showing their mathematical equivalence with correct parameter conversion
Bumpless transfer — avoiding output "bumps" when switching between MAN and AUTO modes


Key Takeaway

Commercial PID controllers include several enhancements over the textbook algorithm to improve smoothness, noise rejection, and safe operator transitions — without sacrificing tuning flexibility.

Tool

PC-ControLAB
