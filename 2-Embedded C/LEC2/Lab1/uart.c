#include "uart.h"

#define UART0DR *((volatile unsigned int*)((volatile unsigned int*)0x101f1000 + 0x0))

void Uart_Send_String(unsigned char *p_str)
{
    while(*p_str !='\0')
    {
    	UART0DR = (volatile unsigned int)*p_str;
    	p_str++;

    }
}