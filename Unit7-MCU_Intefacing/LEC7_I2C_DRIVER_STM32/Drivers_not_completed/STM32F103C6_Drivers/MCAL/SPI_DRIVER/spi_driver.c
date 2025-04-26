/*
 * spi_driver.c
 *
 *  Created on: Feb 26, 2025
 *      Author: oussa
 */


/********************************************************************************************************************************************/
/*INCLUDES*/
/********************************************************************************************************************************************/

#include "STM32F103x6.h"
#include "rcc_driver.h"
#include "gpio_driver.h"
#include "spi_driver.h"


/********************************************************************************************************************************************/
/*GENERIC VARIABLES*/
/********************************************************************************************************************************************/
SPI_CONFIG* GLOBAL_SPI_config[2] = {NULL,NULL};
SPI_CONFIG GLOBAL_SPI_config1;
SPI_CONFIG GLOBAL_SPI_config2;


/********************************************************************************************************************************************/
/*GENERIC MACROS*/
/********************************************************************************************************************************************/
#define SPI1_INDEX			0
#define SPI2_INDEX			1

#define SPI_SR_TXE             ((uint8_t)0x02) // Transmit buffer empty flag (bit 1)
#define SPI_SR_RXNE            ((uint8_t)0x01) // Receive buffer not empty flag (bit 0)

/*********************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Functions Defintion
 * =================================================================================================================
 */
/*******************************************************************************************************************************/


/*========================================================================================================================================
 * @Fn           : MCAL_SPI_INIT
 * @brief        : Initializes the SPI peripheral with user-defined configurations.
 * @param [in]   : SPIx - Specifies the SPI peripheral (SPI1 or SPI2).
 * @param [in]   : SPI_Config - Pointer to a configuration structure that contains:
 *                   - @ref SPI_Device_Mode (Master/Slave mode selection)
 *                   - @ref SPI_Communication_Mode (Full Duplex, Half Duplex, or Simplex)
 *                   - @ref SPI_Frame_Format (MSB First or LSB First)
 *                   - @ref SPI_DataSize (8-bit or 16-bit data frame)
 *                   - @ref SPI_CLK_Polarity (Clock Polarity: Idle Low or High)
 *                   - @ref SPI_CLK_Phase (Clock Phase: 1st or 2nd Edge Sampling)
 *                   - @ref SPI_NSS (Software or Hardware NSS Management)
 *                   - @ref SPI_BR_Prescaler (Baud Rate Prescaler)
 *                   - @ref SPI_IRQ_Enable (Enable or Disable SPI Interrupts)
 * @retval       : None
 * @note         : - This function enables the SPI peripheral clock before configuration.
 *                 - The function configures SPIx->CR1 and SPIx->CR2 registers based on user settings.
 *                 - If hardware NSS is enabled in Master mode, it is configured in CR2.
 *                 - If an interrupt is enabled, the corresponding NVIC IRQ is also enabled.
 ========================================================================================================================================*/

void MCAL_SPI_INIT (SPI_TypeDef* SPIx, SPI_CONFIG* SPI_Config)
{
	//safety for registers
	uint16_t temp_reg_CR1 = 0;
	uint16_t temp_reg_CR2 = 0;

	if(SPIx == SPI1)
	{	GLOBAL_SPI_config1 = *SPI_Config;
		GLOBAL_SPI_config[SPI1_INDEX]= &GLOBAL_SPI_config1;
		RCC_SPI1_CLK_EN();
	}
	else if (SPIx == SPI2)
	{	GLOBAL_SPI_config2 = *SPI_Config;
		GLOBAL_SPI_config[SPI2_INDEX]= &GLOBAL_SPI_config2;
		RCC_SPI2_CLK_EN();
	}

	//Enable SPI (CR1:BIT 6  SPE:SPI ENABLE)
	temp_reg_CR1 = (0x1U << 6);

	//MASTER or slave
	temp_reg_CR1 |= SPI_Config->Device_Mode;

	//SPI_COMMUNICATION MODE (FULL-duplex, half-duplex, or simplex)
	temp_reg_CR1 |= SPI_Config->Communication_Mode;

	//SPI_Frame_Format (LSB first or MSB first)
	temp_reg_CR1 |= SPI_Config->Frame_Format;

	//SPI_Data_Size (8-bit or 16-bit)
	temp_reg_CR1 |= SPI_Config->Data_Size;

	//SPI_CLK_Polarity
	temp_reg_CR1 |= SPI_Config->CLK_Polarity;

	//SPI_CLK_Phase
	temp_reg_CR1 |= SPI_Config->CLK_Phase;

	//***********NSS*****************//
	if(SPI_Config->NSS == SPI_NSS_HW_Master_SS_OUT_EN)
	{
		temp_reg_CR2 |= SPI_Config->NSS;

	}else if(SPI_Config->NSS == SPI_NSS_HW_Master_SS_OUT_DISABLE)
	{
		temp_reg_CR2 &= SPI_Config->NSS;
	}else
	{
		temp_reg_CR1 |= SPI_Config->NSS;
	}

	//baudrate prescaler
	temp_reg_CR1 |= SPI_Config->SPI_BR_Prescaler;

	//interrupt
	if(SPI_Config->IRQ_ENABLE != SPI_IRQ_Enable_NONE)
	{
		//SPI_IRQ_ENABLE
		temp_reg_CR2 |=SPI_Config->IRQ_ENABLE;

		if(SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_Enable;
		}
		else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}
	}


	SPIx->SPI_CR1 = temp_reg_CR1;
	SPIx->SPI_CR2 = temp_reg_CR2;
}

/*========================================================================================================================================
 * @Fn           : MCAL_SPI_DeINIT
 * @brief        : Deinitializes the SPI peripheral and resets its configuration.
 * @param [in]   : SPIx - Specifies the SPI peripheral (SPI1 or SPI2) to be deinitialized.
 * @retval       : None
 * @note         : - This function resets the SPI peripheral and disables its interrupt in the NVIC.
 *                 - It restores the default state of the SPI peripheral by resetting its clock and IRQ settings.
 ========================================================================================================================================*/

void MCAL_SPI_DeINIT (SPI_TypeDef* SPIx)
{
	if(SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_RESET; // Disable SPI1 interrupt in NVIC
		RCC_SPI1_RESET(); //Reset SPI1 clock and registers

	}else if (SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_RESET;  // Disable SPI2 interrupt in NVIC
		RCC_SPI2_RESET(); //Reset SPI2 clock and registers
	}
}

/*========================================================================================================================================
 * @Fn          : MCAL_SPI_SEND_DATA
 * @brief       : Sends data over SPI in full-duplex mode
 * @param [in]  : SPIx       - Specifies the SPI instance (SPI1, SPI2, etc.).
 * @param [in]  : ptxBuffer  - Pointer to the buffer containing the data to be transmitted.
 * @param [in]  : PollingEN  - Specifies whether to enable polling mechanism (@ref PollingMechanism_spi).
 * @retval      : None
 * Note         : - Assumes full-duplex mode (simultaneous transmit & receive).
 *               - Polling mechanism waits for TXE (Transmit Buffer Empty) flag before sending data.
 ========================================================================================================================================*/

void MCAL_SPI_SEND_DATA(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN)
{

	if(PollingEN == Polling_EN)
	{
		// Wait until the Transmit Buffer is Empty (TXE flag set)
		while (!((SPIx->SPI_SR &SPI_SR_TXE)));
	}
	// Load the data into the SPI Data Register to transmit
	SPIx->SPI_DR = *ptxBuffer;
}

/*========================================================================================================================================
 * @Fn          : MCAL_SPI_RECIEVE_DATA
 * @brief       : Receives data over SPI in full-duplex mode
 * @param [in]  : SPIx       - Specifies the SPI instance (SPI1, SPI2, etc.).
 * @param [out] : ptxBuffer  - Pointer to the buffer where the received data will be stored.
 * @param [in]  : PollingEN  - Specifies whether to enable polling mechanism (@ref PollingMechanism_spi).
 * @retval      : None
 * Note         : - Assumes full-duplex mode (simultaneous transmit & receive).
 *               - Polling mechanism waits for RXNE (Receive Buffer Not Empty) flag.
 ========================================================================================================================================*/
void MCAL_SPI_RECIEVE_DATA(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN)
{

	if(PollingEN == Polling_EN)
	{
		// Wait until data is received
		while (!((SPIx->SPI_SR &SPI_SR_RXNE)));
	}
	// Read received data into buffer
	*ptxBuffer = SPIx->SPI_DR;
}

/*========================================================================================================================================
 * @Fn          : MCAL_SPI_TX_RX
 * @brief       : Transmit and Receive data over SPI in full-duplex mode
 * @param [in]  : SPIx       - Specifies the SPI instance (SPI1, SPI2, etc.).
 * @param [in]  : ptxBuffer  - Pointer to the buffer containing the data to be transmitted and to store received data.
 * @param [in]  : PollingEN  - Specifies whether to enable polling mechanism (@ref PollingMechanism_spi).
 * @retval      : None
 * Note         : - Assumes full-duplex mode (simultaneous transmit & receive).
 *               - Polling mechanism waits for TXE (Transmit Buffer Empty) and RXNE (Receive Buffer Not Empty) flags.
 ========================================================================================================================================*/
void MCAL_SPI_TX_RX(SPI_TypeDef* SPIx,uint16_t* ptxBuffer, enum PollingMechanism_spi PollingEN)
{

	if(PollingEN == Polling_EN)
	{
		// Wait until the Transmit Buffer is Empty (TXE flag set)
		while (!((SPIx->SPI_SR &SPI_SR_TXE)));
	}
	// Load the data into the SPI Data Register to transmit
	SPIx->SPI_DR = *ptxBuffer;

	if(PollingEN == Polling_EN)
	{
		// Wait until data is received
		while (!((SPIx->SPI_SR &SPI_SR_RXNE)));
	}
	// Read received data into buffer
	*ptxBuffer = SPIx->SPI_DR;
}

void MCAL_SPI_GPIO_SET_PINS(SPI_TypeDef* SPIx)
{
	GPIO_PinConfig_t PinCfg;
	if(SPIx == SPI1)
	{
		//PA4 :SPI1_NSS
		//PA5 :SPI1_SCK
		//PA6 :SPI1_MISO
		//PA7 :SPI1_MOSI
		if(GLOBAL_SPI_config[SPI1_INDEX]->Device_Mode == SPI_Devide_Mode_Master)
		{
			//PA4 :SPI1_NSS
			switch(GLOBAL_SPI_config[SPI1_INDEX]->NSS)
			{

			case SPI_NSS_HW_Master_SS_OUT_EN:
				//HW MASTER /NSS outout enabled alternat function
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
				break;


			case SPI_NSS_HW_Master_SS_OUT_DISABLE:
				//HW master /slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);

				break;


			}

			//PA5: SPI1_SCK, MASTER ALTER PP
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);


			//PA6 : MISO (FULL DUPLEX HERE) MASTER IPUT FLOATING
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA7 :SPI1_MOSI, (FULL DUPLEX) MASTER ALTERNATE PP
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

		}else // slave
		{
			//PA4 :SPI1_NSS
			if(GLOBAL_SPI_config[SPI1_INDEX]->NSS == SPI_NSS_HW_Slave)
			{
				//HW Mater/Slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_4;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}

			//PA5: SPI1_SCK, slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_5;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA6 : MISO (FULL DUPLEX HERE) slave alternat out pp
			PinCfg.GPIO_PinNumber = GPIO_PIN_6;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA7 :SPI1_MOSI, (FULL DUPLEX HERE) slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_7;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinCfg);








		}


	} else if(SPIx == SPI2)
	{
		//PB12 :SPI2_NSS
		//PB13 :SPI2_SCK
		//PB14 :SPI2_MISO
		//PB15 :SPI2_MOSI
		if(GLOBAL_SPI_config[SPI2_INDEX]->Device_Mode == SPI_Devide_Mode_Master)
		{
			//PB12 :SPI2_NSS
			switch(GLOBAL_SPI_config[SPI2_INDEX]->NSS)
			{
			case SPI_NSS_HW_Master_SS_OUT_EN:
				//HW MASTER /NSS outout enabled alternat function
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
				break;


			case SPI_NSS_HW_Master_SS_OUT_DISABLE:
				//HW master /slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);

				break;

			}

			//PB13: SPI1_SCK, MASTER ALTER PP
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);


			//PB14 :SPI2_MISO
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB15 :SPI2_MOSI, (FULL DUPLEX) MASTER ALTERNATE PP
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}else // slave
		{
			//PB12 :SPI2_NSS
			if(GLOBAL_SPI_config[SPI2_INDEX]->NSS == SPI_NSS_HW_Slave)
			{
				//HW Mater/Slave input floating
				PinCfg.GPIO_PinNumber = GPIO_PIN_12;
				PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}

			//PB13: SPI1_SCK, slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_13;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB14 :SPI2_MISO (FULL DUPLEX HERE) slave alternat out pp
			PinCfg.GPIO_PinNumber = GPIO_PIN_14;
			PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB15 :SPI2_MOSI, (FULL DUPLEX HERE) slave input floating
			PinCfg.GPIO_PinNumber = GPIO_PIN_15;
			PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

		}
	}
}



	/*========================================================================================================================================
	 * @Fn           : SPI1_IRQHandler
	 * @brief        : SPI1 interrupt handler that processes different SPI interrupt flags (TXE, RXNE, ERRI)
	 * @param [in]   : None (ISR is automatically called upon SPI1 interrupt occurrence)
	 * @retval       : None
	 * Note          : - This function retrieves interrupt flags and calls the user-defined IRQ callback.
	 *                - The callback function is stored in the SPI global configuration structure.
 ========================================================================================================================================*/
	void SPI1_IRQHandler(void)
	{
		struct S_IRQ_SRC irq_src;

		// Read the interrupt source flags from SPI status register (SPI_SR)
		irq_src.TXE  = ((SPI1->SPI_SR & (1 << 1)) >> 1);  // Transmit buffer empty flag
		irq_src.RXNE = ((SPI1->SPI_SR & (1 << 0)) >> 0);  // Receive buffer not empty flag
		irq_src.ERRI = ((SPI1->SPI_SR & (1 << 4)) >> 4);  // Error interrupt flag

		// Call the user-defined interrupt callback function
		GLOBAL_SPI_config[SPI1_INDEX]->P_IRQ_CallBack (irq_src);
	}

	/*========================================================================================================================================
	 * @Fn           : SPI2_IRQHandler
	 * @brief        : SPI2 interrupt handler that processes different SPI interrupt flags (TXE, RXNE, ERRI)
	 * @param [in]   : None (ISR is automatically triggered by the SPI2 interrupt)
	 * @retval       : None
	 * Note          : - This function retrieves SPI2 interrupt flags and calls the user-defined IRQ callback.
	 *                - The callback function is stored in the SPI global configuration structure.
 ========================================================================================================================================*/
	void SPI2_IRQHandler(void)
{
		struct S_IRQ_SRC irq_src;

		// Read the interrupt source flags from SPI status register (SPI_SR)
		irq_src.TXE  = ((SPI2->SPI_SR & (1 << 1)) >> 1);  // Transmit buffer empty flag
		irq_src.RXNE = ((SPI2->SPI_SR & (1 << 0)) >> 0);  // Receive buffer not empty flag
		irq_src.ERRI = ((SPI2->SPI_SR & (1 << 4)) >> 4);  // Error interrupt flag

		// Call the user-defined interrupt callback function
		GLOBAL_SPI_config[SPI2_INDEX]->P_IRQ_CallBack(irq_src);
}
