/*
 * spi_driver.h
 *
 *  Created on: Feb 26, 2025
 *      Author: oussa
 */

#ifndef MCAL_INCLUDE_SPI_DRIVER_H_
#define MCAL_INCLUDE_SPI_DRIVER_H_

/********************************************************************************************************************************************/
/*INCLUDES*/
/********************************************************************************************************************************************/

#include "STM32F103x6.h"
#include "gpio_driver.h"
#include "rcc_driver.h"

/********************************************************************************************************************************************/
/*CONFIG STRUCTURES*/
/********************************************************************************************************************************************/
struct S_IRQ_SRC{
	uint8_t TXE:1; //"TX buffer Empty" interrupt
	uint8_t RXNE:1; //"RX buffer not empty" interrupt
	uint8_t ERRI:1; //"Error Interrupt"
	uint8_t Reserved:5;
};


typedef struct {
	uint16_t Device_Mode;         //Defines whether the SPI operates as a Master or Slave.@ref SPI_Device_Mode
	uint16_t Communication_Mode;  //Configures whether SPI is full-duplex, half-duplex, or simplex (receive only). @ref SPI_Communication_Mode
	uint16_t Frame_Format;		  //Determines whether data is transmitted LSB first or MSB first @ref SPI_Frame_Format
	uint16_t Data_Size;		  	  //Defines the size of each data frame (8-bit or 16-bit) @ref SPI_Data_Size
	uint16_t CLK_Polarity;		  //Specifies whether the clock (SCK) is idle high (CPOL=1) or idle low (CPOL=0). @ref SPI_CLK_Polarity
	uint16_t CLK_Phase;		      //Defines when the data is sampled (on the first or second clock edge @ref SPI_CLK_Phase
	uint16_t NSS;		          //Determines if the NSS (Slave Select) is controlled by software (SW) or hardware (HW) @ref SPI_NSS
	uint16_t SPI_BR_Prescaler;	  //Sets the baud rate prescaler, which affects the SPI clock speed @ref SPI_SPI_BR_Prescaler, only the clock of the master need to be set because it is the one deriving the communication
	uint16_t IRQ_ENABLE;          //@ref SPI_IRQ_Enable

	void(*P_IRQ_CallBack)(struct S_IRQ_SRC irq_src);     // function that will be called when SPI interrupt happens

}SPI_CONFIG;




/********************************************************************************************************************************************/
/*MACROS CONFIG REFERENCE*/
/********************************************************************************************************************************************/

/**************@ref SPI_Device_Mode******************/
#define SPI_Devide_Mode_Slave          	   		 (0x00000000U)	// SPI operates in Slave mode (MSTR = 0)
#define SPI_Devide_Mode_Master           		 (0x1U<<2) 		// Configure bit 2 (MSTR) in CR1 register to set SPI as Master

/**************@ref SPI_Communication_Mode********************/
#define SPI_Direction_2lines			 		 (0x00000000U)		// SPI Full-Duplex mode (2 lines for Tx and Rx)
#define SPI_Direction_2lines_RXONLY			 	 (0x1U << 10)		// Bit 10 (RXONLY) in CR1: Enables Receive-only mode in Full-Duplex
#define SPI_Direction_1lines_Recieve_Only	 	 (0x1U << 15)		// Bit 15 (BIDIMODE) in CR1: Enables 1-line Bidirectional mode, Receive-only
#define SPI_Direction_1lines_Transmit_Only		 ((0x1U << 15) | (0x1U << 14))	// Bit 15 (BIDIMODE) enables 1-line Bidirectional mode,
																			//Bit 14 (BIDIOE) enables Output enable (Transmit-only)
/*************@ref SPI_Frame_Format******************/
#define SPI_Frame_Format_MSB_Transmitted_first   (0x00000000U)  //Configures SPI to transmit MSB (Most Significant Bit) first (bit 7 = 0 in CR1)
#define SPI_Frame_Format_LSB_Transmitted_first   (0x1U << 7)  //Configures SPI to transmit LSB (Least Significant Bit) first (bit 7 = 1 in CR1)

/***********@ref SPI_Data_Size********************/
#define SPI_DataSize_8bit					     (0x00000000U) // Configures SPI to use 8-bit data frame format (bit 11 (DFF) = 0 in CR1)
#define SPI_DataSize_16bit					     (0x1U << 11)  // Configures SPI to use 16-bit data frame format (bit 11 (DFF) = 1 in CR1)

/************@ref SPI_CLK_Polarity**************/
#define SPI_CLK_Polarity_Low_Idle				(0x00000000U) //Clock polarity (CPOL = 0): SCK is low when idle
#define SPI_CLK_Polarity_High_Idle              (0x1U << 1)   //Clock polarity (CPOL = 1): SCK is high when idle

/*********@ref SPI_CLK_Phase********************/
#define SPI_CLK_Phase_1Edge_data_capture		(0x00000000U) //Clock Phase (CPHA = 0): Data is captured on the first clock transition
#define SPI_CLK_Phase_2Edge_data_capture		 (0x1U << 1)  //Clock Phase (CPHA = 1): Data is captured on the second clock transition

/*******@ref SPI_NSS************/
//Hardware NSS management (controlled by hardware)
#define SPI_NSS_HW_Slave						(0x00000000U) // NSS pin is managed by hardware in slave mode
#define SPI_NSS_HW_Master_SS_OUT_EN				(0x1U << 2)   //Set SSOE (bit 2) to enable SS output in master mode
#define SPI_NSS_HW_Master_SS_OUT_DISABLE		~(0x1U << 2) // SS output is disabled in master mode (default)
// Software NSS management (controlled by software, used in master or slave mode)
#define SPI_NSS_SW_Slave_RESET					(0x1U << 9) // Set SSI (bit 9) to 0: NSS is LOW (slave mode active)
#define SPI_NSS_SW_Slave_SET					((0x1U << 9) | (0x1U << 8))// Set SSI (bit 9) and SSM (bit 8) to 1: NSS is HIGH (slave mode inactive)

/******@ref SPI_SPI_BR_Prescaler*************/
// These values configure the SPI baud rate prescaler (Bits 5:3 BR[2:0] in CR1 register)
// SPI clock = PCLK / Prescaler_Value
#define SPI_SPI_BR_Prescaler_2                   (0x00000000U)  // Baud rate prescaler = 2  (PCLK/2)
#define SPI_SPI_BR_Prescaler_4                   (0b001U << 3)   // Baud rate prescaler = 4  (PCLK/4)
#define SPI_SPI_BR_Prescaler_8                   (0b010U << 3)   // Baud rate prescaler = 8  (PCLK/8)
#define SPI_SPI_BR_Prescaler_16                  (0b011U << 3)   // Baud rate prescaler = 16 (PCLK/16)
#define SPI_SPI_BR_Prescaler_32                  (0b100U << 3)   // Baud rate prescaler = 32 (PCLK/32)
#define SPI_SPI_BR_Prescaler_64                  (0b101U << 3)   // Baud rate prescaler = 64 (PCLK/64)
#define SPI_SPI_BR_Prescaler_128                 (0b110U << 3)   // Baud rate prescaler = 128 (PCLK/128)
#define SPI_SPI_BR_Prescaler_256                 (0b111U << 3)   // Baud rate prescaler = 256 (PCLK/256)

/**********@ref SPI_IRQ_Enable****************/
// These values configure the SPI interrupt enable bits in the SPI_CR2 register.

#define SPI_IRQ_Enable_NONE						 (uint32_t)(0)   //No interrupt enabled

// This interrupt is triggered when the TXE flag is set, meaning the transmit buffer is empty.
#define SPI_IRQ_Enable_TXEIE					 (uint32_t)(1 << 7) //TXEIE: Transmit buffer empty interrupt enable (Bit 7 in SPI_CR2)

// This interrupt is triggered when the RXNE flag is set, indicating that data has been received and is ready to be read.
#define SPI_IRQ_Enable_RXNEIE					 (uint32_t)(1 << 6) // RXNEIE: Receive buffer not empty interrupt enable (Bit 6 in SPI_CR2)

// This interrupt is triggered when an error occurs, such as an overrun, mode fault, or CRC error.
#define SPI_IRQ_Enable_ERRIE					 (uint32_t)(1 << 5) // ERRIE: Error interrupt enable (Bit 5 in SPI_CR2)


enum PollingMechanism_spi{
	Polling_EN,
	Polling_DISABLE
};




/*********************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Supported by "MCAL GPIO DRIVER"
 * =================================================================================================================
 */
/*******************************************************************************************************************************/
void MCAL_SPI_INIT (SPI_TypeDef* SPIx, SPI_CONFIG* SPI_Config);
void MCAL_SPI_DeINIT (SPI_TypeDef* SPIx);
void MCAL_SPI_GPIO_SET_PINS(SPI_TypeDef* SPIx);
void MCAL_SPI_SEND_DATA(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN);
void MCAL_SPI_RECIEVE_DATA(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN);
void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN);

#endif /* MCAL_INCLUDE_SPI_DRIVER_H_ */
