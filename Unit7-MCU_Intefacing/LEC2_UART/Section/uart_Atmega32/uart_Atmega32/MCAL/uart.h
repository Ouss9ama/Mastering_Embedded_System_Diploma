/*
 * uart.h
 *
 * Created: 2/19/2025 3:46:24 PM
 *  Author: oussa
 */ 


#ifndef UART_H_
#define UART_H_

#include "stdint.h"
/*---------------------------------------------------------------------------------------------------------------------------*/
// USART Register Bit Definitions
/*---------------------------------------------------------------------------------------------------------------------------*/

// UCSRA (USART Control and Status Register A)
#define RXC     7  // USART Receive Complete
#define TXC     6  // USART Transmit Complete
#define UDRE    5  // USART Data Register Empty
#define FE      4  // Frame Error
#define DOR     3  // Data OverRun
#define UPE     2  // USART Parity Error
#define U2X     1  // Double the USART Transmission Speed
#define MPCM    0  // Multi-Processor Communication Mode

// UCSRB (USART Control and Status Register B)
#define RXCIE   7  // RX Complete Interrupt Enable
#define TXCIE   6  // TX Complete Interrupt Enable
#define UDRIE   5  // USART Data Register Empty Interrupt Enable
#define RXEN    4  // Receiver Enable
#define TXEN    3  // Transmitter Enable
#define UCSZ2   2  // Character Size (bit 2)
#define RXB8    1  // Receive Data Bit 8
#define TXB8    0  // Transmit Data Bit 8

// UCSRC (USART Control and Status Register C)
#define URSEL   7  // Register Select (1 = UCSRC, 0 = UBRRH)
#define UMSEL   6  // USART Mode Select (0 = Asynchronous, 1 = Synchronous)
#define UPM1    5  // Parity Mode Bit 1
#define UPM0    4  // Parity Mode Bit 0
#define USBS    3  // Stop Bit Select (0 = 1 stop bit, 1 = 2 stop bits)
#define UCSZ1   2  // Character Size Bit 1
#define UCSZ0   1  // Character Size Bit 0
#define UCPOL   0  // Clock Polarity (used in synchronous mode)


void UART_Init(void);
void UART_Send(uint8_t data);
uint8_t UART_Recieve(void);
uint32_t UART_SendNumberU32(uint32_t num);
uint32_t UART_RecieveNumberU32(void);
void UART_SendString(char* str);
void UART_RecieveString(char* buffer);

#endif /* UART_H_ */