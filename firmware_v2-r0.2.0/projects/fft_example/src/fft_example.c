
#include "sapi.h"
#include "arm_math.h"


#define TEST_LENGTH_SAMPLES 128
/* -------------------------------------------------------------------
* External Input and Output buffer Declarations for FFT Bin Example
* ------------------------------------------------------------------- */

extern float32_t testInput[TEST_LENGTH_SAMPLES];
static float32_t testOutput[TEST_LENGTH_SAMPLES];
static float32_t modulo[(TEST_LENGTH_SAMPLES/2)+1];
/* ------------------------------------------------------------------
* Global variables for FFT Bin Example
* ------------------------------------------------------------------- */
uint16_t fftSize = 128;
uint8_t ifftFlag = 0;

/* ----------------------------------------------------------------------
* Max magnitude FFT Bin test
* ------------------------------------------------------------------- */
int main(void)
{

  boardConfig();

  arm_rfft_fast_instance_f32 s;
  float32_t potencia_tiempo=0, potencia_frecuencia=0;

  //calculo de potencia en el dominio del tiempo
  arm_power_f32(testInput, TEST_LENGTH_SAMPLES, &potencia_tiempo);
  potencia_tiempo=potencia_tiempo/TEST_LENGTH_SAMPLES;

  //calculo de la fft
  arm_rfft_fast_init_f32(&s, fftSize);
  //devuelve un arreglo de numueros complejos, cada par representa parte real y parte imaginaria
  //el primer par de elementos es real
  //por lo que en realidad se tiene una fft de 65 elementos
  arm_rfft_fast_f32(&s, testInput, testOutput, ifftFlag);

  //se calcula el modulo de la fft
  arm_cmplx_mag_f32(testOutput+2, modulo+1, (TEST_LENGTH_SAMPLES/2)-1);
  //el primer elemento de la fft es real
  modulo[0]=testOutput[0];
  //el segundo elemento tambien es real y representa el elemento N/2 de la fft
  modulo[TEST_LENGTH_SAMPLES/2]=testOutput[1];

  //calculo de la potencia en el dominio de la frecuencia
  arm_power_f32(modulo+1, (TEST_LENGTH_SAMPLES/2)-1, &potencia_frecuencia);
  potencia_frecuencia=(modulo[0]*modulo[0]+modulo[TEST_LENGTH_SAMPLES/2]*modulo[TEST_LENGTH_SAMPLES/2]+2*potencia_frecuencia)/(TEST_LENGTH_SAMPLES*TEST_LENGTH_SAMPLES);
  while (1);                             /* main function does not return */
}
