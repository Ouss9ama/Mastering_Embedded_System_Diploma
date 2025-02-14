/*
 * keypad.h
 *
 * Created: 2/7/2025 2:49:28 PM
 *  Author: oussa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_PORT PORTD
#define DDR_KEYPAD_PORT DDRD
#define KEYPAD_PIN PIND

#define R0 0 //row 0 to D0 and so on
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7


void KEYPAD_INIT();
char KEYPAD_GETCHAR();


#endif /* KEYPAD_H_ */