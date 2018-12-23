/*
 * bandpass7.h
 *
 *  Created on: 20/11/2018
 *      Author: Tomás
 */
/*

 FIR filter designed with
 http://t-filter.appspot.com

 sampling frequency: 32000 Hz

 fixed point precision: 31 bits

 * 0 Hz - 9000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 * 10000 Hz - 14000 Hz
 gain = 1
 desired ripple = 5 dB
 actual ripple = n/a

 * 15000 Hz - 16000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 */
#ifndef BANDPASS7_H_
#define BANDPASS7_H_

//num taps 23
#define BANDPASS_TAP_NUM_7 43
extern const int bandpass_taps_7[BANDPASS_TAP_NUM_7];

#endif /* BANDPASS7_H_ */
