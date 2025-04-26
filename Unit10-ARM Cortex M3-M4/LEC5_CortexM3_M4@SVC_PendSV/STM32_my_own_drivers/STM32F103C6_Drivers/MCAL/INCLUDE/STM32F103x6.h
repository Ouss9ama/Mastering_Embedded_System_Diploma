/*
 * STM32F103x8.h
 *
 *  Created on: Feb 8, 2025
 *      Author: oussama
 */

#ifndef INCLUDES_STM32F103X6_H_
#define INCLUDES_STM32F103X6_H_

/*---------------------------------------------------------------------------------------------------------------------------*/
//Includes
/*---------------------------------------------------------------------------------------------------------------------------*/

#include "stdlib.h"
#include "stdint.h"

/*---------------------------------------------------------------------------------------------------------------------------*/
//Base addresses for Memories
/*---------------------------------------------------------------------------------------------------------------------------*/
#define FLASH_MEMORY_BASE					0x08000000UL
#define SYSTEM_MEMORY_BASE					0x1FFFF000UL
#define SRAM_MEMORY_BASE					0x20000000UL


#define PERIPHERALS_BASE					0x40000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE	0xE0000000UL

//NVIC register map
#define NVIC_BASE							0xE000E100UL
#define NVIC_ISER0						*((volatile uint32_t *)(NVIC_BASE + 0x00)) // ISER0: Enables interrupts 0 to 31
#define NVIC_ISER1						*((volatile uint32_t *)(NVIC_BASE + 0x04)) // ISER1: Enables interrupts 32 to 63
#define NVIC_ISER2						*((volatile uint32_t *)(NVIC_BASE + 0x08)) // ISER2: Enables interrupts 64 to 95
#define NVIC_ICER0						*((volatile uint32_t *)(NVIC_BASE + 0x80)) // ICER0: Disables interrupts 0 to 31
#define NVIC_ICER1						*((volatile uint32_t *)(NVIC_BASE + 0x84)) // ICER1: Disables interrupts 32 to 63
#define NVIC_ICER2						*((volatile uint32_t *)(NVIC_BASE + 0x88)) // ICER2: Disables interrupts 64 to 95


/*---------------------------------------------------------------------------------------------------------------------------*/
//Base addresses for AHB Peripherals
/*---------------------------------------------------------------------------------------------------------------------------*/

//RCC
#define RCC_BASE							0x40021000UL

/*---------------------------------------------------------------------------------------------------------------------------*/
//Base addresses for APB2 Peripherals
/*---------------------------------------------------------------------------------------------------------------------------*/

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE 							0x40010800UL
#define GPIOB_BASE							0x40010C00UL
//C,D Partially ncluded in LQFP48 Package
#define GPIOC_BASE							0x40011000UL
#define GPIOD_BASE							0x40011400UL
//E Partially ncluded in LQFP48 Package
#define GPIOE_BASE							0x40011800UL

//EXTI
#define EXTI_BASE							0x40010400UL

//AFIO
#define AFIO_BASE							0x40010000UL

/*---------------------------------------------------------------------------------------------------------------------------*/
//Base addresses for APB2 Peripherals
/*---------------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------------------------------------------------------*/
//Peripheral registers:
/*---------------------------------------------------------------------------------------------------------------------------*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: GPIO
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct{
	volatile uint32_t CRL;//Configuration Register Low (configures the lower 8 pins of the GPIO port)
	volatile uint32_t CRH;//Configuration Register High (configures the upper 8 pins of the GPIO port)
	volatile uint32_t IDR;//Input Data Register (reads the state of the input pins)
	volatile uint32_t ODR;//Output Data Register (sets the state of the output pins)
	volatile uint32_t BSRR;//Bit Set/Reset Register (set or reset individual bits in the ODR)
	volatile uint32_t BRR;//Bit Reset Register (reset individual bits in the ODR)
	volatile uint32_t LCKR;//Configuration Lock Register (locks the configuration of the GPIO pins)
}GPIO_TypeDef;


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: RCC
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct{
    volatile uint32_t CR;// Clock Control Register: Configures and controls the main PLL and oscillators.
    volatile uint32_t CFGR;// Clock Configuration Register: Sets system clock sources, prescalers, and bus dividers.
    volatile uint32_t CIR;// Clock Interrupt Register: Manages clock interrupts and flags.
    volatile uint32_t APB2RSTR;// APB2 Peripheral Reset Register: Resets peripherals on the APB2 bus.
    volatile uint32_t APB1RSTR;// APB1 Peripheral Reset Register: Resets peripherals on the APB1 bus.
    volatile uint32_t AHBENR;// AHB Peripheral Clock Enable Register: Enables clock for AHB peripherals.
    volatile uint32_t APB2ENR;// APB2 Peripheral Clock Enable Register: Enables clock for APB2 peripherals.
    volatile uint32_t APB1ENR;// APB1 Peripheral Clock Enable Register: Enables clock for APB1 peripherals.
    volatile uint32_t BDCR;// Backup Domain Control Register: Manages RTC clock and backup domain reset.
    volatile uint32_t CSR; // Control/Status Register: Controls low-power modes and status flags.
}RCC_TypeDef;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: EXTI
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct{
    volatile uint32_t IMR;// Interrupt Mask Register: Enables/disables interrupt lines.
    volatile uint32_t EMR;// Event Mask Register: Enables/disables event lines.
    volatile uint32_t RTSR;// Rising Trigger Selection Register: Configures rising edge triggers.
    volatile uint32_t FTSR;// Falling Trigger Selection Register: Configures falling edge triggers.
    volatile uint32_t SWIER;// Software Interrupt Event Register: Triggers interrupts/events via software.
    volatile uint32_t PR;// Pending Register: Indicates/clears pending interrupt/event flags.
} EXTI_TypeDef;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: AFIO
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct{
    volatile uint32_t EVCR;// Event Control Register: Configures external event inputs.
    volatile uint32_t MAPR;// Remap and Debug I/O Configuration Register: Manages pin remapping and debug settings.
//  volatile uint32_t EXTICR1;// External Interrupt Configuration Register 1: Maps EXTI lines to GPIO ports.
//  volatile uint32_t EXTICR2;// External Interrupt Configuration Register 2: Maps EXTI lines to GPIO ports.
//  volatile uint32_t EXTICR3;// External Interrupt Configuration Register 3: Maps EXTI lines to GPIO ports.
//  volatile uint32_t EXTICR4;// External Interrupt Configuration Register 4: Maps EXTI lines to GPIO ports.
    volatile uint32_t EXITCR[4];
    volatile uint32_t RESERVED0;// Reserved: Unused register (padding).
    volatile uint32_t MAPR2;// Remap and Debug I/O Configuration Register 2: Additional pin remapping settings.
}AFIO_TypeDef;

/*---------------------------------------------------------------------------------------------------------------------------*/
//Peripheral instants:
/*---------------------------------------------------------------------------------------------------------------------------*/
//GPIO
#define GPIOA							((GPIO_TypeDef *)GPIOA_BASE) // GPIO_TypeDef *GPIOA =(GPIO_TypeDef *)GPIOA_BASE;
#define GPIOB							((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC							((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD							((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE							((GPIO_TypeDef *)GPIOE_BASE)
//RCC
#define RCC							    ((RCC_TypeDef *)RCC_BASE)
//EXTI
#define EXTI							((EXTI_TypeDef *)EXTI_BASE)
//AFIO
#define AFIO							((AFIO_TypeDef *)AFIO_BASE)


/*---------------------------------------------------------------------------------------------------------------------------*/
//Clock Enable Macros:
/*---------------------------------------------------------------------------------------------------------------------------*/

//clock enable fo GPIO
#define RCC_GPIOA_CLK_EN() 				(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN() 				(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN() 				(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN() 				(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN() 				(RCC->APB2ENR |= (1<<6))

//clock enable fo AFIO
#define RCC_AFIO_CLK_EN() 				(RCC->APB2ENR |= (1<<0))


/*---------------------------------------------------------------------------------------------------------------------------*/
// IVT: INTERRUPT VECTOR TABLE
/*---------------------------------------------------------------------------------------------------------------------------*/

//EXTI
#define EXTI0_IRQ                       6
#define EXTI1_IRQ                       7
#define EXTI2_IRQ                       8
#define EXTI3_IRQ                       9
#define EXTI4_IRQ                       10
#define EXTI5_IRQ                       23
#define EXTI6_IRQ                       23
#define EXTI8_IRQ                       23
#define EXTI9_IRQ                       23
#define EXTI10_IRQ                      40
#define EXTI12_IRQ                      40
#define EXTI13_IRQ                      40
#define EXTI14_IRQ                      40
#define EXTI15_IRQ                      40


/*---------------------------------------------------------------------------------------------------------------------------*/
// NVIC IRQ Enable/Disable macros
/*---------------------------------------------------------------------------------------------------------------------------*/

#define NVIC_IRQ6_EXTI0_Enable           (NVIC_ISER0 |= (1<<6)) //EXTI0 → IRQ6 → NVIC enables bit 6 → CPU jumps to EXTI0_IRQHandler()
#define NVIC_IRQ7_EXTI1_Enable           (NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable           (NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable           (NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable          (NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_to_9_Enable     (NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_to_15_Enable   (NVIC_ISER1 |= (1<<8)) //40-32=8

#define NVIC_IRQ6_EXTI0_disable          (NVIC_ICER0 |= (1<<6)) //NVIC_ICER0 disable interrupt by setting one in it
#define NVIC_IRQ7_EXTI1_disable          (NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_disable          (NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_disable          (NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_disable         (NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_to_9_disable    (NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_to_15_disable  (NVIC_ICER1 |= (1<<8)) //40-32=8

#endif /* INCLUDES_STM32F103X6_H_ */
