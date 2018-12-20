#include "sapi.h"                // <= sAPI header
#include "KEYPAD.h"
   /* Configuracion de pines para el Teclado Matricial*/

   // Teclado
   static keypad_t keypad;
   // Filas --> Salidas
   static uint8_t keypadRowPins1[4] = {
      RS232_TXD, // Row 0
      CAN_RD,    // Row 1
      CAN_TD,    // Row 2
      T_COL1     // Row 3
   };

   // Columnas --> Entradas con pull-up (MODO = GPIO_INPUT_PULLUP)
   static uint8_t keypadColPins1[4] = {
      T_FIL0,    // Column 0
      T_FIL3,    // Column 1
      T_FIL2,    // Column 2
      T_COL0     // Column 3
   };
   static char teclado[] = {
   		'1', '2', '3','A',
   		'4', '5', '6','B',
   		'7', '8', '9','C',
   		'*', '0', '#','D'
   };

   static uint16_t tecla=0;
   static unsigned char key='\0';

   void KEYPAD_init(){
      keypadConfig( &keypad, keypadRowPins1, 4, keypadColPins1, 4 );
   }

   unsigned char KEYPAD_get_key(){

	   return key;

   }
   void KEYPAD_update(){

	   if (keypadRead(&keypad, &tecla))
		   key=teclado[tecla];

   }


