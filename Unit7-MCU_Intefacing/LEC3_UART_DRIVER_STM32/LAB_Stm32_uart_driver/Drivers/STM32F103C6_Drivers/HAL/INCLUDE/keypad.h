/*
 * keypad.h
 *
 * Created: 2/7/2025 2:49:28 PM
 *  Author: oussa
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL
#include "STM32F103x6.h"
#include "gpio_driver.h"

#define KEYPAD_PORT GPIOB


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


void KEYPAD_INIT();
char KEYPAD_GETCHAR();


#endif /* KEYPAD_H_ */
