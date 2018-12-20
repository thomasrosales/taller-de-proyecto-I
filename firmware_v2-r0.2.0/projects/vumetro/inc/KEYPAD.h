#ifndef _KEYPAD_H_
#define _KEYPAD_H_

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
 * Configura el teclado matricial
 */
void KEYPAD_init();
/*
 * Retorna la tecla presionada a traves del parametro key
 */
unsigned char  KEYPAD_get_key();

void KEYPAD_update();

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* #ifndef _KEYPAD_H_ */
