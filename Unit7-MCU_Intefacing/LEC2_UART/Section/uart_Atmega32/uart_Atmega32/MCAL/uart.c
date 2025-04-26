/*
 * uart.c
 *
 * Created: 2/19/2025 3:46:02 PM
 *  Author: oussa
 */ 

#include "uart.h"
#include "Bit_manipulation.h"
#include "../INCLUDES/ATMEGA32_memory_map.h"

//Configures the baud rate, sets asynchronous mode, and enables the transmitter/receiver.
void UART_Init(void)
{
	//set up the baudrate
	UBRRL = 51;
	clear_bit(&UCSRA,U2X);//Normal mode
	//set up the frame
	clear_bit(&UCSRC,UMSEL); //Asynchronous mode
	//Enable the transmitter and receiver
	set_bit(&UCSRB,TXEN); // Enable transmitter
	set_bit(&UCSRB,RXEN); // Enable receiver
	
}

//Waits until the transmit buffer is empty and then writes the data to the UDR register.
void UART_Send(uint8_t data)
{
	while(!read_bit(&UCSRA,UDRE)); // Wait until the transmit buffer is empty
	UDR = data; // Write the data to the UART Data Register (UDR)
}

//Waits until data is received and then reads the data from the UDR register.
uint8_t UART_Recieve(void){
	while(!read_bit(&UCSRA,RXC));
	return UDR;
}


uint32_t UART_SendNumberU32(uint32_t num)
{
	uint8_t* p = &num; // Create a pointer to the memory location of `num`
	UART_Send(p[0]);   // Send the first byte (least significant byte) of `num`
	UART_Send(p[1]);   // Send the second byte of `num`
	UART_Send(p[2]);   // Send the third byte of `num`
	UART_Send(p[3]);   // Send the fourth byte (most significant byte) of `num`
}


uint32_t UART_RecieveNumberU32(void)
{
	uint32_t num;      // Declare a variable to hold the received number
	uint8_t* p = &num; // Create a pointer to the memory location of `num`
	p[0] = UART_Recieve(); // Receive the first byte and store it in the first byte of `num`
	p[1] = UART_Recieve(); // Receive the second byte and store it in the second byte of `num`
	p[2] = UART_Recieve(); // Receive the third byte and store it in the third byte of `num`
	p[3] = UART_Recieve(); // Receive the fourth byte and store it in the fourth byte of `num`
	return num;        // Return the fully assembled 32-bit number
}

void UART_SendString(char* str)
{
	while (*str) // Loop until the null terminator is reached
	{
		UART_Send(*str); // Send the current character
		str++;           // Move to the next character
	}
}

 

void UART_RecieveString(char* buffer)
{
    uint8_t index = 0;
    char receivedChar;

    while (index < 49) // Limit to 49 characters (leave space for null terminator)
    {
        receivedChar = UART_Recieve(); // Receive a character

        // Echo the character back to the virtual terminal for debugging
        UART_Send(receivedChar);

        if (receivedChar == '\n' || receivedChar == '\r')
            break;

        buffer[index++] = receivedChar; // Store the character and increment the index
    }

    buffer[index] = '\0'; // Null-terminate the string
}