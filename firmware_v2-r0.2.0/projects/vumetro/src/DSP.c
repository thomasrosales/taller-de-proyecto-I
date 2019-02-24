#include "sapi.h"
#include "DSP.h"
#include "arm_math.h"
#include "board.h"

#ifdef lpc4337_m4
#define LPC_ADC LPC_ADC0
#define ADC_IRQn ADC0_IRQn
#endif

#define T_BUFFER 2048
#define FFT_SIZE 2048

static float32_t buffer[T_BUFFER];
static int indice;
static bool_t buffer_lleno;

static float32_t modulo_fft[(T_BUFFER/2)+1];
static float32_t fft_buffer[T_BUFFER];

static float32_t potencia_band1;
static float32_t potencia_band2;
static float32_t potencia_band3;
static float32_t potencia_band4;
static float32_t potencia_band5;
static float32_t potencia_band6;
static float32_t potencia_band7;
static float32_t potencia_band8;


void DSP_init(){
	//el indice del buffer comienza en cero
	indice=0;
	buffer_lleno=0;
	potencia_band1=0;
	potencia_band2=0;
	potencia_band3=0;
	potencia_band4=0;
	potencia_band5=0;
	potencia_band6=0;
	potencia_band7=0;
	potencia_band8=0;

}

void DSP_put_sample(float32_t sample){

	buffer[indice]=sample;
	//Si se lleno el buffer
	if (++indice==T_BUFFER){
		//Reinicio el indice a cero
		indice=0;
		//deshabilito el adc
		Chip_ADC_Int_SetChannelCmd(LPC_ADC, ADC_CH1, DISABLE);
		//indico que el buffer esta lleno
		buffer_lleno=1;
	}
}

void get_potencia_band1(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 1*16=16 hz hasta 10*16=160 hz
	arm_power_f32(modulo_fft+1, 10, &potencia_band1);
	potencia_band1=10*log10(2*potencia_band1/(T_BUFFER*T_BUFFER));
}
/*
 * Calcula la potencia de la banda 1
 * 20 hz a 160 hz
 */
float32_t DSP_get_potencia_band1(){
	return potencia_band1;
};

void get_potencia_band2(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 10*16=160 hz hasta 19*16=304 hz
    arm_power_f32(modulo_fft+10, 10, &potencia_band2);
    potencia_band2=10*log10(2*potencia_band2/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 2
 * 160 hz a 300 hz
 */
float32_t DSP_get_potencia_band2(){
	return potencia_band2;
};

void get_potencia_band3(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 19*16=304 hz hasta 38*16=608 hz
    arm_power_f32(modulo_fft+19, 20, &potencia_band3);
    potencia_band3=10*log10(2*potencia_band3/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 3
 * 300 hz a 600 hz
 */
float32_t DSP_get_potencia_band3(){
	return potencia_band3;
};

void get_potencia_band4(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 38*16=608 hz hasta 75*16=1200 hz
    arm_power_f32(modulo_fft+38, 38, &potencia_band4);
    potencia_band4=10*log10(2*potencia_band4/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 4
 * 600 hz a 1200 hz
 */
float32_t DSP_get_potencia_band4(){
	return potencia_band4;
};

void get_potencia_band5(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 75*16=1200 hz hasta 150*16=2400 hz
    arm_power_f32(modulo_fft+75, 76, &potencia_band5);
    potencia_band5=10*log10(2*potencia_band5/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 5
 * 1200 hz a 2400 hz
 */
float32_t DSP_get_potencia_band5(){
	return potencia_band5;
};

void get_potencia_band6(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 150*16=2400 hz hasta 313*16=5008 hz
    arm_power_f32(modulo_fft+150, 164, &potencia_band6);
    potencia_band6=10*log10(2*potencia_band6/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 6
 * 2400 hz a 5000 hz
 */
float32_t DSP_get_potencia_band6(){
	return potencia_band6;
};

void get_potencia_band7(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 313*16=5008 hz hasta 625*16=10000 hz
    arm_power_f32(modulo_fft+313, 313, &potencia_band7);
    potencia_band7=10*log10(2*potencia_band7/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 7
 * 5000 hz a 10000 hz
 */
float32_t DSP_get_potencia_band7(){
	return potencia_band7;
};

void get_potencia_band8(){
	//la resolucion es de 16 hz
	//se calcula la potencia desde el elemento 625*16=10000 hz hasta 1000*16=16000 hz
    arm_power_f32(modulo_fft+625, 375, &potencia_band8);
    potencia_band8=10*log10(2*potencia_band8/(T_BUFFER*T_BUFFER));
}

/*
 * Calcula la potencia de la banda 8
 * 10000 hz a 16000 hz
 */
float32_t DSP_get_potencia_band8(){
	return potencia_band8;
};

/*
 * Realiza el calculo de la fft de la señal
 * almacenada en el buffer
 */
void fft(){
	//calculo de la fft
	arm_rfft_fast_instance_f32 s;
	arm_rfft_fast_init_f32(&s, FFT_SIZE);
	arm_rfft_fast_f32(&s, buffer, fft_buffer, 0);
	//se calcula el modulo de la fft
	arm_cmplx_mag_f32(fft_buffer+2, modulo_fft+1, (T_BUFFER/2)-1);
	//el primer elemento de la fft es real
	arm_abs_f32(fft_buffer, modulo_fft, 1);
	//el segundo elemento tambien es real y representa el elemento N/2 de la fft
	arm_abs_f32(fft_buffer+1, modulo_fft+T_BUFFER/2, 1);
}
/*
 * si el buffer esta lleno, calcula la fft,
 * calcula la potencia de cada banda
 * y vuelve a activar el adc para que tome nuevas muestras
 */
void DSP_update(){
	if(buffer_lleno){
		fft();
		get_potencia_band1();
		get_potencia_band2();
		get_potencia_band3();
		get_potencia_band4();
		get_potencia_band5();
		get_potencia_band6();
		get_potencia_band7();
		get_potencia_band8();
		//indico que el buffer esta vacio
		buffer_lleno=0;
		//habilito adc
		Chip_ADC_Int_SetChannelCmd(LPC_ADC, ADC_CH1, ENABLE);
	}
};
