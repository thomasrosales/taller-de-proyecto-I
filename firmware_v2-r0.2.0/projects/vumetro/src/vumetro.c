/* Copyright 2016, Eric Pernia.
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * Date: 2016-07-28
 */

/*==================[inclusions]=============================================*/

#include "sapi.h"                // <= sAPI header
#include "KEYPAD.h"
#include "MAX7219.h"
#include "adc.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
void myTickHook( void *ptr ){

   KEYPAD_update();
}

unsigned char tecla='0';

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){
	uint8_t rows[8]={ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
   /* ------------- INICIALIZACIONES ------------- */
	//uint16_t muestra = 0;
   /* Inicializar la placa */
   boardConfig();
   KEYPAD_init();
   MAX7219_init();
   int i=0;
   /*adcInit();
   tickConfig( 1 );

   tickCallbackSet( myTickHook, NULL );
	*/
   //MAX7219_displaytest_mode(1);
   while(1) {
	   MAX7219_write_row(ROW1, COL1|COL2);
	   /*for(i=0;i<0xffffff;i++);
	   MAX7219_clear_display();
	   for(i=0;i<0xffffff;i++);
	   /*if (adcFlag) {
		   muestra=ADC_get_data();
	   	   adcFlag=0;
	   }*/
   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
