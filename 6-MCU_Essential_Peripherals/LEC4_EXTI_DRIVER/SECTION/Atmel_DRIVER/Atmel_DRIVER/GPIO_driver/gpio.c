/*
 * gpio.c
 *
 * Created: 2/12/2025 5:05:28 PM
 *  Author: oussa
 */ 

#include "gpio.h"


void set_DDR_output(volatile uint8_t *DDRx, uint8_t pin){
	*DDRx |= (1 << pin);
}
void set_DDR_input(volatile uint8_t *DDRx, uint8_t pin){
	*DDRx &= ~(1 << pin);
}
void set_PORT_high(volatile uint8_t *PORTx, uint8_t pin){
	*PORTx |= (1 << pin);
}
void set_PORT_low(volatile uint8_t *PORTx, uint8_t pin){
	*PORTx &= ~(1 << pin);
}
Pin_state read_PIN(volatile uint8_t *PINx, uint8_t pin){
	uint8_t pin_state = 0;
	pin_state = (*PINx & (1<<pin))? pin_high : pin_low ;
	return pin_state;
}
