/*
 * fir.c
 *
 *  Created on: 23/12/2018
 *      Author: Tomás
 */

#define samples 512


#include "fir.h"
#include "fir_q31.h"
#include "lowpass.h"
#include "bandpass1.h"
#include "bandpass2.h"
#include "bandpass3.h"
#include "bandpass4.h"
#include "bandpass5.h"
#include "bandpass6.h"
#include "bandpass7.h"

fir_q31_t filtro_flp;
fir_q31_t filtro_fbp_b1;
fir_q31_t filtro_fbp_b2;
fir_q31_t filtro_fbp_b3;
fir_q31_t filtro_fbp_b4;
fir_q31_t filtro_fbp_b5;
fir_q31_t filtro_fbp_b6;
fir_q31_t filtro_fbp_b7;

/**
 * Variable global extern desde fir_q31
 */

int history[samples];
int historyBand1[samples];
int historyBand2[samples];
int historyBand3[samples];
int historyBand4[samples];
int historyBand5[samples];
int historyBand6[samples];
int historyBand7[samples];

void fir_init() {

	/**
	 * @param f es la declaracion del filtro
	 * @param history son las muestras del adc
	 * @param kernel son los coeficientes del filtro
	 * @param num_taps cantidad de coeficientes
	 */

	fir_q31_init(&filtro_flp, history, lowpass_taps, LOWPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 160 Hz a 300 Hz
	 */
	fir_q31_init(&filtro_fbp_b1, historyBand1, bandpass_taps, BANDPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 300 Hz a 600 Hz
	 */
	fir_q31_init(&filtro_fbp_b2, historyBand2, bandpass_taps_2,
	BANDPASS_TAP_NUM_2);

	/**
	 * Banda correspondiente a 600 Hz a 1200 Hz
	 */
	fir_q31_init(&filtro_fbp_b3, historyBand3, bandpass_taps_3,
	BANDPASS_TAP_NUM_3);

	/**
	 * Banda correspondiente a 1200 Hz a 2400 Hz
	 */
	fir_q31_init(&filtro_fbp_b4, historyBand4, bandpass_taps_4,
	BANDPASS_TAP_NUM_4);

	/**
	 * Banda correspondiente a 2400 Hz a 5000 Hz
	 */
	fir_q31_init(&filtro_fbp_b5, historyBand5, bandpass_taps_5,
	BANDPASS_TAP_NUM_5);

	/**
	 * Banda correspondiente a 5000 Hz a 10000 Hz
	 */
	fir_q31_init(&filtro_fbp_b6, historyBand6, bandpass_taps_6,
	BANDPASS_TAP_NUM_6);

	/**
	 * Banda correspondiente a 10000 Hz a 14000 Hz
	 */
	fir_q31_init(&filtro_fbp_b7, historyBand7, bandpass_taps_7,
	BANDPASS_TAP_NUM_7);

}
