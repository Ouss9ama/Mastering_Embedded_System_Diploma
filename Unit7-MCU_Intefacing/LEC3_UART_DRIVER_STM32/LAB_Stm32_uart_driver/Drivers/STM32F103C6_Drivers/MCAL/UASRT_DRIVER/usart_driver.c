/*
 * usart_driver.c
 *
 *  Created on: Feb 21, 2025
 *      Author: oussa
 */


#include "usart_driver.h"




/********************************************************************************************************************************************/
/*GENERIC VARIABLES*/
/********************************************************************************************************************************************/

UART_Config* Global_UART_Config = NULL;



/********************************************************************************************************************************************/
/*GENERIC FUNCTIONS*/
/********************************************************************************************************************************************/





/*********************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Functions Defintion
 * =================================================================================================================
 */
/*******************************************************************************************************************************/


/*========================================================================================================================================
 * @Fn			 : MCAL_UART_INIT
 * @brief		 : Initailzes UART (Asynchronouns only)
 * @param [in]  : USARTx: where x can be (1..3 depending on device used)
 * @param [in]  : UART_config (All uart configuration UART_Config
 * @retval 	 :  NONE
 * Note		 : CLOCK 8 MHZ
  ========================================================================================================================================*/
void MCAL_UART_INIT (USART_TypeDef* USARTx, UART_Config* UART_Config)
{
	uint32_t pclk, BRR;
	Global_UART_Config = UART_Config;

	//Enable the clock for the given USART
	if(USARTx == USART1)
		RCC_USART1_CLK_EN();

	else if(USARTx == USART2)
		RCC_USART2_CLK_EN();

	else if(USARTx == USART3)
		RCC_USART3_CLK_EN();

	//Enable the USART MODULE
	USARTx->USART_CR1 |= (1<<13);//Bit 13 UE: USART enable

	//Enable USART TX & RX engines according  to the USART_Mode configuration item
	USARTx->USART_CR1 |= UART_Config->USART_MODE;//Bit 3 TE: Transmitter enable  Bit 2 RE: Receiver enable

	//payload width
	USARTx->USART_CR1 |= UART_Config->Payload_Length;//Bit 12 M: Word length

	//parity configuration
	USARTx->USART_CR1 = UART_Config->Parity; //Bit 10 PCE: Parity control enable & Bit 9 PS: Parity selection

	//stopbits configuartion
	USARTx->USART_CR2 = UART_Config->Stopbits; //Bits 13:12 STOP: STOP bits

	//Flow contorl configuration
	USARTx->USART_CR3 = UART_Config->HW_Flow_ctrl;//Bit 9 CTSE: CTS enable & Bit 8 RTSE: RTS enable


	//Configuration of BRR(BaudeRate Register)
	//PLCLK1 for usart2,3
	//PLCLK2 for USART1

	if (USARTx == USART1)
	{
		pclk = MCAL_RCC_get_PCLK2_FREQUENCY();
	}
	else
	{
		pclk = MCAL_RCC_get_PCLK1_FREQUENCY();
	}
	BRR = UART_BRR_REGISTER(pclk,UART_Config->BaudeRate);
	USARTx->USART_BRR = BRR;

	//Enable / disable the interrupt
	//USART_CR1
	if (UART_Config->IRQ_Enable != UART_IRQ_ENABLE_NONE)
	{
		USARTx->USART_CR1 |=(UART_Config->IRQ_Enable);
		//Enable NVIC interrupt for USARTx IRQ
		if(USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
		else if(USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}
}

void MCAL_UART_DeINIT (USART_TypeDef* USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_RESET();
		NVIC_IRQ37_USART1_RESET;
	}
	else if(USARTx == USART2)
	{
		RCC_USART2_RESET();
		NVIC_IRQ38_USART2_RESET;
	}
	else if(USARTx == USART3)
	{
		RCC_USART3_RESET();
		NVIC_IRQ39_USART3_RESET;
	}
}



void MCAL_UART_SEND_DATA(USART_TypeDef* USARTx,uint16_t* ptxBuffer, enum Polling_mechism PollingEN)
{
	//wait untill TXE flag is set in the ISR
	if (PollingEN == enable)
	while(!(USARTx->USART_SR & (1<<7)));

	//check if the USART word length item is 8 bit or 9 bit

	if(Global_UART_Config->Payload_Length ==  UART_PAYLOAD_LENGTH_9B)
	{
		USARTx->USART_DR = (*ptxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		USARTx->USART_DR = (*ptxBuffer & (uint8_t)0xFF);
	}
}

void MCAL_UART_WAIT_TC(USART_TypeDef * USARTx)
{
	//wait till TC falg is set in the SR
	while(!(USARTx->USART_SR & 1<<6));

}


void MCAL_UART_RECIEVE_DATA(USART_TypeDef* USARTx,uint16_t* ptxBuffer, enum Polling_mechism PollingEN)
{
	//wait until RXNE flag is set in the SR
	if (PollingEN == enable)
	{
		while(!(USARTx->USART_SR & (1 << 5)));
	}
	//check if the USART word length item is 8 bit or 9 bit
	if(Global_UART_Config->Payload_Length == UART_PAYLOAD_LENGTH_9B)
	{
		if(Global_UART_Config->Parity == UART_Parity_NONE)
		{
			//no parity, all 9bit are data
			*((uint16_t*)ptxBuffer) = USARTx->USART_DR;
		}
		else
		{	//8bit are data, 1 bit is parity
			*((uint16_t*)ptxBuffer) = (USARTx->USART_DR & (uint8_t)0xFF);
		}
	}
	else
	{
		if(Global_UART_Config->Parity == UART_Parity_NONE)
		{
			//no parity, all 8bit are data
			*((uint16_t*)ptxBuffer) = (USARTx->USART_DR & (uint8_t)0xFF);
		}
		else
		{	//7 bit is data, 1 bit is parity
			*((uint16_t*)ptxBuffer) = (USARTx->USART_DR & (uint8_t)0x7F);
		}
	}
}


void MCAL_UART_GPIO_SET_PINS(USART_TypeDef* USARTx)
{
	GPIO_PinConfig_t PinCfg;
	if(USARTx == USART1)
	{
		//PA9 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_9;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		//PA10 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_CTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PA11 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_11;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PA12 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_12;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}

	if(USARTx == USART2)
	{
		//PA2 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOA, &PinCfg);
		//PA3 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &PinCfg);

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_CTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PA0 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_0;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PA1 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_1;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);
		}
	}

	if(USARTx == USART3)
	{
		//PB10 TX
		PinCfg.GPIO_PinNumber = GPIO_PIN_10;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(GPIOB, &PinCfg);
		//PB11 RX
		PinCfg.GPIO_PinNumber = GPIO_PIN_11;
		PinCfg.GPIO_MODE = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &PinCfg);

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_CTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PB13 CTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}

		if(Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS || Global_UART_Config->HW_Flow_ctrl == UART_HW_FLOW_CTRL_RTS_CTS)
		{
			//PB14 RTS
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);
		}
	}

}


//ISR
void USART1_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CALLBACK();
}

void USART2_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CALLBACK();
}

void USART3_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CALLBACK();
}

