/*
 * lcd.c
 *
 *  Created on: 10/09/2018
 *      Author: pc2
 * Basic Character LCD functions
 * By Los Cachos
 * 01/15/08
 **************************************************************************
 * 
 */
#include "../inc/lcd.h"
#include "stdint.h"                /* <= Standar Integer data types header */
#include "chip.h"

#define OUTPUT 1
#define INPUT 0
/* Define the number of cycles for 1ms */
#define INACCURATE_TO_MS 20400

union ubyte {
	char _byte;
	struct {
		unsigned char b0 :1;
		unsigned char b1 :1;
		unsigned char b2 :1;
		unsigned char b3 :1;
		unsigned char b4 :1;
		unsigned char b5 :1;
		unsigned char b6 :1;
		unsigned char b7 :1;
	} bit;
};

// Display configuration global variable
static char lcd_mode;

/** \brief delay function
 *
 * For Loop Delay. Inaccurate Blocking Delay.
 *
 */
void LCD_delay_ms(uint64_t delay_ms) {
	volatile uint64_t i;
	volatile uint64_t delay;

	delay = INACCURATE_TO_MS * delay_ms;

	for (i = delay; i > 0; i--);
}

//**************************************************************************
//* Send a nibble to the LCD
//**************************************************************************
//* Calling arguments
//* char data : data to be sent to the display
//**************************************************************************
void LCD_send_nibble(char data) {
	union ubyte my_union;
	my_union._byte = data;
	// Output the four data bits
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD1_GPIO, LCD1_PIN, my_union.bit.b0);
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD2_GPIO, LCD2_PIN, my_union.bit.b1);
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD3_GPIO, LCD3_PIN, my_union.bit.b2);
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD4_GPIO, LCD4_PIN, my_union.bit.b3);
	// pulse the LCD enable line
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD_EN_GPIO, LCD_EN_PIN, 1);
	for (data = 20; data; data--);
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD_EN_GPIO, LCD_EN_PIN, 0);
}

//**************************************************************************
//* Write a byte into the LCD
//**************************************************************************
//* Calling arguments:
//* char address : 0 for instructions, 1 for data
//* char data : command or data to be written
//**************************************************************************
void LCD_send_byte(char address, char data) {
	unsigned int temp;
	if (address == 0)
		Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD_RS_GPIO, LCD_RS_PIN, 0);              // config the R/S line
	else
		Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD_RS_GPIO, LCD_RS_PIN, 1);
	Chip_GPIO_SetPinState( LPC_GPIO_PORT, LCD_EN_GPIO, LCD_EN_PIN, 0);                // set LCD enable line to 0
	LCD_send_nibble(data >> 4);     // send the higher nibble
	LCD_send_nibble(data & 0x0f);   // send the lower nibble
	for (temp = 1000; temp; temp--);
}

//**************************************************************************
//* LCD initialization
//**************************************************************************
//* Calling arguments:
//* char mode1 : display mode (number of lines and character size)
//* char mode2 : display mode (cursor and display state)
//**************************************************************************
void LCD_init(char mode1, char mode2) {

	char aux;
	/* Initializes GPIO */
	Chip_GPIO_Init(LPC_GPIO_PORT);
	/* Config EDU-CIAA-NXP LCD Pins as GPIOs */
	Chip_SCU_PinMux(LCD_EN_P, LCD_EN_P_, MD_PLN, FUNC4); /* P4_9,  GPIO5[13],  LCD */
	Chip_SCU_PinMux(LCD_RS_P, LCD_RS_P_, MD_PLN, FUNC4);
	Chip_SCU_PinMux(LCD1_P, LCD1_P_, MD_PLN, FUNC0);
	Chip_SCU_PinMux(LCD2_P, LCD2_P_, MD_PLN, FUNC0);
	Chip_SCU_PinMux(LCD3_P, LCD3_P_, MD_PLN, FUNC0);
	Chip_SCU_PinMux(LCD4_P, LCD4_P_, MD_PLN, FUNC4);
	/* Config EDU-CIAA-NXP LCD Pins as Outputs */
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD_EN_GPIO, (1 << LCD_EN_PIN), OUTPUT);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD_RS_GPIO, (1 << LCD_RS_PIN), OUTPUT);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD1_GPIO, (1 << LCD1_PIN), OUTPUT);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD2_GPIO, (1 << LCD2_PIN), OUTPUT);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD3_GPIO, (1 << LCD3_PIN), OUTPUT);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, LCD4_GPIO, (1 << LCD4_PIN), OUTPUT);
	// Set the LCD data pins to zero
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD_EN_GPIO, (1 << LCD_EN_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD_RS_GPIO, (1 << LCD_RS_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD1_GPIO, (1 << LCD1_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD2_GPIO, (1 << LCD2_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD3_GPIO, (1 << LCD3_PIN));
	Chip_GPIO_ClearValue(LPC_GPIO_PORT, LCD4_GPIO, (1 << LCD4_PIN));
	LCD_delay_ms(15);
	// LCD 4-bit mode initialization sequence
	// send three times 0x03 and then 0x02 to finish configuring the LCD
	for (aux = 0; aux < 3; ++aux) {
		LCD_send_nibble(3);
		LCD_delay_ms(5);
	}
	LCD_send_nibble(2);
	// Now send the LCD configuration data
	LCD_send_byte(0, 0x20 | mode1);
	LCD_send_byte(0, 0x08 | mode2);
	lcd_mode = 0x08 | mode2;

	LCD_send_byte(0, 1);
	LCD_delay_ms(5);
	LCD_send_byte(0, 6); //entry mode set I/D=1 S=0
}

//**************************************************************************
//* LCD cursor position set
//**************************************************************************
//* Calling arguments:
//* char x : column (starting by 0)
//* char y : line (0 or 1)
//**************************************************************************
void LCD_pos_xy(char x, char y) {
	char address;
	if (y)
		address = LCD_SEC_LINE;
	else
		address = 0;
	address += x;
	LCD_send_byte(0, 0x80 | address);
}

//**************************************************************************
//* Write a character on the display
//**************************************************************************
//* Calling arguments:
//* char c : character to be written
//**************************************************************************
//* Notes :
//* \f clear the display
//* \n and \r return the cursor to line 1 column 0
//**************************************************************************
void LCD_write_char(char c) {
	switch (c) {
	case '\f':
		LCD_send_byte(0, 1);
		LCD_delay_ms(5);
		break;
	case '\n':
	case '\r':
		LCD_pos_xy(0, 1);
		break;
	default:
		LCD_send_byte(1, c);
	}
}

//**************************************************************************
//* Write a string on the display
//**************************************************************************
//* Calling arguments:
//* char *c : pointer to the string
//**************************************************************************
void LCD_write_string(char *c) {
	while (*c) {
		LCD_write_char(*c);
		c++;
	}
}

//**************************************************************************
//* Turn the display on
//**************************************************************************
void LCD_display_on(void) {
	lcd_mode |= 4;
	LCD_send_byte(0, lcd_mode);
}

//**************************************************************************
//* Turn the display off
//**************************************************************************
void LCD_display_off(void) {
	lcd_mode &= 0b11111011;
	LCD_send_byte(0, lcd_mode);
}

//**************************************************************************
//* Turn the cursor on
//**************************************************************************
void LCD_cursor_on(void) {
	lcd_mode |= 2;
	LCD_send_byte(0, lcd_mode);
}

//**************************************************************************
//* Turn the cursor off
//**************************************************************************
void LCD_cursor_off(void) {
	lcd_mode &= 0b11111101;
	LCD_send_byte(0, lcd_mode);
}

//**************************************************************************
//* Turn on the cursor blink function
//**************************************************************************
void LCD_cursor_blink_on(void) {
	lcd_mode |= 1;
	LCD_send_byte(0, lcd_mode);
}

//**************************************************************************
//* Turn off the cursor blink function
//**************************************************************************
void LCD_cursor_blink_off(void) {
	lcd_mode &= 0b11111110;
	LCD_send_byte(0, lcd_mode);
}
