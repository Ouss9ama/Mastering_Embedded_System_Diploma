/*
 * ATMEGA32_memory_map.h
 *
 * Created: 2/19/2025 3:23:09 PM
 *  Author: oussa
 */ 


#ifndef ATMEGA32_MEMORY_MAP_H_
#define ATMEGA32_MEMORY_MAP_H_


#include <stdint.h>

// GPIO Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

// UART Registers
#define UDR   *((volatile uint8_t*)0x2C) // USART Data Register
#define UCSRA *((volatile uint8_t*)0x2B) // USART Control and Status Register A
#define UCSRB *((volatile uint8_t*)0x2A) // USART Control and Status Register B
#define UCSRC *((volatile uint8_t*)0x40) // USART Control and Status Register C
#define UBRRL *((volatile uint8_t*)0x29) // USART Baud Rate Register Low
#define UBRRH *((volatile uint8_t*)0x40) // USART Baud Rate Register High



#endif /* ATMEGA32_MEMORY_MAP_H_ */