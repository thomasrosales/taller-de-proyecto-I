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
#include "DSP.h"
#include "arm_math.h"
#include "mef.h"
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

//int32_t mef_count=0;
/* FUNCION que se ejecuta cada vez que ocurre un Tick. */
/*
 void myTickHook( void *ptr ){
	DSP_update();
	if (++mef_count==32){
		MEF_update();
		mef_count=0;
	}

}
*/





/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){
   /* ------------- INICIALIZACIONES ------------- */
   /* Inicializar la placa */
   boardConfig();
   KEYPAD_init();
   MAX7219_init();
   DSP_init();
   MEF_init();
   adc_Init();

   /* Inicializar el conteo de Ticks con resolucion de 50ms (se ejecuta
      periodicamente una interrupcion cada 1 ms que incrementa un contador de
      Ticks obteniendose una base de tiempos). */
   //tickConfig( 2 );

   /* Se agrega ademas un "tick hook" nombrado myTickHook. El tick hook es
      simplemente una funcion que se ejecutara peri�odicamente con cada
      interrupcion de Tick, este nombre se refiere a una funcion "enganchada"
      a una interrupcion.
   */
   //tickCallbackSet( myTickHook, NULL);


   while(1) {
	   DSP_update();
	   MEF_update();
	   KEYPAD_update();
   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/
