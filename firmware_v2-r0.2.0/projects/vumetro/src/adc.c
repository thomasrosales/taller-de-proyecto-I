#include "board.h"
#include "DSP.h"
#include "arm_math.h"

#ifdef lpc4337_m4
#define LPC_ADC LPC_ADC0
#define ADC_IRQn ADC0_IRQn
#endif


uint32_t fs=32000; //frecuencia de muestreo
static flag = 1;
/* P0.23 -> AD0 */
void adc_Init(void)
{
	ADC_CLOCK_SETUP_T adc;

	Chip_ADC_Init(LPC_ADC, &adc);
	Chip_ADC_SetBurstCmd(LPC_ADC, DISABLE);
	Chip_ADC_SetSampleRate(LPC_ADC, &adc, fs);

	Chip_ADC_EnableChannel(LPC_ADC, ADC_CH1, ENABLE);
	Chip_ADC_Int_SetChannelCmd(LPC_ADC, ADC_CH1, ENABLE);


	NVIC_EnableIRQ(ADC_IRQn);
}

#ifdef lpc4337_m4
void ADC0_IRQHandler(void)
#else
void ADC_IRQHandler(void)
#endif
{
	uint16_t sample;
	float32_t data;
	float32_t vcc=3.3;
	Chip_ADC_ReadValue(LPC_ADC, ADC_CH1, &sample);
	/*
	 * almacena la muestra en el buffer
	 */
	//data=(sample*vcc)/1024;
	//DSP_put_sample(data);
	DSP_put_sample(sample);
}


