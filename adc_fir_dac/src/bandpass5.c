/*
 * bandpass5.c
 *
 *  Created on: 20/11/2018
 *      Author: Tom�s
 */

/*

 FIR filter designed with
 http://t-filter.appspot.com

 sampling frequency: 32000 Hz

 fixed point precision: 31 bits

 * 0 Hz - 2000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 * 2400 Hz - 5000 Hz
 gain = 1
 desired ripple = 5 dB
 actual ripple = n/a

 * 5400 Hz - 16000 Hz
 gain = 0
 desired attenuation = -20 dB
 actual attenuation = n/a

 */

#include "bandpass5.h"

const int bandpass_taps_5[BANDPASS_TAP_NUM_5] = { 34743088, -22414370, -772233,
		16564418, 21411925, 7701466, -21043916, -49060695, -56742099, -35691784,
		2238819, 32083239, 35409614, 16206468, -1757161, 4161051, 31827605,
		51832308, 30070560, -39417583, -120224231, -153544639, -101098473,
		20967873, 145936501, 198486070, 145936501, 20967873, -101098473,
		-153544639, -120224231, -39417583, 30070560, 51832308, 31827605,
		4161051, -1757161, 16206468, 35409614, 32083239, 2238819, -35691784,
		-56742099, -49060695, -21043916, 7701466, 21411925, 16564418, -772233,
		-22414370, 34743088 };
