/*
 * adc.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Pablo
 */

#ifndef ADC_H_
#define ADC_H_

#include "board.h"

extern int adcFlag;
uint16_t ADC_get_data();
void adcInit(void);


#endif /* ADC_H_ */
