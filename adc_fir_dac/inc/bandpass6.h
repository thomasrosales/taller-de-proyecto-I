/*
 * bandpass6.h
 *
 *  Created on: 20/11/2018
 *      Author: Tomás
 */

/*

 FIR filter designed with
 http://t-filter.appspot.com

 sampling frequency: 32000 Hz

 fixed point precision: 31 bits

 * 0 Hz - 4000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 * 5000 Hz - 10000 Hz
 gain = 1
 desired ripple = 5 dB
 actual ripple = n/a

 * 11000 Hz - 16000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 */
#ifndef BANDPASS6_H_
#define BANDPASS6_H_


//num taps 23
#define BANDPASS_TAP_NUM_6 200
extern const int bandpass_taps_6[BANDPASS_TAP_NUM_6];

#endif /* BANDPASS6_H_ */
