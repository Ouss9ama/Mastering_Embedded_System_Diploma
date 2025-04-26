/*
 * usart_driver.h
 *
 *  Created on: Feb 21, 2025
 *      Author: oussa
 */

#ifndef MCAL_INCLUDE_USART_DRIVER_H_
#define MCAL_INCLUDE_USART_DRIVER_H_

#include "STM32F103x6.h"
#include "rcc_driver.h"
#include "gpio_driver.h"

//configuration structure
typedef struct
{	//this parametre need to be set  based  on @ref UART_MODE_DEFINE
	uint8_t  	USART_MODE; //specifies TX/RX Enable/Disable
	//this parametre need to be set  based  on @ref UART_BaudeRate_DEFINE
	uint32_t 	BaudeRate;//specifies the uart communication bauderate
	//this parametre need to be set  based  on @ref UART_PAYLOAD_LENGTH_DEFINE
	uint8_t		Payload_Length;//specifies the nbr of data bits need to be transferred
	//this parametre need to be set  based  on @ref UART_Parity_DEFINE
	uint8_t     Parity; //specifies the parity mode
	//this parametre need to be set  based  on @ref UART_Stopbits_DEFINE
	uint8_t     Stopbits;//specifies the number of stop bits
	//this parametre need to be set  based  on @ref UART_HW_FLOW_CTRL_DEFINE
	uint8_t     HW_Flow_ctrl; //specifies wether the HW FLOW CONTROL  is enabled or not
	//this parametre need to be set  based  on @ref UART_IRQ_ENABLE_DEFINE
	uint8_t     IRQ_Enable; //enable or disable UART IRQ

	void (*P_IRQ_CALLBACK)(void);
}UART_Config;

/********************************************************************************************************************************************/
                                           /*MACROS CONFIG REFERENCE*/
/********************************************************************************************************************************************/
//@ref UART_MODE_DEFINE
#define UART_MODE_RX							(uint32_t)(1<<2) //Bit 2 RE: Receiver enable
#define UART_MODE_TX							(uint32_t)(1<<3) //Bit 3 TE: Transmitter enable
#define UART_MODE_TX_RX							((uint32_t)(1<<3 | 1<<2))

//@ref UART_BaudeRate_DEFINE
#define UART_BAUDRATE_2400						2400
#define UART_BAUDRATE_9600						9600
#define UART_BAUDRATE_19200						19200
#define UART_BAUDRATE_57600						57600
#define UART_BAUDRATE_115200					115200
#define UART_BAUDRATE_230400					230400
#define UART_BAUDRATE_460800					460800
#define UART_BAUDRATE_921600					921600
#define UART_BAUDRATE_2250000					2250000
#define UART_BAUDRATE_4500000					4500000

//@ref UART_PAYLOAD_LENGTH_DEFINE
#define UART_PAYLOAD_LENGTH_8B					(uint32_t)(0) //Bit 12 M: Word length
#define UART_PAYLOAD_LENGTH_9B					(uint32_t)(1<<12) //Bit 12 M: Word length

//@ref UART_Parity_DEFINE
#define UART_Parity_NONE						(uint32_t)(0)
#define UART_Parity_EVEN						(uint32_t)(1<<10)
#define UART_Parity_ODD							(uint32_t)(1<<10 | 1<<9)

//@ref UART_Stopbits_DEFINE
#define UART_StopBits_half						(uint32_t)(1<<12)
#define UART_StopBits_1							(uint32_t)(0)
#define UART_StopBits_1_half					(uint32_t)(3<<12) //(0b11 << 12)
#define UART_StopBits_2							(uint32_t)(2<<12)

//@ref UART_HW_FLOW_CTRL_DEFINE
#define UART_HW_FLOW_CTRL_NONE					(uint32_t)(0)
#define UART_HW_FLOW_CTRL_RTS					(uint32_t)(1<<8)
#define UART_HW_FLOW_CTRL_CTS					(uint32_t)(1<<9)
#define UART_HW_FLOW_CTRL_RTS_CTS				((uint32_t)(1<<8 | 1<<9))

//@ref UART_IRQ_ENABLE_DEFINE
#define UART_IRQ_ENABLE_NONE					(uint32_t)(0)
#define UART_IRQ_ENABLE_TXE						(uint32_t)(1<<7)//Transmit data register empty
#define UART_IRQ_ENABLE_TC						(uint32_t)(1<<6)//Transmit complete
#define UART_IRQ_ENABLE_RXNEIE					(uint32_t)(1<<5)//Recieved data ready to be read & overrun detected
#define UART_IRQ_ENABLE_PE						(uint32_t)(1<<8)//parity error


enum Polling_mechism{
	enable,
	disable
};

/*/BAUDERATE CALCULATION*/
//USARTDIV = FCLK / (16 * BAUDERATE)
//USARTDIV_MULTI100 = uint32_t((100 * FCLK) / (16 * BAUDERATE))  == (25 * FCLK)/ (4*BAUDERATE)
//DIV_Mantissa_multip100 = integer part (USARTDIV * 100)
//DIV_Mantissa = integer part (USARTDIV)
//DIV_fraction = ((USARTDIV_MULTI100 - DIV_Mantissa_multip100) *16) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MLTP100(_PCLK_, _BAUD_)					(uint32_t)((25*_PCLK_)/(4 * _BAUD_))
#define MANTISSA_MLTP100(_PCLK_, _BAUD_)					(uint32_t)( USARTDIV(_PCLK_, _BAUD_) * 100)
#define MANTISSA(_PCLK_, _BAUD_)							(uint32_t)( USARTDIV(_PCLK_, _BAUD_))
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t)(((USARTDIV_MLTP100(_PCLK_, _BAUD_) - MANTISSA_MLTP100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_REGISTER(_PCLK_, _BAUD_)					((MANTISSA(_PCLK_, _BAUD_)) << 4) | ((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF)


/*********************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Supported by "MCAL GPIO DRIVER"
 * =================================================================================================================
 */
/*******************************************************************************************************************************/

void MCAL_UART_INIT (USART_TypeDef* USARTx, UART_Config* UART_Config);
void MCAL_UART_DeINIT (USART_TypeDef* USARTx);
void MCAL_UART_GPIO_SET_PINS(USART_TypeDef* USARTx);
void MCAL_UART_SEND_DATA(USART_TypeDef* USARTx,uint16_t* ptxBuffer, enum Polling_mechism PollingEN);
void MCAL_UART_RECIEVE_DATA(USART_TypeDef* USARTx,uint16_t* ptxBuffer, enum Polling_mechism PollingEN);
void MCAL_UART_WAIT_TC(USART_TypeDef * USARTx);
#endif /* MCAL_INCLUDE_USART_DRIVER_H_ */
