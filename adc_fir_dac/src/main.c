#include "adc.h"
#include "sapi.h"
#include "MAX7219.h"
#include "main.h"
#include "math.h"
#include "fir.h"

#define samples 512

char adcStop = 0;

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

	adcInit();

#endif
#endif

}

/**
 * @param row fila
 * @param value valor de potencia
 */
static void vumeter(uint8_t row, double value) {
	MAX7219_write_row(row, 0b00000000);
	if (value >= 37) {
		MAX7219_write_row(row,
		COL8 | COL7 | COL6 | COL5 | COL4 | COL3 | COL2 | COL1);
	} else {
		if (value < 37 && value >= 35) {
			MAX7219_write_row(row,
			COL8 | COL7 | COL6 | COL5 | COL4 | COL3 | COL2);
		} else {
			if (value < 35 && value >= 34) {
				MAX7219_write_row(row, COL8 | COL7 | COL6 | COL5 | COL4 | COL3);
			} else {
				if (value < 34 && value >= 33) {
					MAX7219_write_row(row, COL8 | COL7 | COL6 | COL5 | COL4);
				} else {
					if (value < 33 && value >= 32) {
						MAX7219_write_row(row, COL8 | COL7 | COL6 | COL5);
					} else {
						if (value < 32 && value >= 31) {
							MAX7219_write_row(row, COL8 | COL7 | COL6);
						} else {
							if (value < 31 && value >= 30) {
								MAX7219_write_row(row, COL8 | COL7);
							} else {
								if (value < 30 && value >= 23) {
									MAX7219_write_row(row, COL8);
								} else {
									MAX7219_write_row(row, 0b00000000);
								}
							}
						}
					}
				}
			}
		}
	}
}

int main(void) {

	unsigned int i = 0;
	int r[samples];

	/*
	 * Inicializacion de los filtros
	 */
	fir_init();

	/**
	 * Inicializacion del hw
	 */
	initHardware();

	char one_time = 1;
	char two_time = 0;
	char three_time = 0;
	char four_time = 0;
	char five_time = 0;
	char six_time = 0;
	char seven_time = 0;
	char eigth_time = 0;

	while (1) {

		if (adcFlag) {

			adcFlag = 0;

			if (one_time) {

				r[i] = fir_q31_get(&filtro_flp);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					if (pot_db > 52.38) {
						pot_db = 33;
					} else {
						if (pot_db < 52.38 && pot_db >= 52.37) {
							pot_db = 32;
						} else {
							if (pot_db < 52.37 && pot_db >= 52.36) {
								pot_db = 31;
							} else {
								if (pot_db < 52.36 && pot_db >= 52.34) {
									pot_db = 30;
								} else {
									if (pot_db < 52.34) {
										pot_db = 25;
									}
								}
							}
						}
					}

					vumeter(ROW8, pot_db);

					one_time = 0;
					two_time = 1;

				}
			}

			if (two_time) {

				r[i] = fir_q31_get(&filtro_fbp_b1);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW7, pot_db);

					two_time = 0;
					three_time = 1;

				}
			}

			if (three_time) {

				r[i] = fir_q31_get(&filtro_fbp_b2);

				i++;
				if (i == samples) {

					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW6, pot_db);

					three_time = 0;
					four_time = 1;

				}
			}

			if (four_time) {

				r[i] = fir_q31_get(&filtro_fbp_b3);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW5, pot_db);

					four_time = 0;
					five_time = 1;

				}
			}

			if (five_time) {

				r[i] = fir_q31_get(&filtro_fbp_b4);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW4, pot_db);

					five_time = 0;
					six_time = 1;

				}
			}

			if (six_time) {

				r[i] = fir_q31_get(&filtro_fbp_b5);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW3, pot_db);

					six_time = 0;
					seven_time = 1;

				}
			}

			if (seven_time) {

				r[i] = fir_q31_get(&filtro_fbp_b6);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					vumeter(ROW2, pot_db);

					seven_time = 0;
					eigth_time = 1;

				}
			}

			if (eigth_time) {

				r[i] = fir_q31_get(&filtro_fbp_b7);

				i++;
				if (i == samples) {
					i = 0;

					double pot_db = potencia(r);

					if (pot_db > 12) {
						pot_db = 33;
					} else {
						if (pot_db < 12 && pot_db >= 11) {
							pot_db = 32;
						} else {
							if (pot_db < 11 && pot_db >= 10) {
								pot_db = 31;
							} else {
								if (pot_db < 10 && pot_db >= 9.6) {
									pot_db = 30;
								} else {
									if (pot_db < 9.6) {
										pot_db = 25;
									}
								}
							}
						}
					}

					vumeter(ROW1, pot_db);

					adcStop = 1;
					eigth_time = 0;
					one_time = 1;

				}
			}

		}

	}
}
