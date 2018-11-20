#ifndef _MAX7219_H_
#define _MAX7219_H_

/*==================[inclusions]=============================================*/

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

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
