#include "lowpass.h"
#include "bandpass1.h"
#include "bandpass2.h"
#include "fir_q31.h"

#define USAR_FUNCIONES_ASSEMBLER	0

#define samples 500

fir_q31_t filtro_flp;
fir_q31_t filtro_fbp_b1;
fir_q31_t filtro_fbp_b2;

int historyBanda0[LOWPASS_TAP_NUM];
int historyBanda1[BANDPASS_TAP_NUM];
int historyBanda2[BANDPASS_TAP_NUM_2];

int y[samples] = { 0, 0, -91, 90, -91, 0, 0, 0, /* 0-7 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 8-15 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 16-23 */
0, 0, -91, 90, -91, 0, 0, 0, /* 24-31 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 32-39 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 40-47 */
0, 0, -91, 90, -91, 0, 0, 0, /* 48-55 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 56-63 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 64-71 */
0, 0, -91, 90, -91, 0, 0, 0, /* 72-79 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 80-87 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 88-95 */
0, 0, -91, 90, -91, 0, 0, 0, /* 96-103 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 104-111 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 112-119 */
0, 0, -91, 90, -91, 0, 0, 0, /* 120-127 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 128-135 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 136-143 */
0, 0, -91, 90, -91, 0, 0, 0, /* 144-151 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 152-159 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 160-167 */
0, 0, -91, 90, -91, 0, 0, 0, /* 168-175 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 176-183 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 184-191 */
0, 0, -91, 90, -91, 0, 0, 0, /* 192-199 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 200-207 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 208-215 */
0, 0, -91, 90, -91, 0, 0, 0, /* 216-223 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 224-231 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 232-239 */
0, 0, -91, 90, -91, 0, 0, 0, /* 240-247 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 248-255 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 256-263 */
0, 0, -91, 90, -91, 0, 0, 0, /* 264-271 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 272-279 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 280-287 */
0, 0, -91, 90, -91, 0, 0, 0, /* 288-295 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 296-303 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 304-311 */
0, 0, -91, 90, -91, 0, 0, 0, /* 312-319 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 320-327 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 328-335 */
0, 0, -91, 90, -91, 0, 0, 0, /* 336-343 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 344-351 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 352-359 */
0, 0, -91, 90, -91, 0, 0, 0, /* 360-367 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 368-375 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 376-383 */
0, 0, -91, 90, -91, 0, 0, 0, /* 384-391 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 392-399 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 400-407 */
0, 0, -91, 90, -91, 0, 0, 0, /* 408-415 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 416-423 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 424-431 */
0, 0, -91, 90, -91, 0, 0, 0, /* 432-439 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 440-447 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 448-455 */
0, 0, -91, 90, -91, 0, 0, 0, /* 456-463 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 464-471 */
-91, 0, 0, 0, -91, 90, -91, 0, /* 472-479 */
0, 0, -91, 90, -91, 0, 0, 0, /* 480-487 */
-91, 90, -91, 0, 0, 0, -91, 90, /* 488-495 */
-91, 0, 0, 0, -91 /* 496-500 */};

static void initHardware(void) {
#if defined (__USE_LPCOPEN)
#if !defined(NO_BOARD_LIB)
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();

#if(USAR_FUNCIONES_ASSEMBLER)
	asm_fir_q31_put(&filtro_flp, y);
	asm_fir_q31_put(&filtro_fbp_b1, y);
	asm_fir_q31_put(&filtro_fbp_b2, y);
#else
	fir_q31_put(&filtro_flp, y);
	fir_q31_put(&filtro_fbp_b1, y);
	fir_q31_put(&filtro_fbp_b2, y);
#endif

#endif
#endif

}

static double p(double x, int i) {
	double r = 1.0;
	for (i; i > 0; i--)
		r *= x;
	return r;
}

static double log(int b, double n) {
	double val = 0;
	int i, accurate = 10, reps = 0;
	while (n != 1 && accurate >= 0) {
		for (i = 0; n >= b; i++)
			n /= b;
		n = p(n, 10);
		val = 10 * (val + i);
		accurate--;
		reps++;
	}
	return (double) val / p(10, reps);
}

int main(void) {

	int i = 0;

	/**
	 * @param f es la declaracion del filtro
	 * @param history son las muestras del adc
	 * @param kernel son los coeficientes del filtro
	 * @param num_taps cantidad de coeficientes
	 */
	fir_q31_init(&filtro_flp, historyBanda0, lowpass_taps, LOWPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 160 Hz a 300 Hz
	 */
	fir_q31_init(&filtro_fbp_b1, historyBanda1, bandpass_taps,
	BANDPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 300 Hz a 600 Hz
	 */
	fir_q31_init(&filtro_fbp_b2, historyBanda2, bandpass_taps,
	BANDPASS_TAP_NUM_2);

	long r[samples];

	int k;
	for (k = 0; k < samples; k++) {
		r[k] = 0;
	}

	initHardware();

	unsigned int one_time = 1;
	unsigned int two_time = 0;
	unsigned int three_time = 0;
	unsigned int finally = 0;

	while (1) {
		if (one_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_flp);
#else
			r[i] = fir_q31_get(&filtro_flp);
#endif
			i++;
			if (i == 500) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot);
				one_time = 0;
				two_time = 1;
			}
		}

		if (two_time) {
#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b1);
#else
			r[i] = fir_q31_get(&filtro_fbp_b1);
#endif
			i++;
			if (i == 500) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot);
				two_time = 0;
				three_time = 1;
			}
		}

		if (three_time) {
#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b2);
#else
			r[i] = fir_q31_get(&filtro_fbp_b2);
#endif
			i++;
			if (i == 500) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot);
				three_time = 0;
				finally = 1;
			}
		}

		if (finally) {
			finally = 1;
		}
	}
}
