#ifndef _VIEW_H_
#define _VIEW_H_

/*==================[inclusions]=============================================*/
#include "sapi.h"
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
/*
 * Limpia la pantalla de la matriz
 */
void VIEW_clear();
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 1 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band1(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 2 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band2(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 3 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band3(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 4 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band4(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 5 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band5(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 6 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band6(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 7 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band7(int);
/*
 * Indica el nivel de volumen en la posicion
 * correspondiente a la banda 8 de la matriz
 * acorde a la potencia pasada como parametro
 */
void VIEW_band8(int);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _MEF_H_ */
