/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>



// Register addresses
#define GPIOPA_Base 0x40010800
#define RCC_base 0x40021000
#define GPIO_CRH   *((volatile uint32_t*)(GPIOPA_Base + 0x04))//ptr to volatile unsigned 32 bit integer that points to the mentioned adress
#define GPIOPA_ODR  *((volatile uint32_t*)(GPIOPA_Base + 0x0C))//ptr to volatile unsigned 32 bit integer that points to the mentioned adress
#define RCC_APB2ENR  *((volatile uint32_t*)(RCC_base + 0x18))


int main(void)
{
	// init clock  for GPIO PORT A :
	//	Bit 2 IOPARST: I/O port A reset
	//	 Set and cleared by software.
	//	 0: No effect
	//	 1: Reset I/O port A
	RCC_APB2ENR |= 1<<2;
	// initiate the GPIO
	GPIO_CRH &=0Xff0fffff;
	GPIO_CRH |=0X00200000;

	while(1)
	{
		GPIOPA_ODR |= 1<<13; //set bit 13
		for( int i=0;i<5000;i++);

		GPIOPA_ODR &= ~(1<<13);
		for(  int i=0;i<5000;i++);
	}


}

