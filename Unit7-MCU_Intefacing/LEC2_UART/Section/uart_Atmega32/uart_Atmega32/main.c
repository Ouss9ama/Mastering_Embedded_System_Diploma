/*
 * uart_Atmega32.c
 *
 * Created: 2/19/2025 1:12:44 PM
 * Author : oussa
 */ 

 #define F_CPU 8000000UL

#include "HAL/lcd.h"
#include "INCLUDES/ATMEGA32_memory_map.h"
#include "MCAL/Bit_manipulation.h"
#include "MCAL/uart.h"
#include <util/delay.h>

uint8_t X = 0;
 
int main(void)
{
	LCD_INIT();
	_delay_ms(600);
	LCD_CLEAR();
	_delay_ms(100);
	
	UART_Init();
	
	LCD_WRITE_STRING("UART IS LOADING");
// 	UART_Send('O');
// 	UART_Send('S');
// 	UART_Send('S');
	
	while(1)
	{	
		 // Step 1: Receive data from the PC
		X = UART_Recieve(); 
		 
		 // Step 2: Echo the received data back to the PC
		UART_Send(X);

		// Step 3: Optionally, display the received data on the LCD
		LCD_GO_TO_XY(2, 0);
		LCD_WRITE_CHAR(X);
	}

}

 