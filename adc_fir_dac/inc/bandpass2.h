/*
 * bandpass1.h
 *
 *  Created on: Sep 7, 2013
 *      Author: Pablo
 */

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 32000 Hz

fixed point precision: 31 bits

* 0 Hz - 150 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

* 300 Hz - 600 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 750 Hz - 16000 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

*/

#ifndef BANDPASS2_H_
#define BANDPASS2_H_

//num taps 141
#define BANDPASS_TAP_NUM_2 200
extern const int bandpass_taps_2[BANDPASS_TAP_NUM_2];

#endif /* BANDPASS_H_ */
