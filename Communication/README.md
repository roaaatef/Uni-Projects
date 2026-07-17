MATLAB Superheterodyne Receiver (Analog Communications)

Objective: Simulate a full analog communication system in MATLAB — an AM (DSB-SC) transmitter with FDM, and a super-heterodyne receiver — using real audio signals.

What's Covered


Transmitter: converts stereo audio to mono, matches sampling rates, upsamples to satisfy Nyquist, modulates two signals onto separate carriers (100 kHz & 150 kHz), and combines them via Frequency Division Multiplexing (FDM)
Receiver chain:

RF stage — band-pass filters the FDM signal to isolate the user-selected channel
Mixer stage — down-converts the selected signal to an intermediate frequency (IF = 25 kHz) using a local oscillator
IF stage — band-pass filters around the IF to remove unwanted components
Baseband stage — mixes down to baseband, low-pass filters, and downsamples to recover the original audio



Noise analysis — injecting AWGN (SNR = 2 dB) after the RF stage and tracing its effect through every downstream stage
RF stage removal — demonstrating signal degradation/interference when the RF filtering stage is skipped
Receiver oscillator offset — testing 0.2 kHz and 1.2 kHz local-oscillator frequency errors and their effect on the recovered spectrum and audio quality


Key Takeaway

Each receiver stage (RF, Mixer, IF, Baseband) plays a distinct role in isolating, down-converting, and cleanly recovering one channel out of a multiplexed signal — and removing any one stage, adding noise, or mistuning the local oscillator measurably degrades the recovered audio.

Tools

MATLAB (designfilt, fft/fftshift, resample, interp/downsample, awgn, sound)
