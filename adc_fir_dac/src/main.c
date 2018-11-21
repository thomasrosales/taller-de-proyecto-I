#include "sapi.h"
#include "lowpass.h"
#include "bandpass1.h"
#include "bandpass2.h"
#include "bandpass3.h"
#include "bandpass4.h"
#include "bandpass5.h"
#include "bandpass6.h"
#include "bandpass7.h"
#include "fir_q31.h"
//#include "MAX7219.h"

#define USAR_FUNCIONES_ASSEMBLER	0

#define samples 200

fir_q31_t filtro_flp;
fir_q31_t filtro_fbp_b1;
fir_q31_t filtro_fbp_b2;
fir_q31_t filtro_fbp_b3;
fir_q31_t filtro_fbp_b4;
fir_q31_t filtro_fbp_b5;
fir_q31_t filtro_fbp_b6;
fir_q31_t filtro_fbp_b7;

int history[samples];
int historyBanda0[samples];
int historyBanda1[samples];
int historyBanda2[samples];
int historyBanda3[samples];
int historyBanda4[samples];
int historyBanda5[samples];
int historyBanda6[samples];
int historyBanda7[samples];

int buffer_1[samples] = { 0, 0, -3265, 3265, -3265, 0, 0, 0, /* 0-7 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 8-15 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 16-23 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 24-31 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 32-39 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 40-47 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 48-55 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 56-63 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 64-71 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 72-79 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 80-87 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 88-95 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 96-103 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 104-111 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 112-119 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 120-127 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 128-135 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 136-143 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 144-151 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 152-159 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 160-167 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 168-175 */
-3265, 3265, -3265, 0, 0, 0, -3265, 3265, /* 176-183 */
-3265, 0, 0, 0, -3265, 3265, -3265, 0, /* 184-191 */
0, 0, -3265, 3265, -3265, 0, 0, 0, /* 192-199 */
-3265 };

static void initHardware(void) {
#if defined (__USE_LPCOPEN)
#if !defined(NO_BOARD_LIB)
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
	// Set up and initialize all required blocks and
	// functions related to the board hardware

	//Board_Init();

	boardConfig();

	MAX7219_init();

#if(USAR_FUNCIONES_ASSEMBLER)
	asm_fir_q31_put(&filtro_flp, y);
#else
	//unsigned int k;
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

static void vumeter(uint8_t row, double value) {
	uint8_t data = 0b00000000;
	if (value >= 100) {
		data = 0b11111111;
	} else {
		if (value < 100 && value >= 90) {
			data = 0b00111111;
		} else {
			if (value < 90 && value >= 80) {
				data = 0b01111111;
			} else {
				if (value < 80 && value >= 60) {
					data = 0b00111111;
				} else {
					if (value < 60 && value >= 50) {
						data = 0b00011111;
					} else {
						if (value < 50 && value >= 40) {
							data = 0b00001111;
						} else {
							if (value < 40 && value >= 30) {
								data = 0b00000111;
							} else {
								if (value < 30 && value >= 10) {
									data = 0b00000011;
								} else {
									if (value < 10 && value >= 0) {
										data = 0b00000001;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	MAX7219_write_row(row, data);
}

int main(void) {

	int i = 0;
	unsigned int k;

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
	fir_q31_init(&filtro_fbp_b2, historyBanda2, bandpass_taps_2,
	BANDPASS_TAP_NUM_2);

	/**
	 * Banda correspondiente a 600 Hz a 1200 Hz
	 */
	fir_q31_init(&filtro_fbp_b3, historyBanda3, bandpass_taps_3,
	BANDPASS_TAP_NUM_3);

	/**
	 * Banda correspondiente a 1200 Hz a 2400 Hz
	 */
	fir_q31_init(&filtro_fbp_b4, historyBanda4, bandpass_taps_4,
	BANDPASS_TAP_NUM_4);

	/**
	 * Banda correspondiente a 2400 Hz a 5000 Hz
	 */
	fir_q31_init(&filtro_fbp_b5, historyBanda5, bandpass_taps_5,
	BANDPASS_TAP_NUM_5);

	/**
	 * Banda correspondiente a 5000 Hz a 10000 Hz
	 */
	fir_q31_init(&filtro_fbp_b6, historyBanda6, bandpass_taps_6,
	BANDPASS_TAP_NUM_6);

	/**
	 * Banda correspondiente a 10000 Hz a 14000 Hz
	 */
	fir_q31_init(&filtro_fbp_b7, historyBanda7, bandpass_taps_7,
	BANDPASS_TAP_NUM_7);

	//unsigned char k;
	for (k = 0; k < samples; k++) {
		history[k] = buffer_1[k];
		//fir_q31_put(&filtro_flp, buffer_1[k]);
	}

	float r[samples];

	for (k = 0; k < samples; k++) {
		r[k] = 0;
	}

	initHardware();

	unsigned int one_time = 1;
	unsigned int two_time = 0;
	unsigned int three_time = 0;
	unsigned int four_time = 0;
	unsigned int five_time = 0;
	unsigned int six_time = 0;
	unsigned int seven_time = 0;
	unsigned int eigth_time = 0;
	unsigned int finally = 0;

	while (1) {
		if (one_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_flp);
#else
			r[i] = fir_q31_get(&filtro_flp);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 0;
				vumeter(row, pot_db);

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
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 1;
				vumeter(row, pot_db);

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
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 2;
				vumeter(row, pot_db);

				three_time = 0;
				four_time = 1;
			}
		}

		if (four_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b3);
#else
			r[i] = fir_q31_get(&filtro_fbp_b3);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 3;
				vumeter(row, pot_db);

				four_time = 0;
				five_time = 1;
			}
		}

		if (five_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b4);
#else
			r[i] = fir_q31_get(&filtro_fbp_b4);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 4;
				vumeter(row, pot_db);

				five_time = 0;
				six_time = 1;
			}
		}

		if (six_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b5);
#else
			r[i] = fir_q31_get(&filtro_fbp_b5);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 5;
				vumeter(row, pot_db);

				six_time = 0;
				seven_time = 1;
			}
		}

		if (seven_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b6);
#else
			r[i] = fir_q31_get(&filtro_fbp_b6);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 6;
				vumeter(row, pot_db);

				seven_time = 0;
				eigth_time = 1;
			}
		}

		if (eigth_time) {

#if(USAR_FUNCIONES_ASSEMBLER)
			r[i] = asm_fir_q31_get(&filtro_fbp_b7);
#else
			r[i] = fir_q31_get(&filtro_fbp_b7);
#endif
			i++;
			if (i == samples) {
				i = 0;
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < samples; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / samples;

				double pot_db = 10 * log(10, pot) / 10;

				//unsigned char row, double value
				uint8_t row = 7;
				vumeter(row, pot_db);

				eigth_time = 0;
				finally = 1;
			}
		}

		if (finally) {
			finally = 1;
		}

	}
}
