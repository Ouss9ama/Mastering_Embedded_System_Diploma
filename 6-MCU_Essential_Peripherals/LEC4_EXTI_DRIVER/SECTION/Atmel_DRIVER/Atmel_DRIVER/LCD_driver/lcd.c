/*
 * lcd.c
 *
 * Created: 2/12/2025 3:53:00 PM
 *  Author: oussa
 */ 

#include "../GPIO_driver/gpio.h"
#include "lcd.h"


#include <util/delay.h>

void LCD_CLEAR(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}
void LCD_KICK(){
	set_PORT_high(LCD_CTRL_PORT, EN); //Set enable high
	_delay_us(1);
	
	set_PORT_low(LCD_CTRL_PORT, EN);
	_delay_us(2);
	
}

void LCD_CHECK_BUSY(void){
	
	 // Step 1: Configure D7 as input to read the busy flag
	 set_DDR_input(LCD_DATA_DDR,7); 
	 
	 // Step 2: Set control pins for reading the busy flag
	 set_PORT_low(LCD_CTRL_PORT,RS); //RS = 0 (Command Mode)
	 set_PORT_high(LCD_CTRL_PORT,RW); // RW = 1 (Read Mode)
	 
	   // Step 3: Wait until the busy flag (D7) is cleared
	 while(read_PIN(LCD_DATA_PIN,7)){
		 LCD_KICK(); // Pulse EN to read the next state of D7  
	 }
	 
	 // Step 4: Restore control pins to write mode
	 set_PORT_low(LCD_CTRL_PORT,RW);
	 
	 // Step 5: Reconfigure D7 as output for normal operation
	 set_DDR_output(LCD_DATA_DDR,7);
	
}
void LCD_INIT(void){
	// Step 1: Configure control pins (RS, RW, EN) as output
	set_DDR_output(LCD_CTRL_DDR, RS);
	set_DDR_output(LCD_CTRL_DDR, RW);
	set_DDR_output(LCD_CTRL_DDR, EN);
	// Step 2: Configure data pins (D4-D7) as output
	*LCD_DATA_DDR = 0XF0; 
	// Step 3: Wait for LCD to power up
	_delay_ms(50);
	// Step 4: Switch to 4-bit mode
	LCD_WRITE_COMMAND(0x02);
	_delay_ms(5);
	// Step 5: Configure the LCD
	 LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);// 4-bit mode, 2 lines, 5x8 font
	 LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);// Display on, cursor on, blink on
	 LCD_CLEAR();
	  
	 LCD_WRITE_COMMAND(LCD_ENTRY_MODE);// Entry mode: increment cursor, no shift
	 LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW); //we set the cursor on to first row
	 
}

void LCD_WRITE_COMMAND(uint8_t command){
	set_PORT_low(LCD_CTRL_PORT,RS); // RS = 0 (Command mode)
	set_PORT_low(LCD_CTRL_PORT,RW);  // RW = 0 (Write mode)
	
	*LCD_DATA_PORT = (*LCD_DATA_PORT & 0X0F) | (command & 0xF0); //// Send higher nibble
	LCD_KICK(); 
	
	*LCD_DATA_PORT = (*LCD_DATA_PORT & 0X0F) | (command << 4 ); //// Send lower nibble	
	LCD_KICK(); 
	_delay_ms(2);
}

void LCD_GO_TO_XY(int line, int pos){
	//we have two lines (2 row) and 0-15 position
	uint8_t position;
	if(line == 1)
	{
		position = LCD_BEGIN_AT_FIRST_ROW + pos;
	}else
	{
		position = LCD_BEGIN_AT_SECOND_ROW + pos;
	}
	LCD_WRITE_COMMAND(position);
	}

void LCD_WRITE_CHAR(uint8_t data){
	// Step 1: Set RS = 1 (Data Mode), RW = 0 (Write Mode)
	set_PORT_high(LCD_CTRL_PORT,RS);
	set_PORT_low(LCD_CTRL_PORT,RW);
	
	*LCD_DATA_PORT = (*LCD_DATA_PORT & 0X0F) | (data & 0xF0); //// Send higher nibble
	LCD_KICK();
	
	*LCD_DATA_PORT = (*LCD_DATA_PORT & 0X0F) | (data << 4 ); //// Send lower nibble
	LCD_KICK();
	_delay_ms(2);
}

void LCD_WRITE_STRING(char* data){
	int counter = 0; //the counter we used here keeps track of how many characters have been written
	while(*data != '\0'){ //our loop is on as long as the current character is not '\0' (end of string)
		counter ++;
		_delay_ms(600);
		LCD_WRITE_CHAR(*data++);// write the character and move to the next one
		if(counter == 16){ //if 16 char have been written we move to the second row
			LCD_GO_TO_XY(2, 0);
		}
		else if(counter == 32){//if 32 char have been written we clear the screen and start all over again from the first row
			LCD_CLEAR();
			LCD_GO_TO_XY(1,0);
			counter = 0;
		}
	}
}