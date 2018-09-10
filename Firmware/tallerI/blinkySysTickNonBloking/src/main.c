/* Copyright 2014, 2015 Mariano Cerdeiro
 * Copyright 2014, Pablo Ridolfi
 * Copyright 2014, Juan Cecconi
 * Copyright 2014, Gustavo Muro
 * Copyright 2015, Eric Pernia
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
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

/** \brief Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */
/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials    Name
 * ---------------------------
 * ENP          Eric Pernia
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20151104   v0.0.1   ENP   First version
 */

/*==================[inclusions]=============================================*/
#include "main.h"       /* <= own header */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif

/*==================[macros and definitions]=================================*/

#define TEC1_P    1
#define TEC1_P_   0
#define TEC1_GPIO 0
#define TEC1_PIN  4

#define TEC2_P    1
#define TEC2_P_   1
#define TEC2_GPIO 0
#define TEC2_PIN  8

#define TEC3_P    1
#define TEC3_P_   2
#define TEC3_GPIO 0
#define TEC3_PIN  9

#define TEC4_P    1
#define TEC4_P_   6
#define TEC4_GPIO 1
#define TEC4_PIN  9

#define LEDR_P    2
#define LEDR_P_   0
#define LEDR_GPIO 5
#define LEDR_PIN  0

#define LEDG_P    2
#define LEDG_P_   1
#define LEDG_GPIO 5
#define LEDG_PIN  1

#define LEDB_P    2
#define LEDB_P_   2
#define LEDB_GPIO 5
#define LEDB_PIN  2

#define LED1_P    2
#define LED1_P_  10
#define LED1_GPIO 0
#define LED1_PIN 14

#define LED2_P    2
#define LED2_P_  11
#define LED2_GPIO 1
#define LED2_PIN 11

#define LED3_P    2
#define LED3_P_  12
#define LED3_GPIO 1
#define LED3_PIN 12

#define INPUT     0
#define OUTPUT    1

#define ON        1
#define OFF       0

#define TICKRATE_HZ (1000) /* 1000 ticks per second --> 1ms Tick */

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

volatile uint32_t msTicks = 0;
uint32_t ledStatus = OFF;
uint32_t delay_ms = 0;
uint32_t tiempoCumplido = 0;

/*==================[internal functions definition]==========================*/

static void boardButtonsInit(void) {

   /* Config EDU-CIAA-NXP Button Pins as GPIOs */
   Chip_SCU_PinMux(TEC1_P, TEC1_P_, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* P1_0,  GPIO0[4], TEC1 */
   Chip_SCU_PinMux(TEC2_P, TEC2_P_, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* P1_1,  GPIO0[8], TEC2 */
   Chip_SCU_PinMux(TEC3_P, TEC3_P_, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* P1_2,  GPIO0[9], TEC3 */
	Chip_SCU_PinMux(TEC4_P, TEC4_P_, MD_PUP|MD_EZI|MD_ZI, FUNC0); /* P1_6,  GPIO1[9], TEC4 */

   /* Config EDU-CIAA-NXP Button Pins as Inputs */
   Chip_GPIO_SetDir(LPC_GPIO_PORT, TEC1_GPIO, (1<<TEC1_PIN), INPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, TEC2_GPIO, (1<<TEC3_PIN), INPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, TEC2_GPIO, (1<<TEC2_PIN), INPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, TEC4_GPIO, (1<<TEC4_PIN), INPUT);

}

static void boardLedsInit(void) {

   /* Config EDU-CIAA-NXP Led Pins as GPIOs */
   Chip_SCU_PinMux(LEDR_P, LEDR_P_, MD_PUP, FUNC4); /* P2_0,  GPIO5[0],  LEDR */
   Chip_SCU_PinMux(LEDG_P, LEDG_P_, MD_PUP, FUNC4); /* P2_1,  GPIO5[1],  LEDG */
   Chip_SCU_PinMux(LEDB_P, LEDB_P_, MD_PUP, FUNC4); /* P2_2,  GPIO5[2],  LEDB */
   Chip_SCU_PinMux(LED1_P, LED1_P_, MD_PUP, FUNC0); /* P2_10, GPIO0[14], LED1 */
   Chip_SCU_PinMux(LED2_P, LED2_P_, MD_PUP, FUNC0); /* P2_11, GPIO1[11], LED2 */
   Chip_SCU_PinMux(LED3_P, LED3_P_, MD_PUP, FUNC0); /* P2_12, GPIO1[12], LED3 */

   /* Config EDU-CIAA-NXP Led Pins as Outputs */
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LEDR_GPIO, (1<<LEDR_PIN), OUTPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LEDG_GPIO, (1<<LEDG_PIN), OUTPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LEDB_GPIO, (1<<LEDB_PIN), OUTPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LED1_GPIO, (1<<LED1_PIN), OUTPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LED2_GPIO, (1<<LED2_PIN), OUTPUT);
   Chip_GPIO_SetDir(LPC_GPIO_PORT, LED3_GPIO, (1<<LED3_PIN), OUTPUT);

   /* Init EDU-CIAA-NXP Led Pins OFF */
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LEDR_GPIO, (1<<LEDR_PIN));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LEDG_GPIO, (1<<LEDG_PIN));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LEDB_GPIO, (1<<LEDB_PIN));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED1_GPIO, (1<<LED1_PIN));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED2_GPIO, (1<<LED2_PIN));
   Chip_GPIO_ClearValue(LPC_GPIO_PORT, LED3_GPIO, (1<<LED3_PIN));

}

static void coreInit(void) {

   /* Read clock settings and update SystemCoreClock variable */
   SystemCoreClockUpdate();

   /* To configure the Systick timer we use the SysTick_Config(uint32_t ticks);
    * funtion. With ticks we can set the Systick timer interval. In our case we
    * have a 204 MHz clock and we want it to fire each ms. So the tick has to
    * be set to 204 MHz / 1000.
    */
   SysTick_Config( SystemCoreClock / TICKRATE_HZ); /* TICKRATE_HZ ticks per second */
}

/* blocks for dlyTicks ms */
__INLINE static void delay(uint32_t dlyTicks){
    uint32_t curTicks;

    curTicks = msTicks;
    while ((msTicks - curTicks) < dlyTicks);
}

/*==================[external functions definition]==========================*/

__attribute__ ((section(".after_vectors")))
void SysTick_Handler(void) {

	msTicks++;

	if (msTicks == delay_ms){
      tiempoCumplido = 1;
      msTicks = 0;
   }
}

/* Set up and initialize board hardware */
void boardInit(void) {

   /* Config Core */
   coreInit();

   /* Initializes GPIO */
   Chip_GPIO_Init(LPC_GPIO_PORT);

   /* Config EDU-CIAA-NXP Button Pins */
   boardButtonsInit();

   /* Config EDU-CIAA-NXP Led Pins */
   boardLedsInit();

}

/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
int main(void)
{
   /* perform the needed initialization here */

   boardInit();

	delay_ms = 500;

   while(1) {

      if (tiempoCumplido){

         if (ledStatus){
            /* LED2 OFF */
            Chip_GPIO_SetPinState( LPC_GPIO_PORT, LED2_GPIO, LED2_PIN, OFF);
            ledStatus = OFF;
         } else{
			   /* LED2 ON */
			   Chip_GPIO_SetPinState( LPC_GPIO_PORT, LED2_GPIO, LED2_PIN, ON);
            ledStatus = ON;
         }

         tiempoCumplido = 0;
      }

      /* Read TEC1 */
      if( !(Chip_GPIO_ReadPortBit( LPC_GPIO_PORT, TEC1_GPIO, TEC1_PIN )) ){

         /* If TEC1 = 0, then LEDB ON */
         Chip_GPIO_SetPinState( LPC_GPIO_PORT, LEDB_GPIO, LEDB_PIN, ON);

      } else{

         /* else LEDB OFF */
         Chip_GPIO_SetPinState( LPC_GPIO_PORT, LEDB_GPIO, LEDB_PIN, OFF);
      }

   }

   return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
