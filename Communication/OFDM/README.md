What's Covered

1. DFT vs. FFT Execution Time


Custom MATLAB implementation of the DFT formula
Timing comparison (tic/toc) against MATLAB's built-in FFT() on a random 4096-length test signal
Conclusion on which transform is computationally superior


2. BER Performance over Rayleigh Flat Fading Channel


Simulating a BPSK system model with:

Complex Rayleigh-distributed channel gain (h_r + j·h_i)
Complex AWGN noise (n_c + j·n_s)



Full link simulation: bit generation → symbol mapping → channel + noise → channel compensation → correlator/hard-decision decoding → BER calculation
BER vs. Eb/No curves, repeated with a rate-1/5 repetition code for error resilience
Same simulation repeated for QPSK and 16-QAM


3. OFDM System Simulation


Full OFDM chain: Coding (none or rate-1/5 repetition) → Interleaver (32×16 for QPSK, 32×32 for 16-QAM) → Mapper → 256-point IFFT → Channel → Receiver
Two channel models:

Rayleigh flat fading (same as single-carrier case)
Frequency-selective fading (independent Rayleigh fading per subcarrier, modeled in the frequency domain)



BER vs. SNR plotted for BPSK and 16-QAM, across both channel models, with and without coding (4 cases per modulation scheme)


Key Takeaway

FFT dramatically outperforms a direct DFT implementation in execution time; channel coding (repetition) and modulation choice both significantly affect BER under fading; and OFDM's per-subcarrier structure allows it to handle frequency-selective fading more robustly than a single-carrier system.

Rules


Single MATLAB code file, well-commented
Hard-copy report submission only; AI tools permitted only for report language/grammar, not code
Max 3 students/group; similarity across reports results in a zero grade


Tools

MATLAB
