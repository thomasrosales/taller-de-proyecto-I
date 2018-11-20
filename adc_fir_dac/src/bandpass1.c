/*
 * bandpass.c
 *
 *  Created on: Sep 7, 2013
 *      Author: Pablo
 */

#include "bandpass1.h"

const int bandpass_taps[BANDPASS_TAP_NUM] = { 12091456, -43458659, -15744112,
		-9100606, -7745566, -7713896, -8011340, -8383002, -8761808, -9134514,
		-9494122, -9832997, -10153456, -10451936, -10722563, -10968394,
		-11185526, -11370144, -11526682, -11644095, -11727953, -11773245,
		-11781839, -11744201, -11666299, -11540261, -11372117, -11172653,
		-10932654, -10656078, -10323745, -9922606, -9473975, -9000692, -8504602,
		-7961642, -7348209, -6699505, -6056338, -5364178, -4589183, -3830899,
		-3056147, -2174865, -1370872, -459000, 417891, 1335358, 2257434,
		3192447, 4129180, 5070394, 6012444, 6949802, 7879385, 8793138, 9690101,
		10573043, 11436044, 12276252, 13089796, 13866017, 14609565, 15312989,
		15986240, 16604891, 17191278, 17708709, 18194009, 18629769, 19001657,
		19326072, 19587199, 19791626, 19946752, 20033729, 20057358, 20033729,
		19946752, 19791626, 19587199, 19326072, 19001657, 18629769, 18194009,
		17708709, 17191278, 16604891, 15986240, 15312989, 14609565, 13866017,
		13089796, 12276252, 11436044, 10573043, 9690101, 8793138, 7879385,
		6949802, 6012444, 5070394, 4129180, 3192447, 2257434, 1335358, 417891,
		-459000, -1370872, -2174865, -3056147, -3830899, -4589183, -5364178,
		-6056338, -6699505, -7348209, -7961642, -8504602, -9000692, -9473975,
		-9922606, -10323745, -10656078, -10932654, -11172653, -11372117,
		-11540261, -11666299, -11744201, -11781839, -11773245, -11727953,
		-11644095, -11526682, -11370144, -11185526, -10968394, -10722563,
		-10451936, -10153456, -9832997, -9494122, -9134514, -8761808, -8383002,
		-8011340, -7713896, -7745566, -9100606, -15744112, -43458659, 12091456 };
