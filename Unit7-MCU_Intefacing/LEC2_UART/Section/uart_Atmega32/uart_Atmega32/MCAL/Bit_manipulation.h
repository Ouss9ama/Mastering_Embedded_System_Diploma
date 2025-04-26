/*
 * Bit_manipulation.h
 *
 * Created: 2/19/2025 3:24:24 PM
 *  Author: oussa
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#include "stdint.h"

void set_bit(volatile uint8_t *reg, uint8_t bit);
void clear_bit(volatile uint8_t *reg, uint8_t bit);
void toggle_bit(volatile uint8_t *reg, uint8_t bit);
uint8_t read_bit(volatile uint8_t *reg, uint8_t bit);



#endif /* BIT_MANIPULATION_H_ */