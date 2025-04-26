/*
 * Bit_manipulation.c
 *
 * Created: 2/19/2025 3:25:41 PM
 *  Author: oussa
 */ 

#include "Bit_manipulation.h"

void set_bit(volatile uint8_t *reg, uint8_t bit)
{
	*reg |= (1 << bit);
	
}
void clear_bit(volatile uint8_t *reg, uint8_t bit)
{
	*reg &= ~(1 << bit);
}

void toggle_bit(volatile uint8_t *reg, uint8_t bit)
{
	*reg ^= (1 << bit);
}

uint8_t read_bit(volatile uint8_t *reg, uint8_t bit)
{
	return (*reg & (1 << bit)) ? 1 : 0;
}