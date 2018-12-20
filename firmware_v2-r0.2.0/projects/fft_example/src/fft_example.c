
#include "sapi.h"
#include "arm_math.h"


#define TEST_LENGTH_SAMPLES 2048
/* -------------------------------------------------------------------
* External Input and Output buffer Declarations for FFT Bin Example
* ------------------------------------------------------------------- */

extern float32_t testInput_f32_10khz[TEST_LENGTH_SAMPLES];
float32_t testOutput[TEST_LENGTH_SAMPLES/2];
/* ------------------------------------------------------------------
* Global variables for FFT Bin Example
* ------------------------------------------------------------------- */
uint16_t fftSize = 1024;
uint8_t ifftFlag = 0;

/* ----------------------------------------------------------------------
* Max magnitude FFT Bin test
* ------------------------------------------------------------------- */
int main(void)
{
	boardConfig();

  arm_rfft_fast_instance_f32 s;

  arm_rfft_fast_init_f32(&s, fftSize);
  arm_rfft_fast_f32(&s, testInput_f32_10khz, testOutput, ifftFlag);
  while (1);                             /* main function does not return */
}
