/*
 * task3.c
 *
 * Created: 2/5/2025 9:45:13 PM
 * Author : oussa
 */ 

#define F_CPU 8000000UL
#include "MemoryMap.h"
#include "utils.h"
#include <util/delay.h>


int main(void)
{
    ClearBit(DDRD,0); //set pin D0 as input connected to pushbutton + pull-down resistor
	SetBit(DDRD,4); //set pin D4 as output
    while (1) 
    {
		if(ReadBit(PIND,0) == 1)
		{
			SetBit(PORTD,4);
    }
}
}
