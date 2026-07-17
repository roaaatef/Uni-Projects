 Source & Channel Coding

Objective: Implement source coding algorithms and evaluate the BER performance of various channel coding and error-correction schemes over an AWGN channel.

What's Covered

Source Coding


Binary Huffman coding for a discrete memoryless source (tested on a 7-symbol source with given probabilities)
Binary Shannon-Fano coding on the same source, for comparison


Channel Coding — BPSK Performance


Uncoded BPSK: simulated probability of error vs. Eb/No (−3 to 10 dB)
Repetition-3 coding with hard-decision decoding, compared at (a) equal energy per transmitted bit and (b) equal energy per information bit
Soft-decision decoding repeated for the Fano-coded case
(7,4) Hamming code: BER performance, minimum distance calculation, and a recommendation on its use for error-rate reduction (bit-energy basis, ignoring transmit time)
(15,11) Hamming code: BER performance and recommendations, including a proposal for keeping transmission time comparable to the uncoded case


Channel Coding — Higher-Order Modulation


Comparing uncoded QPSK vs. 16-QAM with a (255,131) BCH code, at Eb/No = 5–15 dB, transmitting 26.2M bits (with runtime-saving strategies for lower SNR points and linear interpolation for higher ones)


Convolutional Coding


MATLAB implementation of a rate-2/3, constraint-length-K convolutional encoder for 1000 bits, defined by a specified set of generator polynomials


Key Takeaway

Different error-correction strategies (repetition, block codes, BCH, convolutional) trade off coding gain, bandwidth/time efficiency, and complexity differently — this report quantifies those tradeoffs directly through simulated BER curves against theoretical/uncoded baselines.

Rules


MATLAB (or similar) required
Groups of up to 5 students
Staged submission deadlines, with late penalties


Tools

MATLAB (encode/decode, custom Huffman/Fano/convolutional coding functions, provided 16-QAM mod/demod functions)
