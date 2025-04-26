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

//USART1
#define USART1_BASE							0x40013800UL

//SPI1
#define SPI1_BASE							0X40013000UL
/*---------------------------------------------------------------------------------------------------------------------------*/
//Base addresses for APB1 Peripherals
/*---------------------------------------------------------------------------------------------------------------------------*/

//USART2
#define USART2_BASE							0x40004400UL
//USART3
#define USART3_BASE							0x40004800UL
//SPI2
#define SPI2_BASE							0X40013800UL
//I2C1
#define I2C1_BASE							0x40005400UL
//I2C2
#define I2C2_BASE							0x40005800UL
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

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: USART
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct {
    volatile uint32_t USART_SR;  // Status Register: Contains flags indicating the status of the USART, such as transmit complete, receive data ready, etc.
    volatile uint32_t USART_DR;  // Data Register: Holds the data to be transmitted or the received data. Writing to this register sends data, and reading from it retrieves received data.
    volatile uint32_t USART_BRR; // Baud Rate Register: Configures the baud rate for communication. The value in this register determines the speed of data transmission.
    volatile uint32_t USART_CR1; // Control Register 1: Contains configuration bits for basic USART features, such as enabling the transmitter/receiver, oversampling mode, and interrupt enables.
    volatile uint32_t USART_CR2; // Control Register 2: Provides additional configuration options, such as addressing mode, stop bits, and LIN mode settings.
    volatile uint32_t USART_CR3; // Control Register 3: Configures advanced USART features, including hardware flow control (RTS/CTS), DMA modes, and wake-up methods.
    volatile uint32_t USART_GTPR; // Guard Time and Prescaler Register: Used in smartcard mode to configure the guard time and prescaler values for clock generation.
} USART_TypeDef;

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: SPI
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct {
    volatile uint32_t SPI_CR1;       // Control Register 1: Configures SPI mode, clock polarity, phase, baud rate, data format, etc.
    volatile uint32_t SPI_CR2;       // Control Register 2: Configures additional settings like NSS management, interrupts, and DMA control.
    volatile uint32_t SPI_SR;        // Status Register: Contains flags for SPI status, such as transmit buffer empty, receive buffer not empty, and overrun.
    volatile uint32_t SPI_DR;        // Data Register: Holds data for transmission and reception.
    volatile uint32_t SPI_CRCPR;     // CRC Polynomial Register: Defines the polynomial for cyclic redundancy check (CRC) calculation.
    volatile uint32_t SPI_RXCRCR;    // RX CRC Register: Stores the CRC value calculated for received data.
    volatile uint32_t SPI_TXCRCR;    // TX CRC Register: Stores the CRC value calculated for transmitted data.
    volatile uint32_t SPI_I2SCFGR;   // I2S Configuration Register: Configures SPI in I2S mode for audio communication.
    volatile uint32_t SPI_I2SPR;     // I2S Prescaler Register: Defines the prescaler value for the I2S clock.
} SPI_TypeDef;


/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
//Peripheral register: I2C
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

typedef struct {
    volatile uint32_t I2C_CR1;    // Control Register 1: Enables I2C, configures ACK, start/stop generation
    volatile uint32_t I2C_CR2;    // Control Register 2: Configures clock frequency, interrupts, DMA
    volatile uint32_t I2C_OAR1;   // Own Address Register 1: Stores the primary I2C address of the device
    volatile uint32_t I2C_OAR2;   // Own Address Register 2: Stores the secondary address (if used)
    volatile uint32_t I2C_DR;     // Data Register: Holds data for transmission and reception
    volatile uint32_t I2C_SR1;    // Status Register 1: Contains event flags (e.g., Start, Address Match, Data Ready)
    volatile uint32_t I2C_SR2;    // Status Register 2: Contains additional status flags (e.g., busy, master/slave mode)
    volatile uint32_t I2C_CCR;    // Clock Control Register: Defines SCL clock speed (Standard/Fast mode)
    volatile uint32_t I2C_TRISE;  // TRISE Register: Configures the maximum allowed rise time of SCL
} I2C_TypeDef;


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
//USART
#define USART1							((USART_TypeDef *)USART1_BASE)
#define USART2							((USART_TypeDef *)USART2_BASE)
#define USART3							((USART_TypeDef *)USART3_BASE)
//SPI
#define SPI1							((SPI_TypeDef *)SPI1_BASE)
#define SPI2							((SPI_TypeDef *)SPI2_BASE)
//I2C
#define I2C1							((I2C_TypeDef*)I2C1_BASE)
#define I2C2							((I2C_TypeDef*)I2C2_BASE)

/*---------------------------------------------------------------------------------------------------------------------------*/
//Clock Enable/Disable Macros:
/*---------------------------------------------------------------------------------------------------------------------------*/

//clock enable fo GPIO
#define RCC_GPIOA_CLK_EN() 				(RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_EN() 				(RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_EN() 				(RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_EN() 				(RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_EN() 				(RCC->APB2ENR |= (1<<6))

//clock enable for AFIO
#define RCC_AFIO_CLK_EN() 				(RCC->APB2ENR |= (1<<0))

/*USART*/
//clock enable for USART
#define RCC_USART1_CLK_EN() 				(RCC->APB2ENR |= (1<<14))
#define RCC_USART2_CLK_EN() 				(RCC->APB1ENR |= (1<<17))
#define RCC_USART3_CLK_EN() 				(RCC->APB1ENR |= (1<<18))

//clock disable(reset) for USART
#define RCC_USART1_RESET() 					(RCC->APB2RSTR |= (1<<14))
#define RCC_USART2_RESET() 					(RCC->APB1RSTR |= (1<<17))
#define RCC_USART3_RESET() 					(RCC->APB1RSTR |= (1<<18))

/*SPI*/
//clock enable for SPI
#define RCC_SPI1_CLK_EN() 				    (RCC->APB2ENR |= (1<<12))
#define RCC_SPI2_CLK_EN() 					(RCC->APB1ENR |= (1<<14))


//clock disable(reset) for SPI
#define RCC_SPI1_RESET() 					(RCC->APB2RSTR |= (1<<12))
#define RCC_SPI2_RESET() 					(RCC->APB1RSTR |= (1<<14))

/*I2C*/
//clock enable for I2C
#define RCC_I2C1_CLK_EN() 				    (RCC->APB1ENR |= (1<<21))
#define RCC_I2C2_CLK_EN() 					(RCC->APB1ENR |= (1<<22))


//clock disable(reset) for I2C
#define RCC_I2C1_RESET() 					(RCC->APB1RSTR |= (1<<21))
#define RCC_I2C2_RESET() 					(RCC->APB1RSTR |= (1<<22))


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

//USART
#define USART1_IRQ						37
#define USART2_IRQ						38
#define USART3_IRQ						39

//SPI
#define SPI1_IRQ						35
#define SPI2_IRQ						36

//I2C
#define I2C1_EV_IRQ						31
#define I2C1_ER_IRQ						32
#define I2C2_EV_IRQ						33
#define I2C2_ER_IRQ						34
/*---------------------------------------------------------------------------------------------------------------------------*/
// NVIC IRQ Enable/Disable macros
/*---------------------------------------------------------------------------------------------------------------------------*/
/*EXTI*/
//ENABLE
#define NVIC_IRQ6_EXTI0_Enable           (NVIC_ISER0 |= (1<<6)) //EXTI0 → IRQ6 → NVIC enables bit 6 → CPU jumps to EXTI0_IRQHandler()
#define NVIC_IRQ7_EXTI1_Enable           (NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_Enable           (NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_Enable           (NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_Enable          (NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_to_9_Enable     (NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_to_15_Enable   (NVIC_ISER1 |= (1<<8)) //40-32=8
//DISABLE
#define NVIC_IRQ6_EXTI0_disable          (NVIC_ICER0 |= (1<<6)) //NVIC_ICER0 disable interrupt by setting one in it
#define NVIC_IRQ7_EXTI1_disable          (NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_disable          (NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_disable          (NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_disable         (NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_to_9_disable    (NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ40_EXTI10_to_15_disable  (NVIC_ICER1 |= (1<<8)) //40-32=8

/*USART*/
//ENABLE
#define NVIC_IRQ37_USART1_Enable   (NVIC_ISER1 |= (1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_Enable   (NVIC_ISER1 |= (1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_Enable   (NVIC_ISER1 |= (1<<(USART3_IRQ-32)))
//DISABLE
#define NVIC_IRQ37_USART1_RESET    (NVIC_ICER1 |= (1<<(USART1_IRQ-32)))
#define NVIC_IRQ38_USART2_RESET    (NVIC_ICER1 |= (1<<(USART2_IRQ-32)))
#define NVIC_IRQ39_USART3_RESET    (NVIC_ICER1 |= (1<<(USART3_IRQ-32)))

/*SPI*/
//ENABLE
#define NVIC_IRQ35_SPI1_Enable     (NVIC_ISER1 |= (1<<(SPI1_IRQ-32)))
#define NVIC_IRQ36_SPI2_Enable     (NVIC_ISER1 |= (1<<(SPI2_IRQ-32)))
//DISABLE
#define NVIC_IRQ35_SPI1_RESET    (NVIC_ICER1 |= (1<<(SPI1_IRQ-32)))
#define NVIC_IRQ36_SPI2_RESET    (NVIC_ICER1 |= (1<<(SPI2_IRQ-32)))

/*SPI*/
//ENABLE
#define NVIC_IRQ31_I2C1_EV_Enable     (NVIC_ISER0 |= (1<<(I2C1_EV_IRQ)))
#define NVIC_IRQ32_I2C1_ER_Enable     (NVIC_ISER1 |= (1<<(I2C1_ER_IRQ-32)))
#define NVIC_IRQ33_I2C2_EV_Enable     (NVIC_ISER1 |= (1<<(I2C2_EV_IRQ-32)))
#define NVIC_IRQ34_I2C2_ER_Enable     (NVIC_ISER1 |= (1<<(I2C2_ER_IRQ-32)))
//DISABLE
#define NVIC_IRQ31_I2C1_EV_RESET     (NVIC_ICER0 |= (1<<(I2C1_EV_IRQ)))
#define NVIC_IRQ32_I2C1_ER_RESET     (NVIC_ICER1 |= (1<<(I2C1_ER_IRQ-32)))
#define NVIC_IRQ33_I2C2_EV_RESET     (NVIC_ICER1 |= (1<<(I2C2_EV_IRQ-32)))
#define NVIC_IRQ34_I2C2_ER_RESET     (NVIC_ICER1 |= (1<<(I2C2_ER_IRQ-32)))



/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition for I2C ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */

#endif /* INCLUDES_STM32F103X6_H_ */
