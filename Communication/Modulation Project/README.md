Digital Communications Modulation Project

Objective: Simulate single-carrier digital communication systems at baseband and evaluate their Bit Error Rate (BER) performance over an AWGN channel.

What's Covered


System model: Mapper → AWGN Channel → Demapper → BER Calculator (baseband equivalent, no carriers)
Modulation schemes: BPSK, QPSK, 8PSK, BFSK, and 16-QAM
AWGN channel: noise generated using MATLAB's randn
BER vs. Eb/No curves for all 4 PSK/QAM schemes, each plotted against its theoretical BER (or a tight upper bound), with commentary on the results
Constellation mapping comparison: BER vs. Eb/No for QPSK with two different bit-to-symbol mappings (standard vs. alternate constellation), comparing performance
BFSK analysis:

Deriving the signal set's basis functions
Writing the baseband-equivalent signal expression and carrier frequency used (f_i = (n_c + i)/T_b)
Simulating BER vs. Eb/No against the theoretical BFSK curve
Simulating the Power Spectral Density (PSD) of the signal set from its baseband equivalent

Key Takeaway

Different modulation schemes trade off bit-error performance, spectral characteristics, and complexity — simulated BER curves closely track theoretical bounds, while bit-to-symbol mapping choice (e.g., Gray vs. non-Gray coding) measurably affects error performance even for the same constellation.

Tools

MATLAB
