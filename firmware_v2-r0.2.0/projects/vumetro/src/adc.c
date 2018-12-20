

#include "board.h"

int adcFlag=0;

#ifdef lpc4337_m4
#define LPC_ADC LPC_ADC0
#define ADC_IRQn ADC0_IRQn
#endif

uint16_t data;

/* P0.23 -> AD0 */
void adcInit(void)
{
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
	adcFlag=1;
}

uint16_t ADC_get_data(){
	return data;
}
