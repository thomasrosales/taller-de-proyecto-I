/*
 * adc.c
 *
 *  Created on: Sep 4, 2013
 *      Author: Pablo
 */

#include "board.h"
#include "fir_q31.h"
#include "fir.h"
#include "main.h"

int adcFlag = 0;
uint16_t data;
uint32_t cont = 0;

#ifdef lpc4337_m4
#define LPC_ADC LPC_ADC0
#define ADC_IRQn ADC0_IRQn
#endif

/* P0.23 -> AD0 */
void adcInit(void) {
	ADC_CLOCK_SETUP_T adc;

	Chip_ADC_Init(LPC_ADC, &adc);
	Chip_ADC_SetSampleRate(LPC_ADC, &adc, 32000);

	Chip_ADC_EnableChannel(LPC_ADC, ADC_CH1, ENABLE);
	Chip_ADC_Int_SetChannelCmd(LPC_ADC, ADC_CH1, ENABLE);
	Chip_ADC_SetBurstCmd(LPC_ADC, ENABLE);

	NVIC_EnableIRQ(ADC_IRQn);
}

#ifdef lpc4337_m4
void ADC0_IRQHandler(void)
#else
void ADC_IRQHandler(void)
#endif
{

	Chip_ADC_ReadValue(LPC_ADC, ADC_CH1, &data);

	if (cont < 512) {

		cont++;

		fir_q31_put(&filtro_flp, data);
		fir_q31_put(&filtro_fbp_b1, data);
		fir_q31_put(&filtro_fbp_b2, data);
		fir_q31_put(&filtro_fbp_b3, data);
		fir_q31_put(&filtro_fbp_b4, data);
		fir_q31_put(&filtro_fbp_b5, data);
		fir_q31_put(&filtro_fbp_b6, data);
		fir_q31_put(&filtro_fbp_b7, data);

	} else {
		if (adcStop) {
			cont = 0;
		}
		adcFlag = 1;
	}

}
