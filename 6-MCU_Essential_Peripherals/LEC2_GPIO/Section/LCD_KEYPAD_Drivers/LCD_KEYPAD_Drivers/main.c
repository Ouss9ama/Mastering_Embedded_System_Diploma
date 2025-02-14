/*
 * LCD_KEYPAD_Drivers.c
 *
 * Created: 2/6/2025 7:40:27 PM
 * Author : oussa
 */ 

#include <avr/io.h>
#include "LCD_driver/lcd.h"
#include "KEYPAD_driver/keypad.h"
 
int main(void)
{
   
	LCD_INIT(); // we initialized the LCD
	KEYPAD_INIT();
	LCD_WRITE_STRING("THEY CALL ME OUS");
	_delay_ms(1000);
	LCD_GO_TO_XY(2, 0);
	char Pressed_Key;
	
    while (1) 
    {	
		Pressed_Key = KEYPAD_GETCHAR();	
		switch(Pressed_Key)
		 {
			 case ('!'):
				 LCD_clear_screen();
				 break;
			 case ('A'):
				break;
			 default:
				LCD_WRITE_CHAR(Pressed_Key);
				break;
		 }
    }
	_delay_ms(200);
}

