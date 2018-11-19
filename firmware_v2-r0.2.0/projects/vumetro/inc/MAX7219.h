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

void MAX7219_shutdown_mode();

void MAX7219_write_data(uint8_t row, uint8_t data);

void MAX7219_scan_limit(uint8_t cantidad);
/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _MAX7219_H_ */
