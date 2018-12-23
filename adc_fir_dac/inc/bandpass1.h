/*
 * bandpass.h
 *
 *  Created on: Sep 7, 2013
 *      Author: Pablo
 */
/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 32000 Hz

fixed point precision: 31 bits

* 0 Hz - 60 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

* 160 Hz - 300 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 500 Hz - 16000 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

*/
#ifndef BANDPASS_H_
#define BANDPASS_H_

//num taps 153
#define BANDPASS_TAP_NUM 153
extern const int bandpass_taps[BANDPASS_TAP_NUM];

#endif /* BANDPASS_H_ */
