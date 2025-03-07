#include "uart.h"
unsigned char string_2_uart[100]="Learn_in_depth: Oussama";

void main()
{

     Uart_Send_String(string_2_uart);   

}