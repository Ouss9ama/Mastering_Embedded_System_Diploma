/*
 * Task_code.c
 *
 * Created: 2/5/2025 11:21:30 AM
 * Author : oussa
 */ 

#define F_CPU 8000000UL
#include "MemoryMap.h"
#include "utils.h" 
#include <util/delay.h>



 int main(void)
 {
	  ClearBit(DDRD,0);//set pinD0 as input
	  SetBit(DDRD,7); //SET pinD7 as output
	 while (1)
	 {
		   if(ReadBit(PIND,0) == 1){
			   SetBit(PORTD,7);
		   }
		   
	 }
 }