# Decoding-ppm-message
Decoding of a message with PPM using algorithms in the C language, MC STM32G474RE

1. Signal generation with PPM occurs using a model in the Simulink environment. The model was taken from the link:https://github.com/Smsmadly/Pulse-width-modulation-and-Pulse-position-modulation
2. After generation, the signal in the form of an array was initialized in the COM port console application. In the same application, Hamming coding was implemented.
3. The transfer takes place using the COM port and FTDI
4. The message was received in the decoding.uvproj file in the Keil uVision development environment. Hamming decoding and decoding of the PPM signal to PWM using Systick are also implemented here.
5. A digital filter was used to smooth out the ripples. The generation took place in WinFilter. The Butterworth LPF is of the 3rd order.
6. A built-in 12-bit DAC was used to convert the PWM signal
