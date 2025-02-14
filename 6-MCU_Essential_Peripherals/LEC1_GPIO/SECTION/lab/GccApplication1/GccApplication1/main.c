/*
 * GccApplication1.c
 *
 * Created: 2/5/2025 1:34:50 AM
 * Author : oussa
 */ 


#define F_CPU 8000000UL
#include "MemoryMap.h"
#include "utils.h"
#include <util/delay.h>
/* 7segment:
	0x3f = 0
	0x06 = 1
	0x5b = 2
	0x4f = 3
	0x66 = 4
	0x6d = 5
	0x7d = 6
	0x07 = 7
	0x7f = 8
 	0x6f = 9
*/
//static unsigned char SegmentNumber[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	
int main(void)
{
	DDRC = 0xff;
	unsigned char i,j;
	while(1)
	{
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				PORTC = 0b1011 | (i<<4);
				_delay_ms(300);
				PORTC = 0b0111 | (j<<4);
				_delay_ms(300);
			}
			
		}
	}
	
	 
}

 