#ifndef _MAX7219_H_
#define _MAX7219_H_


/*==================[inclusions]=============================================*/
#include "sapi.h"
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/
#define ROW1 7
#define ROW2 1
#define ROW3 3
#define ROW4 5
#define ROW5 0
#define ROW6 2
#define ROW7 4
#define ROW8 6

#define COL1 (1 << 5)
#define COL2 (1 << 3)
#define COL3 (1 << 7)
#define COL4 (1 << 4)
#define COL5 (1 << 2)
#define COL6 (1 << 0)
#define COL7 (1 << 1)
#define COL8 (1 << 6)
/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
/*
 * Configura el max7219
*/
void MAX7219_init();

/*
 * Configura el modo shutdown
 * 1 -> modo shutdown
 * 0 -> modo normal
*/
void MAX7219_shutdown_mode(bool_t state);
/*
 * Configura el modo displaytest
 * 1 -> modo displaytest
 * 0 -> modo normal
*/
void MAX7219_displaytest_mode(bool_t state);
/*
 * Configura la cantidad de digitos a mostrar
*/
void MAX7219_set_scan_limit(uint8_t cantidad);
/*
 * Escribe la fila pasada como parametro
 * data -> parametro de 8 bits, cada bit representa la columna
 * Ejemplo:
 * Prender columnas 0, 1, 2 de la fila 0
 * MAX7219_write_row(0, 0b00000111)
 * MAX7219_write_row(0, 7)
 * MAXX7219_write_row(0, 0x07)
*/
void MAX7219_write_row(uint8_t row, uint8_t data);
/*
 * Limpia la pantalla de la matriz
*/
void MAX7219_clear_display();
/*
 * Configura la intensidad de la matriz
 * 1 <= intensity <= 16
*/
void MAX7219_set_intensity(uint8_t intensity);

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _MAX7219_H_ */
