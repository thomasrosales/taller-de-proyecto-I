/*
 * lcd.h
 *
 *  Created on: 30/07/2013
 *      Author: pc2
 */

#ifndef LCD_H_
#define LCD_H_

#include "stdint.h"

// The following defines set the default pins for the LCD display
/*
 * LCD_P = Puerto
 * LCD_P_ = Pin
 * P4_9
 * LCD_GPIO = Puerto GPIO
 * LCD_PIN = Pin GPIO
 * GPIO5[13]
 */

#define LCD_EN_P    4
#define LCD_EN_P_   9
#define LCD_EN_GPIO 5
#define LCD_EN_PIN  13

#define LCD_RS_P    4
#define LCD_RS_P_   8
#define LCD_RS_GPIO 5
#define LCD_RS_PIN  12

#define LCD1_P    4
#define LCD1_P_   4
#define LCD1_GPIO 2
#define LCD1_PIN  4

#define LCD2_P    4
#define LCD2_P_   5
#define LCD2_GPIO 2
#define LCD2_PIN  5

#define LCD3_P    4
#define LCD3_P_   6
#define LCD3_GPIO 2
#define LCD3_PIN  6

#define LCD4_P    4
#define LCD4_P_   10
#define LCD4_GPIO 5
#define LCD4_PIN  14

#define LCD_SEC_LINE    0x40    // Address of the second line of the LCD

// LCD configuration constants
#define CURSOR_ON       2
#define CURSOR_OFF      0
#define CURSOR_BLINK    1
#define CURSOR_NOBLINK  0
#define DISPLAY_ON      4
#define DISPLAY_OFF     0
#define DISPLAY_8X5     0
#define DISPLAY_10X5    4
#define _2_LINES        8
#define _1_LINE         0


//**************************************************************************
//* Prototypes
//**************************************************************************
void LCD_delay_ms (uint64_t delay_ms);
void LCD_send_nibble(char data);
void LCD_send_byte(char address, char data);
void LCD_init(char mode1, char mode2);
void LCD_pos_xy(char x, char y);
void LCD_write_char(char c);
void LCD_write_string (char *c);
void LCD_display_on(void);
void LCD_display_off(void);
void LCD_cursor_on(void);
void LCD_cursor_off(void);
void LCD_cursor_blink_on(void);
void LCD_cursor_blink_off(void);

#endif /* LCD_H_ */
