/*
 * Atmel_DRIVER.c
 *
 * Created: 2/12/2025 9:30:02 PM
 * Author : oussa
 */ 

#include "GPIO_driver/gpio.h"
#include "LCD_driver/lcd.h"
#define F_CPU 8000000UL
#include <util/delay.h>
 
int main(void)
{
     LCD_INIT();
	  _delay_ms(600);
	 LCD_CLEAR();
	 _delay_ms(100);
	  LCD_WRITE_STRING("Learn In Depth");
	  LCD_GO_TO_XY(2,0);
	  LCD_WRITE_STRING("ATMEGA32 DRIVERS");
	 while(1){
		
	 }
}

