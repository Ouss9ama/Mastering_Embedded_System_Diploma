/*
 * exti_driver.c
 *
 *  Created on: Feb 8, 2025
 *      Author: oussama
 */


/********************************************************************************************************************************************/
/*INCLUDES*/
/********************************************************************************************************************************************/

#include "exti_driver.h"
#include "gpio_driver.h"
#include "STM32F103x6.h"



/********************************************************************************************************************************************/
/*GENERIC VARIABLES*/
/********************************************************************************************************************************************/


void (*GPtr_IRQ_CALLBACK[15])(void) ;

/********************************************************************************************************************************************/
/*GENERIC MACROS*/
/********************************************************************************************************************************************/

#define AFIO_GPIO_EXTI_MAPPING(x)			((x == GPIOA)?0:\
		(x == GPIOB)?1:\
				(x == GPIOC)?2:\
						(x == GPIOD)?3:0)



/********************************************************************************************************************************************/
/*GENERIC FUNCTIONS*/
/********************************************************************************************************************************************/

void Enable_NVIC (uint16_t IRQ){
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_to_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_to_15_Enable;
		break;
	}
}

void Disable_NVIC (uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_to_9_disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_to_15_disable;
		break;
	}
}



void Update_EXTI(EXTI_PinCnfig_t* EXTI_Config){
	//1-Configure the GPIO To be alternative function input -> floating input

	GPIO_PinConfig_t PinCfg;
	//update the GPIO PIN to be floating Input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_PORT, &PinCfg);
	//==========================================================

	//2-update the AFIO to map between EXTI line with port coresponding port (A, B, C, D)
	uint8_t AFIO_EXTICR_INDEX = EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number / 4; // to know EXTI LINE  belong to which register from the for
	uint8_t AFIO_EXTICR_POSITION = (EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number % 4) * 4; // to get the exact position (4 bit) of EXLI line in the register
	//clear the 4 bit
	(AFIO->EXITCR[AFIO_EXTICR_INDEX]) &= ~(0xF<< AFIO_EXTICR_POSITION);
	//ENABLE THE the 4 bit of the line in the selected port
	(AFIO->EXITCR[AFIO_EXTICR_INDEX]) |= ((AFIO_GPIO_EXTI_MAPPING(EXTI_Config->EXTI_PIN.GPIO_PORT) & 0xF) << AFIO_EXTICR_POSITION);
	//==========================================================
	//3- update the rising and falling Edge

	(EXTI->RTSR) &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number); //CLEARING THE RISING REG OF THE LINE
	(EXTI->FTSR) &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number); // CLEARING THE FALLING REG OF THE LINE

	if(EXTI_Config->Trigger_Case ==  EXTI_Trigger_Rising)
	{

		(EXTI->RTSR) |= (1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);

	}else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Falling)
	{
		(EXTI->FTSR) |= (1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);

	}else if (EXTI_Config->Trigger_Case == EXTI_Trigger_Ris_Fall)
	{
		(EXTI->RTSR) |= (1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);
		(EXTI->FTSR) |= (1 << EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);
	}

	//==========================================================
	//4- update IRQ HANDLING CALLBACK

	GPtr_IRQ_CALLBACK[EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number] = EXTI_Config->Ptr_IRQ_CALLBACK;

	//==========================================================
	//5- Enable/disable the IRQ & NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);

	}else{

		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_INPUT_Line_Number);

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
 * @Fn			 : MCAL_EXTI_GPIO_DEINIT
 * @brief		 : Reset EXTI Register and NVIC corresponding IRQ Mask
 * @retval 	     : None
 * Note		     : None
  ========================================================================================================================================*/
void MCAL_EXTI_GPIO_DEINIT(void)
{
	EXTI->IMR = 0x00000000; //reset value of IMR register
	EXTI->EMR = 0x00000000; //reset value of EMR register
	EXTI->RTSR = 0x00000000; //reset value of RTSR register
	EXTI->FTSR = 0x00000000; //reset value of FTSR register
	EXTI->SWIER = 0x00000000; //reset value of SWIER register
	//Cleared by writing 1 to it.
	EXTI->PR = 0xFFFFFFFF;

	//Disable EXTI IRQ from NVIC
	NVIC_IRQ6_EXTI0_disable;
	NVIC_IRQ7_EXTI1_disable;
	NVIC_IRQ8_EXTI2_disable;
	NVIC_IRQ23_EXTI5_to_9_disable;
	NVIC_IRQ40_EXTI10_to_15_disable;
}

/*========================================================================================================================================
 * @Fn			 : MCAL_EXTI_GPIO_INIT
 * @brief		 : initialize the EXTI from a specifc GPIO PIN and specify the mask/trigger condition and IRQ callback
 * @param [in]   : EXTI_Config set by @ref EXTI_Define & @ref EXTI_Trigger_Define and @ref EXTI_IRQ_define
 * @retval 	     : None
 * Note		     : -STM32F103C6 MCU has GPIO A, B, C, D, E Modules,
                   -STM32F103C6 MCU has GPIO A,B,C,D,E modules but LQFP48 A,B AND PART OF C & D exported as external pins of MCU
                   - Mendatory to enable the RCC clock for AFIO & GPIO
  ========================================================================================================================================*/
void MCAL_EXTI_GPIO_INIT(EXTI_PinCnfig_t* EXIT_Config)
{
	Update_EXTI(EXIT_Config);
}


/*========================================================================================================================================
 * @Fn			 : MCAL_EXTI_GPIO_INIT
 * @brief		 : initialize the EXTI from a specifc GPIO PIN and specify the mask/trigger condition and IRQ callback
 * @param [in]   : EXTI_Config set by @ref EXTI_Define & @ref EXTI_Trigger_Define and @ref EXTI_IRQ_define
 * @retval 	     : None
 * Note		     : -STM32F103C6 MCU has GPIO A, B, C, D, E Modules,
                   -STM32F103C6 MCU has GPIO A,B,C,D,E modules but LQFP48 A,B AND PART OF C & D exported as external pins of MCU
                   - Mendatory to enable the RCC clock for AFIO & GPIO
  ========================================================================================================================================*/
void MCAL_EXTI_GPIO_UPDATE(EXTI_PinCnfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/************************************************************************************************/
/**********************************     ISR FUNCTIONS         ***********************************/
/************************************************************************************************/
void EXTI0_IRQHandler (void)
{
	//clear the pending the register of interrupt by writing 1
	(EXTI->PR) |= (1<<0);
	//CALL IRQ CALLBACK
	GPtr_IRQ_CALLBACK[0]();

}
void EXTI1_IRQHandler (void)
{
	//clear the pending the register of interrupt by writing 1
	(EXTI->PR) |= (1<<1);
	//CALL IRQ CALLBACK
	GPtr_IRQ_CALLBACK[1]();
}
void EXTI2_IRQHandler (void)
{
	//clear the pending the register of interrupt by writing 1
	(EXTI->PR) |= (1<<2);
	//CALL IRQ CALLBACK
	GPtr_IRQ_CALLBACK[2]();
}
void EXTI3_IRQHandler (void)
{
	//clear the pending the register of interrupt by writing 1
	(EXTI->PR) |= (1<<3);
	//CALL IRQ CALLBACK
	GPtr_IRQ_CALLBACK[3]();
}
void EXTI4_IRQHandler (void)
{
	//clear the pending the register of interrupt by writing 1
	(EXTI->PR) |= (1<<4);
	//CALL IRQ CALLBACK
	GPtr_IRQ_CALLBACK[4]();
}
void EXTI9_5_IRQHandler (void)
{
	if(EXTI->PR & 1<<5) {EXTI->PR |= (1<<5); GPtr_IRQ_CALLBACK[5]();}
	if(EXTI->PR & 1<<6) {EXTI->PR |= (1<<6); GPtr_IRQ_CALLBACK[6]();}
	if(EXTI->PR & 1<<7) {EXTI->PR |= (1<<7); GPtr_IRQ_CALLBACK[7]();}
	if(EXTI->PR & 1<<8) {EXTI->PR |= (1<<8); GPtr_IRQ_CALLBACK[8]();}
	if(EXTI->PR & 1<<9) {EXTI->PR |= (1<<9); GPtr_IRQ_CALLBACK[9]();}
}
void EXTI15_10_IRQHandler (void)
{
	if(EXTI->PR & 1<<10) {EXTI->PR |= (1<<10); GPtr_IRQ_CALLBACK[10]();}
	if(EXTI->PR & 1<<11) {EXTI->PR |= (1<<11); GPtr_IRQ_CALLBACK[11]();}
	if(EXTI->PR & 1<<12) {EXTI->PR |= (1<<12); GPtr_IRQ_CALLBACK[12]();}
	if(EXTI->PR & 1<<13) {EXTI->PR |= (1<<13); GPtr_IRQ_CALLBACK[13]();}
	if(EXTI->PR & 1<<14) {EXTI->PR |= (1<<14); GPtr_IRQ_CALLBACK[14]();}
	if(EXTI->PR & 1<<15) {EXTI->PR |= (1<<15); GPtr_IRQ_CALLBACK[15]();}
}



