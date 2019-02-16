#include "arm_math.h"
/*
 * Inicializa el DSP
 */
void DSP_init();
/*
 * almacena la muestra en el buffer
 */
void DSP_put_sample(float32_t sample);
/*
 * si el buffer esta lleno, calcula la fft
 * y vuelve a activar el adc para que tome nuevas muestras
 */
void DSP_update();

/*
 * Calcula la potencia de la banda 1
 * 20 hz a 160 hz
 */
float32_t DSP_get_potencia_band1();

/*
 * Calcula la potencia de la banda 2
 * 160 hz a 300 hz
 */
float32_t DSP_get_potencia_band2();

/*
 * Calcula la potencia de la banda 3
 * 300 hz a 600 hz
 */
float32_t DSP_get_potencia_band3();
/*
 * Calcula la potencia de la banda 4
 * 600 hz a 1200 hz
 */
float32_t DSP_get_potencia_band4();

/*
 * Calcula la potencia de la banda 5
 * 1200 hz a 2400 hz
 */
float32_t DSP_get_potencia_band5();

/*
 * Calcula la potencia de la banda 6
 * 2400 hz a 5000 hz
 */
float32_t DSP_get_potencia_band6();

/*
 * Calcula la potencia de la banda 7
 * 5000 hz a 10000 hz
 */
float32_t DSP_get_potencia_band7();

/*
 * Calcula la potencia de la banda 8
 * 10000 hz a 16000 hz
 */
float32_t DSP_get_potencia_band8();
