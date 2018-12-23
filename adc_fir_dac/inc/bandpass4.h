/*
 * bandpass4.h
 *
 *  Created on: 20/11/2018
 *      Author: Tomás
 */
/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 32000 Hz

fixed point precision: 31 bits

* 0 Hz - 1000 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

* 1200 Hz - 2400 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 2600 Hz - 16000 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

*/
#ifndef BANDPASS4_H_
#define BANDPASS4_H_

//num taps 89
#define BANDPASS_TAP_NUM_4 89
extern const int bandpass_taps_4[BANDPASS_TAP_NUM_4];

#endif /* BANDPASS4_H_ */
