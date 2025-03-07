/*
 * Task2_code.c
 *
 * Created: 2/5/2025 3:06:33 PM
 * Author : oussa
 */ 

 
#define F_CPU 8000000UL
#include "MemoryMap.h"
#include "utils.h"
#include <util/delay.h>

int main(void)
{
	 static unsigned counter = 7;
     DDRD = (1<<5) | (1<<6) | (1<<7);//set pins D5,D6,D7 connected to leds as output
	 ClearBit(DDRD,0); // set the pins d0 as input
	 PORTD = 0x00;
	 while(1)
	 {
		 if(ReadBit(PIND,0) == 1)//check if button is pressed (high)
		 {
			 _delay_ms(50); //delay to make sure the button is pressed
			 
			 if(ReadBit(PIND,0) == 1) //check is the button is still pressed
			 {
				 if(counter>4)
				 {
					 _delay_ms(50);
					 SetBit(PORTD,counter);
					 counter--;
					 _delay_ms(300);
				 }
				 else
				 {
					 PORTD = 0x00;
					 counter = 7;
				 }
				 _delay_ms(300);
			 }
			 _delay_ms(300);
		 }
	 }

	  

}