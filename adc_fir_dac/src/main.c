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

/**
 * Variable gloabl extern desde fir_q31
 */
float history[samples];

float historyBand[samples];

/**
 * Buffer de muestras con resolucion 10 bits.
 * http://electronicaestudiofacil.blogspot.com/2014/12/adc-dac-pic16f877.html
 */
float buffer_1[samples] = { 0.000000, 0.078459, 0.156434, 0.233445, 0.309017,
		0.382683, 0.453990, 0.522499, 0.587785, 0.649448, 0.707107, 0.760406,
		0.809017, 0.852640, 0.891007, 0.923880, 0.951057, 0.972370, 0.987688,
		0.996917, 1.000000, 0.996917, 0.987688, 0.972370, 0.951057, 0.923880,
		0.891007, 0.852640, 0.809017, 0.760406, 0.707107, 0.649448, 0.587785,
		0.522499, 0.453990, 0.382683, 0.309017, 0.233445, 0.156434, 0.078459,
		0.000000, -0.078459, -0.156434, -0.233445, -0.309017, -0.382683,
		-0.453990, -0.522499, -0.587785, -0.649448, -0.707107, -0.760406,
		-0.809017, -0.852640, -0.891007, -0.923880, -0.951057, -0.972370,
		-0.987688, -0.996917, -1.000000, -0.996917, -0.987688, -0.972370,
		-0.951057, -0.923880, -0.891007, -0.852640, -0.809017, -0.760406,
		-0.707107, -0.649448, -0.587785, -0.522499, -0.453990, -0.382683,
		-0.309017, -0.233445, -0.156434, -0.078459, -0.000000, 0.078459,
		0.156434, 0.233445, 0.309017, 0.382683, 0.453990, 0.522499, 0.587785,
		0.649448, 0.707107, 0.760406, 0.809017, 0.852640, 0.891007, 0.923880,
		0.951057, 0.972370, 0.987688, 0.996917, 1.000000, 0.996917, 0.987688,
		0.972370, 0.951057, 0.923880, 0.891007, 0.852640, 0.809017, 0.760406,
		0.707107, 0.649448, 0.587785, 0.522499, 0.453990, 0.382683, 0.309017,
		0.233445, 0.156434, 0.078459, 0.000000, -0.078459, -0.156434, -0.233445,
		-0.309017, -0.382683, -0.453990, -0.522499, -0.587785, -0.649448,
		-0.707107, -0.760406, -0.809017, -0.852640, -0.891007, -0.923880,
		-0.951057, -0.972370, -0.987688, -0.996917, -1.000000, -0.996917,
		-0.987688, -0.972370, -0.951057, -0.923880, -0.891007, -0.852640,
		-0.809017, -0.760406, -0.707107, -0.649448, -0.587785, -0.522499,
		-0.453990, -0.382683, -0.309017, -0.233445, -0.156434, -0.078459,
		-0.000000, 0.078459, 0.156434, 0.233445, 0.309017, 0.382683, 0.453990,
		0.522499, 0.587785, 0.649448, 0.707107, 0.760406, 0.809017, 0.852640,
		0.891007, 0.923880, 0.951057, 0.972370, 0.987688, 0.996917, 1.000000,
		0.996917, 0.987688, 0.972370, 0.951057, 0.923880, 0.891007, 0.852640,
		0.809017, 0.760406, 0.707107, 0.649448, 0.587785, 0.522499, 0.453990,
		0.382683, 0.309017, 0.233445, 0.156434, 0.078459 };

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
	//nothing
#endif

#endif
#endif

}

/**
 * @param hist puntero al buffer de muestas
 * @param buff puntero al buffer con las muestras de ejemplo
 */
static void load_history(float * hist, float * buff) {
	unsigned char k = 0;
	for (k = 0; k < samples; k++) {
		hist[k] = buff[k];
	}
}

static float p(float x, int i) {
	float r = 1.0;
	for (i; i > 0; i--)
		r *= x;
	return r;
}

/**
 * @param b base del logaritmo
 * @param n varible a aplicarle el logatirmo
 * @return logaritmo en base b de n
 */
static float log(int b, float n) {
	float val = 0;
	int i, accurate = 10, reps = 0;
	while (n != 1 && accurate >= 0) {
		for (i = 0; n >= b; i++)
			n /= b;
		n = p(n, 10);
		val = 10 * (val + i);
		accurate--;
		reps++;
	}
	return (float) val / p(10, reps);
}

/**
 * @param row fila
 * @param value valor de potencia
 */
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
								if (value < 30 && value >= 20) {
									data = 0b00000011;
								} else {
									if (value < 20 && value >= 10) {
										data = 0b00000001;
									} else {
										data = 0b00000000;
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

	fir_q31_init(&filtro_flp, historyBand, lowpass_taps, LOWPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 160 Hz a 300 Hz
	 */
	fir_q31_init(&filtro_fbp_b1, historyBand, bandpass_taps,
	BANDPASS_TAP_NUM);

	/**
	 * Banda correspondiente a 300 Hz a 600 Hz
	 */
	fir_q31_init(&filtro_fbp_b2, historyBand, bandpass_taps_2,
	BANDPASS_TAP_NUM_2);

	/**
	 * Banda correspondiente a 600 Hz a 1200 Hz
	 */
	fir_q31_init(&filtro_fbp_b3, historyBand, bandpass_taps_3,
	BANDPASS_TAP_NUM_3);

	/**
	 * Banda correspondiente a 1200 Hz a 2400 Hz
	 */
	fir_q31_init(&filtro_fbp_b4, historyBand, bandpass_taps_4,
	BANDPASS_TAP_NUM_4);

	/**
	 * Banda correspondiente a 2400 Hz a 5000 Hz
	 */
	fir_q31_init(&filtro_fbp_b5, historyBand, bandpass_taps_5,
	BANDPASS_TAP_NUM_5);

	/**
	 * Banda correspondiente a 5000 Hz a 10000 Hz
	 */
	fir_q31_init(&filtro_fbp_b6, historyBand, bandpass_taps_6,
	BANDPASS_TAP_NUM_6);

	/**
	 * Banda correspondiente a 10000 Hz a 14000 Hz
	 */
	fir_q31_init(&filtro_fbp_b7, historyBand, bandpass_taps_7,
	BANDPASS_TAP_NUM_7);

	/**
	 * cargar la variable global externa history
	 * con los datos del buffer
	 */
	load_history(history, buffer_1);

	float r[samples];

	for (k = 0; k < samples; k++) {
		r[k] = 0;
	}

	/**
	 * Inicializacion del hw
	 */
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

				/**
				 * Calculo de potencia
				 */
				float pot = 0;
				int k;
				float ipass;
				for (k = 0; k < LOWPASS_TAP_NUM; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				/**
				 * potencia sobre cantidad de muestras procesadas
				 * LOWPASS_TAP_NUM = cantidad de coeficientes
				 */
				pot = pot / LOWPASS_TAP_NUM;

				/**
				 * Caluclo del logaritmo
				 */
				float pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_2; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_2;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_3; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_3;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_4; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_4;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_5; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_5;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_6; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_6;

				double pot_db = 10 * log(10, pot) / 10;

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
				for (k = 0; k < BANDPASS_TAP_NUM_7; k++) {
					ipass = r[k] * r[k];
					pot += ipass;
				}

				pot = pot / BANDPASS_TAP_NUM_7;

				double pot_db = 10 * log(10, pot) / 10;

				uint8_t row = 7;
				vumeter(row, pot_db);

				eigth_time = 0;
				finally = 1;
			}
		}

		if (finally) {
			MAX7219_write_row(0, 0b00000000);
			MAX7219_write_row(1, 0b00000000);
			MAX7219_write_row(2, 0b00000000);
			MAX7219_write_row(3, 0b00000000);
			MAX7219_write_row(4, 0b00000000);
			MAX7219_write_row(5, 0b00000000);
			MAX7219_write_row(6, 0b00000000);
			MAX7219_write_row(7, 0b00000000);
			one_time = 1;
			finally = 0;
		}

	}
}
