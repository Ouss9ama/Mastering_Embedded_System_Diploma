/*
 * lcd.h
 *
 * Created: 2/12/2025 3:53:19 PM
 *  Author: oussa
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "../GPIO_driver/gpio.h"

#define RS				1
#define RW				2
#define EN				3
#define LCD_CTRL_DDR	&DDRB
#define LCD_DATA_DDR	&DDRA  
#define LCD_CTRL_PORT	&PORTB 
#define LCD_DATA_PORT	&PORTA 
#define LCD_DATA_PIN	&PINA

/****************************Commands***************************************/
#define LCD_FUNCTION_8BIT_2LINES    (0x38) // 8-bit mode, 2 lines, 5x7 font
#define LCD_FUNCTION_4BIT_2LINES    (0x28) // 4-bit mode, 2 lines, 5x7 font
#define LCD_MOVE_DISP_RIGHT         (0x1C) // Move display to the right
#define LCD_MOVE_DISP_LEFT          (0x18) // Move display to the left
#define LCD_MOVE_CURSOR_RIGHT       (0x14) // Move cursor to the right
#define LCD_MOVE_CURSOR_LEFT        (0x10) // Move cursor to the left
#define LCD_DISP_OFF                (0x08) // Turn off display
#define LCD_DISP_ON_CURSOR          (0x0E) // Turn on display and cursor
#define LCD_DISP_ON_CURSOR_BLINK    (0x0F) // Turn on display, cursor, and blinking
#define LCD_DISP_ON_BLINK           (0x0D) // Turn on display and blinking
#define LCD_DISP_ON                 (0x0C) // Turn on display only
#define LCD_ENTRY_DEC               (0x04) // Cursor moves left after character write
#define LCD_ENTRY_DEC_SHIFT         (0x05) // Cursor moves left, display shifts
#define LCD_ENTRY_INC_              (0x06) // Cursor moves right after character write
#define LCD_ENTRY_INC_SHIFT         (0x07) // Cursor moves right, display shifts
#define LCD_BEGIN_AT_FIRST_ROW      (0x80) // Set cursor to the first row
#define LCD_BEGIN_AT_SECOND_ROW     (0xC0) // Set cursor to the second row
#define LCD_CLEAR_SCREEN            (0x01) // Clear the display
#define LCD_ENTRY_MODE              (0x06) // Increment cursor after character write


//functions prototypes
void LCD_INIT(void);
void LCD_WRITE_COMMAND(uint8_t command);
void LCD_WRITE_CHAR(uint8_t data);
void LCD_WRITE_STRING(char* data);
void LCD_IS_BUSY(void);
void LCD_CLEAR(void);
void LCD_GO_TO_XY(int line, int pos);





#endif /* LCD_H_ */