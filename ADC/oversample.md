# Question	
What is oversampling and decimation, where will be used?
Are there any prerequisites to perform oversampling and decimation?
# Answer	
Oversampling and Decimation is commonly used in ADC to improve the resolution. 
This technique requires large number of samples, these extra samples can be achieved by oversampling the input signal. 
Here oversampling refers to sampling the signal by a factor greater than the bare minimum Nyquist rate.
The signal needs to be oversampled four times to achieve every additional bit of resolution. 

Oversampling and decimation feature is effective only when Gaussian noise is present in the input signal. 
The quantization error of ADC is at least 0.5 LSB, so the noise amplitude present in the signal needs to be more than 0.5 LSB to be able to change the ADC result by a single LSB. 
Having noise level more than 0.5 LSB (1-4 LSB) also helps to ensure that several samples do not end up getting the same value.

In case of SAM D/L/C the Gaussian noise is not added by the peripheral, in order for oversampling and decimation feature to be effective the user needs to add an external Gaussian noise source. 
If the signal inherently has Gaussian noise with amplitude higher than 0.5 LSB, then no external noise needs to be added.

Note : Gaussian noise, Thermal noise and White noise are all the same.

The following Application notes provides detailed description about oversampling and decimation

