%% Prepare Signals For The Operation 
% Read the two signals  
 
[signal1, fs1] = audioread('Short_SkyNewsArabia.wav'); % Read first audio file 
[signal2 , fs2] = audioread('Short_QuranPalestine.wav'); % Read second audio file 
 
% Get mono signals 
mono_Signal1 = sum(signal1, 2); % Sum the channels for the first audio 
mono_Signal2 = sum(signal2, 2); % Sum the channels for the second audio 
 
% Match sampling rates and pad signals to equal length 
fs = max(fs1, fs2);  % Use the higher sampling rate 
signal1 = resample(mono_Signal1, fs, fs1); %resampling for signal 1  
signal2 = resample(mono_Signal2, fs, fs2); % resampling for signal 2 
 
% Equalize the lengths of the two signals 
maxLength = max(length(signal1), length(signal2));  
signal1 = [signal1; zeros(maxLength - length(signal1), 1)]; 
signal2 = [signal2; zeros(maxLength - length(signal2), 1)]; 
% Plotting before modulation 
% Plot in time and frequency domain for signal 1 
t = (0:maxLength-1)'/fs; % Time axis for Signal 1 and signal 2 
N1 = length(signal1); 
FFT_Signal1 = fft(signal1); % Compute FFT 
fftShifted1 = fftshift(FFT_Signal1); % Shift zero frequency to the center 
frequencies1 = linspace(-fs/2, fs/2, N1)/1000; % Frequency axis 
figure; 
subplot(2,1,1); 
plot(t, signal1); 
title('Time-Domain Plot of Signal 1 (Before Modulation and UpSampling)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
subplot(2,1,2); 
plot(frequencies1, (abs(fftShifted1)/N1)); 
title('Frequency Spectrum of Signal 1 (before modulation and UpSampling)'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
% Plot in time domain and frequency domain  For Signal 2  
figure; 
subplot(2,1,1); 
plot(t, signal2); 
title('Time-Domain Plot of Signal 2 (Before Modulation and UpSampling)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
 
 
 
 N2 = length(signal2); 
FFT_Signal2 = fft(signal2); 
fftShifted2 = fftshift(FFT_Signal2); 
frequencies2 = linspace(-fs/2, fs/2, N2)/1000; 
 
subplot(2,1,2); 
plot(frequencies2, (abs(fftShifted2)/N2)); 
title('Frequency Spectrum of Signal 2 (before modulation and UpSampling)'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
%% Transmitter Stage  
% Modulating the signals  
F_C = [100e3, 150e3]; % Carrier frequencies for two signals 
 
% Upsampling signals to meet Nyquist criteria 
up_factor = 20;         % Increase sampling frequency by 20x 
signal1_up = interp(signal1, up_factor); 
signal2_up = interp(signal2, up_factor); 
Fs_up = fs * up_factor; 
t_up = (0:length(signal1_up)-1)'/Fs_up; 
 
% Plotting In Time Domain and frequency domain for signal 1 
N1 = length(signal1_up); 
fft_Signal1 = fft(signal1_up); % Compute FFT 
fft_Shifted1 = fftshift(fft_Signal1);% Shift zero frequency to the center 
frequencies1 = linspace(-Fs_up/2, Fs_up/2, N1)/1000; % Frequency axis 
figure; 
subplot(2,1,1); 
plot(t_up, signal1_up); 
title('Upsampled Signal 1 in Time Domain'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
subplot(2,1,2); 
plot(frequencies1, (abs(fft_Shifted1)/N1)); 
title('Frequency Spectrum of UpSampled signal 1'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
% Plotting In Time Domain and frequency domain for signal 2 
N2 = length(signal2_up); 
fft_Signal2 = fft(signal2_up); % Compute FFT 
fft_Shifted2 = fftshift(fft_Signal2);% Shift zero frequency to the center 
frequencies2 = linspace(-Fs_up/2, Fs_up/2, N2)/1000; % Frequency axis 
figure; 
subplot(2,1,1); 
plot(t_up, signal2_up); 
title('Upsampled Signal 2 in Time Domain'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
 subplot(2,1,2); 
plot(frequencies1, (abs(fft_Shifted2)/N2)); 
title('Frequency Spectrum of UpSampled signal 2'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
% Generate carriers 
carrier1 = cos(2 * pi * F_C(1) * t_up); % Carrier for Signal 1 
carrier2 = cos(2 * pi * F_C(2) * t_up); % Carrier for Signal 2 
 
% Modulate signals 
modulatedSignal1 = signal1_up .* carrier1; 
modulatedSignal2 = signal2_up .* carrier2; 
 
% FDM Signal 
FDM_Signal = modulatedSignal1 + modulatedSignal2; 
 
% Plotting the modulated signal 1 
N1 = length(modulatedSignal1); 
FFT_Signal1 = fft(modulatedSignal1); % Compute FFT 
fftShifted1 = fftshift(FFT_Signal1);% Shift zero frequency to the center 
 
frequencies1 = linspace(-Fs_up/2, Fs_up/2, N1)/1000; % Frequency axis 
 
figure; 
subplot(2,1,1); 
plot(t_up, modulatedSignal1); 
title('Modulated Signal 1 (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
subplot(2,1,2); 
plot(frequencies1, (abs(fftShifted1)/N1)); 
title('Frequency Spectrum of Modulated Signal 1'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
% Plotting  Modulated Signal 2 
N2 = length(modulatedSignal2); 
FFT_Signal2 = fft(modulatedSignal2); % Compute FFT 
fftShifted2 = fftshift(FFT_Signal2); % Shift zero frequency to the center 
frequencies2 = linspace(-Fs_up/2, Fs_up/2, N2)/1000; % Frequency axis 
 
figure; 
subplot(2,1,1); 
plot(t_up, modulatedSignal2); 
title('Modulated Signal 2 (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
 
subplot(2,1,2); 
plot(frequencies2, (abs(fftShifted2)/N2)); 
title('Frequency Spectrum of Modulated Signal 2'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
%For FDM 
N_FDM = length(FDM_Signal); 
FFT_FDM = fft(FDM_Signal); % Compute FFT of FDM signal 
fftShifted_FDM = fftshift(FFT_FDM); % Shift zero frequency to the center 
frequencies_FDM = linspace(-Fs_up/2, Fs_up/2, N_FDM)/1000; % Frequency axis 
 
figure; 
subplot(2,1,1); 
plot(t_up, FDM_Signal); 
title('FDM Signal (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
 
subplot(2,1,2); 
plot(frequencies_FDM, (abs(fftShifted_FDM)/N_FDM)); 
title('Frequency Spectrum of FDM Signal'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
%% THE RECEIVER STAGE  
%% 1.RF STAGE  
% Assume FDM_Signal is the received signal at the receiver side 
 
% Carrier Frequencies from the Transmitter 
 
% User chooses which signal to demodulate (Signal 1 or Signal 2) 
signal_choice = input('Enter 1 to demodulate Signal 1, or 2 to demodulate Signal 2: '); 
 
% Select the carrier frequency based on user's choice 
if signal_choice == 1 
    carrier_freq_signal = F_C(1);  % Carrier frequency for Signal 1 
    signal_to_filter = FDM_Signal;  % Signal 1 is part of FDM signal 
elseif signal_choice == 2 
    carrier_freq_signal = F_C(2);  % Carrier frequency for Signal 2 
    signal_to_filter = FDM_Signal;  % Signal 2 is part of FDM signal 
else 
    error('Invalid input! Please enter 1 for Signal 1 or 2 for Signal 2.'); 
end 
% if we removed RF stage we will remove from 1 to 2 and pass FDM signal to the mixer directly 
and we will remove part 3 
% 1 
% Design the Band-Pass Filter (BPF) for the selected signal 
filter_order =8;  % Order of the filter (adjustable) 
bandwidth = 9e3;  % Bandwidth around the carrier (adjustable) 
 
% Design a Band-Pass Filter centered at 'carrier_freq_signal' with the specified bandwidth 
BPF_signal = designfilt('bandpassiir', 'FilterOrder', filter_order, ... 
                        'HalfPowerFrequency1', carrier_freq_signal - bandwidth, ... 
                        'HalfPowerFrequency2', carrier_freq_signal + bandwidth, ... 
                        'SampleRate', Fs_up);  % fs is the sample rate used in the signal 
 
% Apply the Band-Pass Filter to isolate the chosen signal 
filteredSignal = filter(BPF_signal, signal_to_filter);  % Apply BPF to the selected signal 
% 2 
 
 
 %% Adding noise 
 
% Add White Gaussian Noise (AWGN) after the RF Stage 
%SNR = 2;  % Specify the Signal-to-Noise Ratio in dB (adjustable) 
%filteredSignal = awgn(filteredSignal, SNR, 'measured');  % Add noise to the filtered signal 
 
%% Plot The Filtered Signal After RF BPF In Time Domain and Frequency Domain 
% part 3  
figure; 
subplot(2,1,1); 
plot(t_up, filteredSignal); 
title(['Filtered Signal ' num2str(signal_choice) ' After BPF (RF Stage)']); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
 
N = length(filteredSignal);  % Number of samples in filtered signal 
FFT_filteredSignal = fft(filteredSignal);  % Compute FFT of filtered signal 
fftShifted = fftshift(FFT_filteredSignal);  % Shift zero frequency to the center 
frequencies = linspace(-Fs_up/2, Fs_up/2, N)/1000;  % Frequency axis 
 
subplot(2,1,2); 
plot(frequencies, (abs(fftShifted)/N));  % Plot magnitude of FFT (frequency spectrum) 
title(['Frequency Spectrum of Filtered Signal after RF stage ' num2str(signal_choice)]); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
 
%% 2.MIXER STAGE 
 
omega_IF = 25e3;  % Intermediate frequency (IF) 
carrier_freq_signal = F_C(signal_choice);  % Carrier frequency selected based on user's choice 
 
% Calculate the local oscillator frequency omega_c 
omega_c = carrier_freq_signal + omega_IF;  % Local oscillator frequency (carrier + IF) 
 
% Generate the local oscillator signal (cosine wave) 
localOscillator = cos(2 * pi * omega_c *t_up);  % Local oscillator signal at omega_c 
%% Adding offset  
% add 0.2 khz offset 
%localOscillator = cos(2 * pi * (omega_c+200) *t_up);  % Local oscillator signal at 
omega_c+offset 
% add 1.2 khz offset  
% localOscillator = cos(2 * pi * (omega_c+1200) *t_up);  % Local oscillator signal at 
omega_c+offset 
%% Mix the filtered signal with the local oscillator (simple multiplier) 
IF_Signal = filteredSignal .* localOscillator;  % Perform the mixing 
 
% Plotting The Mixed Signal In The Time Domain and frequency domain 
figure; 
subplot(2,1,1); 
plot(t_up, IF_Signal); 
title('IF Signal after the oscillator (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
 N_IF = length(IF_Signal);  % Number of samples in mixed signal 
FFT_IFSignal = fft(IF_Signal);  % Compute FFT of the mixed signal 
fftShifted_IF = fftshift(FFT_IFSignal);  % Shift zero frequency to the center 
frequencies_IF = linspace(-Fs_up/2, Fs_up/2, N_IF)/1000;  % Frequency axis 
 
subplot(2,1,2); 
plot(frequencies_IF, (abs(fftShifted_IF)/N_IF));  % Plot magnitude of FFT (frequency spectrum) 
title('Frequency Spectrum of Mixed Signal after the oscillator of IF stage'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
xlim([-400 400]);  % Set x-axis range to -400 kHz to 400 kHz 
grid on; 
%% 3.IF Stage: Band-Pass Filter (BPF) centered at intermediate frequency (omega_IF) 
filter_order = 6;  % Order of the filter (adjustable) 
 
% Design a Band-Pass Filter centered at omega_IF 
BPF_IF = designfilt('bandpassiir', 'FilterOrder', filter_order, ... 
                     'HalfPowerFrequency1', omega_IF - 9e3, ... % Adjust bandwidth 
                     'HalfPowerFrequency2', omega_IF + 9e3, ... 
                     'SampleRate', Fs_up);  % fs is the sample rate used in the signal 
 
% Apply the Band-Pass Filter to isolate the IF signal 
filtered_IF_Signal = filter(BPF_IF, IF_Signal);  % Apply BPF to the selected signal 
 
% Plot The Time-Domain  and frequency domain Signal  
 
 
figure; 
subplot(2,1,1); 
plot(t_up, filtered_IF_Signal); 
title(['Filtered Signal ' num2str(signal_choice) ' After BPF (IF Stage)']); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
N = length(filtered_IF_Signal);  % Number of samples in filtered signal 
FFT_filtered_IF_Signal = fft(filtered_IF_Signal);  % Compute FFT of filtered signal 
fftShifted_IF = fftshift(FFT_filtered_IF_Signal);  % Shift zero frequency to the center 
frequencies_IF = linspace(-Fs_up/2, Fs_up/2, N)/1000;  % Frequency axis 
 
 
subplot(2,1,2); 
plot(frequencies_IF, (abs(fftShifted_IF)/N));  % Plot magnitude of FFT (frequency spectrum) 
title(['Frequency Spectrum of Filtered Signal ' num2str(signal_choice) ' After BPF in IF 
stage']); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
xlim([-400 400]); 
grid on; 
%% 4. Baseband Detection Stage: Mixing with Local Oscillator and Low-Pass Filtering 
% Mix with a carrier of suitable frequency to bring the signal down to baseband 
 
% Local oscillator frequency (same as carrier frequency for signal 1 or 2) 
omega_LO = omega_IF;  % Local oscillator frequency 
 
% Generate the local oscillator signal (cosine wave) 
localOscillator = cos(2 * pi * omega_LO * t_up);  % Local oscillator signal at omega_LO 
 
 % Mix the filtered signal with the local oscillator (simple multiplier) 
mixedSignal = filtered_IF_Signal .* localOscillator;  % Perform the mixing 
 
% Plotting The Mixed Signal In The Time Domain and frequency domain 
 
figure; 
subplot(2,1,1); 
plot(t_up, mixedSignal); 
title('Mixed Signal after the second oscillator (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
N_mixed = length(mixedSignal);  % Number of samples in mixed signal 
FFT_mixedSignal = fft(mixedSignal);  % Compute FFT of the mixed signal 
fftShifted_mixed = fftshift(FFT_mixedSignal);  % Shift zero frequency to the center 
frequencies_mixed = linspace(-Fs_up/2, Fs_up/2, N_mixed)/1000;  % Frequency axis 
 
subplot(2,1,2); 
plot(frequencies_mixed, (abs(fftShifted_mixed)/N_mixed));  % Plot magnitude of FFT (frequency 
spectrum) 
title('Frequency Spectrum of Mixed Signal after second oscillator'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
% Design the Low-Pass Filter (LPF) for baseband detection 
baseband_cutoff = 9e3;  % Cutoff frequency just above IF to filter out high frequencies 
lpf_order = 8;  % Order of the low-pass filter (adjustable) 
 
% Design the Low-Pass Filter 
LPF_baseband = designfilt('lowpassiir', 'FilterOrder', lpf_order, ... 
                           'HalfPowerFrequency', baseband_cutoff, ... 
                           'SampleRate', Fs_up); 
 
% Apply the Low-Pass Filter to the mixed signal to obtain the baseband signal 
basebandSignal = filter(LPF_baseband, mixedSignal); 
 
% Plot The Time-Domain Baseband Signal and frequency domain 
figure; 
subplot(2,1,1); 
plot(t_up, basebandSignal); 
title('Baseband Signal (Time Domain)'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
N_baseband = length(basebandSignal);  % Number of samples in baseband signal 
FFT_basebandSignal = fft(basebandSignal);  % Compute FFT of the baseband signal 
fftShifted_baseband = fftshift(FFT_basebandSignal);  % Shift zero frequency to the center 
frequencies_baseband = linspace(-Fs_up/2, Fs_up/2, N_baseband)/1000;  % Frequency axis 
 
subplot(2,1,2); 
plot(frequencies_baseband, (abs(fftShifted_baseband)/N_baseband));  % Plot magnitude of FFT 
(frequency spectrum) 
title('Frequency Spectrum of Baseband Signal'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
 
 
 
 
 
 
 
 
 
%% DownSampling 
Down_F = up_factor; % Ratio of original to new sampling frequency 
 
% Anti-Aliasing LPF Design 
AntiAlias_Filter = designfilt('lowpassiir', ... 
                             'FilterOrder', 12, ... 
                             'HalfPowerFrequency', (fs / 2), ... % Nyquist frequency of original 
sampling rate 
                             'SampleRate', Fs_up); 
 
% Downsample Signal  
DownSampledSignal1 = filter(AntiAlias_Filter, basebandSignal); % Apply anti-aliasing LPF 
downsampled_signal = downsample(DownSampledSignal1 , Down_F); 
t_down = (0:length(downsampled_signal)-1)' / Down_F;  % Time vector for the downsampled signal 
 
% Plot the Downsampled Signal in the Time Domain and frequecny domain  
figure; 
subplot(2,1,1); 
plot(t_down, downsampled_signal); 
title('Downsampled Signal in Time Domain'); 
xlabel('Time (s)'); 
ylabel('Amplitude'); 
grid on; 
 
frequencies_ds = linspace(-fs/2, fs/2, length(downsampled_signal))/1000; 
 
subplot(2,1,2); 
plot(frequencies_ds, (abs(fftshift(fft(downsampled_signal)))/length(downsampled_signal))); 
title('Frequency Spectrum of Baseband Signal'); 
xlabel('Frequency (KHz)'); 
ylabel('Magnitude'); 
grid on; 
%% 5. Play Reconstructed Signal 
sound(downsampled_signal / max(abs(downsampled_signal)), fs);