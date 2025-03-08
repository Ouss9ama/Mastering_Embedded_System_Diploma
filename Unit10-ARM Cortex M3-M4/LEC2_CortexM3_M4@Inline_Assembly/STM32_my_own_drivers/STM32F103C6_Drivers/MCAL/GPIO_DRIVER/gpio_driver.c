/*
 * gpio_driver.c
 *
 *  Created on: Feb 8, 2025
 *      Author: oussama
 */


/********************************************************************************************************************************************/
                                                 /*INCLUDES*/
/********************************************************************************************************************************************/

#include "gpio_driver.h"
#include "STM32F103x6.h"

/********************************************************************************************************************************************/
                                              /*GENERIC FUNCTIONS*/
/********************************************************************************************************************************************/

uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	default:
		return 0;
	}
}

/*********************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Functions Defintion
 * =================================================================================================================
 */
/*******************************************************************************************************************************/


/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Init
 * @brief		 : intialize the GPIOX PINy according to the specified parametters in the PinConfig
 * @param [in]  : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]  : PinConfig pointer  to a GPIO_PinConfig_t structure that contains the config info for the selected GPIO peripheral
 * @retval 	 : None
 * Note		 : STM32F103C6 MCU has GPIO A,B,C,D,E modules but LQFP48 A,B AND PART OF C & D exported as external pins of MCU
  ========================================================================================================================================*/
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig){

	// (GPIOx_CRL) Configuration Register Low (configures the lower 8 pins of the GPIO port 0---->7)
	// (GPIOx_CRL) Configuration Register High (configures the higher 8 pins of the GPIO port 8---->15)
	volatile uint32_t* Config_Register = NULL;
	uint8_t PIN_Config = 0; //will hold the final 4-bit value that will be written to the CRL or CRH
	uint8_t position = Get_CRLH_Position(PinConfig->GPIO_PinNumber);

	// Select the correct configuration register (CRL or CRH)
	Config_Register = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;

	/*Clear MODEx[1:0] and CNFx[1:0]*/
	(*Config_Register) &= ~(0xf <<position);

	//if pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) ||
	   (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) ||
	   (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) ||
	   (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD))
	{
		/*SETS MODEx[1:0] and CNFx[1:0]*/
		PIN_Config = ((((PinConfig->GPIO_MODE -4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f);

	}
	//if pin is input
	else //MODE = 00 BY DEFUALT
	{
		if( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG) )
		{
			/*SETS MODEx[00] and CNFx[1:0]*/
			PIN_Config = ((((PinConfig->GPIO_MODE) << 2) | (0x0)) & 0x0f);

		}else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)
		{
			/*SETS MODEx[00] and CNFx[1:0]*/
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | (0x0)) & 0x0f);
		}
		else
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2) | (0x0)) & 0x0f);
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//incase of pull-up PxODR set to 1
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}else
			{
				//incase of pull-down PxODR clears
				GPIOx->ODR &= ~ (PinConfig->GPIO_PinNumber);
			}
		}

	}
	//write on the CRL or CRH
	(*Config_Register) |= (PIN_Config << position);
}


/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_DeInit
 * @brief		 : Reset all the GPIO Registers
 * @param [in]  : GPIOx(x can be A-...-E depending on the device used to selected)
 * @retval 	 : None
 * Note	     : None
 ========================================================================================================================================*/
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx){

  /*GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRH  = 0x44444444;
	GPIOx->CRL  = 0x44444444;
  //GPIOx->IDR  = ; READ-ONLY
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;*/

	/*******Or we can use the the reset register*******/
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2); //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
		}else if(GPIOx == GPIOB){ //Bit 3 IOPARST: IO port B reset
			RCC->APB2RSTR |= (1<<3);
			RCC->APB2RSTR &= ~(1<<3);
		}else if(GPIOx == GPIOC){ //Bit 4 IOPARST: IO port C reset
			RCC->APB2RSTR |= (1<<4);
			RCC->APB2RSTR &= ~(1<<4);
		}else if(GPIOx == GPIOD){ //Bit 5 IOPARST: IO port D reset
			RCC->APB2RSTR |= (1<<5);
			RCC->APB2RSTR &= ~(1<<5);
		}{ //Bit 6 IOPARST: IO port E reset
			RCC->APB2RSTR |= (1<<6);
			RCC->APB2RSTR &= ~(1<<6);
		}

}
/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Read_PIN
 * @brief		 : Read specific pin
 * @param [in]  : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]  : PinNumber (set according number according to @ref GPIO_PINS_define)
 * @retval 	 : The input pin value (either 2 values according to @ref GPIO_PIN_State)
 * Note		 : None
  ========================================================================================================================================*/
uint8_t MCAL_GPIO_Read_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber){

	uint8_t bitstatus ;
	if(((GPIOx->IDR) & PinNumber)!= (uint32_t)GPIO_PIN_RESET){
		bitstatus = GPIO_PIN_SET;
	}else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}


/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Read_PORT
 * @brief		 : Read input PORT value
 * @param [in]  : GPIOx(x can be A-...-E depending on the device used to selected)
 * @retval 	 : The input port value
 * Note         : None
 ========================================================================================================================================*/
uint16_t MCAL_GPIO_Read_PORT(GPIO_TypeDef* GPIOx){

	uint16_t port_value;
	port_value = (uint16_t)(GPIOx->IDR);
	return port_value;
}


/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Write_PIN
 * @brief		 : Write specific pin
 * @param [in]   : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]   : PinNumber (set according number according to @ref GPIO_PINS_define)
 * @retval 	     : None
 * Note		     : None
 ========================================================================================================================================*/
void MCAL_GPIO_Write_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber, uint8_t Value){

	if(Value!= GPIO_PIN_RESET){
		//GPIOx->ODR |= PinNumber;

		/*************Or we can use the the BSRR & BRR register***********/

		GPIOx->BSRR = (uint32_t)PinNumber;

		}else
		{
		GPIOx->BRR = (uint32_t)PinNumber;
		}

	}


/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Write_PORT
 * @brief		 : write specific port
 * @param [in]    : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]    : Value to be set in the port
 * @retval 	     : None
 * Note		     : None
========================================================================================================================================*/
void MCAL_GPIO_Write_PORT(GPIO_TypeDef* GPIOx,uint16_t Value){
	GPIOx->ODR = (uint32_t) Value;
}

/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_Toggle_PIN
 * @brief		 : Toggles specific pin
 * @param [in]    : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]    : PinNumber (set according number according to @ref GPIO_PINS_define)
 * @retval 	     : None
 * Note		     : None
========================================================================================================================================*/
void MCAL_GPIO_Toggle_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber){

	GPIOx->ODR ^= (PinNumber);

}

/*========================================================================================================================================
 * @Fn			 : MCAL_GPIO_LOCK_PIN
 * @brief		 : The locking mechanism allows  the IO configuration  ti be frozen
 * @param [in]    : GPIOx(x can be A-...-E depending on the device used to selected)
 * @param [in]    : PinNumber (set according number according to @ref GPIO_PINS_define)
 * @retval 	     : Enabled(if the pinconfig is locked) or ERROR(if pin is not locked) @ref GPIO_LCK_STATE
 * Note		     : None
========================================================================================================================================*/
uint8_t MCAL_GPIO_LOCK_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber){

	  /*Bit 16 LCKK[16]: Lock key
		This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
		0: Port configuration lock key not active
		1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
		LOCK key writing sequence:
		Write 1
		Write 0
		Write 1
		Read 0
		Read 1 (this read is optional but confirms that the lock is active)
		Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
		Any error in the lock sequence will abort the lock.
		Bits 15:0 : Port x Lock bit y (y= 0 .. 15)
		These bits are read write but can only be written when the LCKK bit is 0.
		0: Port configuration not locked
		1: Port configuration locked.*/

	volatile uint32_t tmp = 1 << 16; //Bit 16 LCKK[16]: Lock key
	tmp |=  PinNumber; // set LCKx
	GPIOx->LCKR	= tmp ; //Write 1
	GPIOx->LCKR = PinNumber ; //Write 0
	GPIOx->LCKR	= tmp ; //Write 1
	tmp = GPIOx->LCKR; //Read 0
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LCK_ENABLE;
	}else
	{
		return GPIO_RETURN_LCK_ERROR;
	}
}










