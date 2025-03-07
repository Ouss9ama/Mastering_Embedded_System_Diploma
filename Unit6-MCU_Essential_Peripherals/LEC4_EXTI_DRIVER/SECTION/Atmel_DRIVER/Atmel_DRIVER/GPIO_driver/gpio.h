/*
 * gpio.h
 *
 * Created: 2/12/2025 4:35:38 PM
 *  Author: oussa
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
typedef enum {
	pin_low = 0 ,
	pin_high = 1
	}Pin_state;

#define DDRA *((volatile uint8_t*)(0x3A))   
#define PORTA *((volatile uint8_t*)(0x3B))     
#define PINA *((volatile uint8_t*)(0x39))

#define DDRB *((volatile uint8_t*)(0x37))
#define PORTB *((volatile uint8_t*)(0x38))
#define PINB *((volatile uint8_t*)(0x36))


void set_DDR_output(volatile uint8_t *DDRx, uint8_t pin);
void set_DDR_input(volatile uint8_t *DDRx, uint8_t pin);
void set_PORT_high(volatile uint8_t *DDRx, uint8_t pin);
void set_PORT_low(volatile uint8_t *DDRx, uint8_t pin);
Pin_state read_PIN(volatile uint8_t *PINx, uint8_t pin);



#endif /* GPIO_H_ */