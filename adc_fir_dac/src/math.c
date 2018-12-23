/*
 * math.c
 *
 *  Created on: 23/12/2018
 *      Author: Tomás
 */

#include "math.h"


#define samples 512

/**
 * Eleva numeros a exponente entero
 * @param x valor
 * @param i exponente
 */
double p(double x, int i) {
	double r = 1.0;
	for (i; i > 0; i--)
		r *= x;
	return r;
}

/**
 * @param b base del logaritmo
 * @param n varible a aplicarle el logatirmo
 * @return logaritmo en base b de n
 */
double log(int b, double n) {
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

double potencia(int * r) {
	/**
	 * Calculo de potencia
	 */
	long long pot = 0;
	int ipass;
	int k;
	for (k = 0; k < samples; k++) {
		ipass = r[k] * r[k];
		pot += ipass;
	}

	/**
	 * potencia sobre cantidad de muestras procesadas
	 * LOWPASS_TAP_NUM = cantidad de coeficientes
	 */
	pot = pot / samples;

	/**
	 * Caluclo del logaritmo
	 */
	return (double) 10 * log(10, pot);
}


