/*
 * STM32F103C6_gpio_driver.h
 *
 *  Created on: Feb 8, 2025
 *      Author: oussama
 */

#ifndef INCLUDES_GPIO_DRIVER_H_
#define INCLUDES_GPIO_DRIVER_H_
/********************************************************************************************************************************************/
//includes
#include "STM32F103x6.h"

/********************************************************************************************************************************************/
//Config stucture
typedef struct{
	uint16_t GPIO_PinNumber ;			//Specifies  the GPIO pins to be configured
							    	  	// it is a value of @ref GPIO_PINS_define

	uint8_t GPIO_MODE;        			//Specifies the oprating mode for the selected PIN
							  	  	  	// it is a value of @ref GPIO_MODE_define

	uint8_t GPIO_Output_Speed;			//Specifies the SPEED for the selected PIN
  										// it is a value of @ref GPIO_SPEED_define

}GPIO_PinConfig_t;
/********************************************************************************************************************************************/
//Macros config reference

//@ref GPIO_PINS_define
#define GPIO_PIN_0						((uint16_t)0x0001)  // PIN 0 selected Binary: 0000 0000 0000 0001
#define GPIO_PIN_1						((uint16_t)0x0002)  // PIN 1 selected Binary: 0000 0000 0000 0010
#define GPIO_PIN_2						((uint16_t)0x0004)  // PIN 2 selected Binary: 0000 0000 0000 0100
#define GPIO_PIN_3						((uint16_t)0x0008)  // PIN 3 selected ...
#define GPIO_PIN_4						((uint16_t)0x0010)  // PIN 4 selected
#define GPIO_PIN_5						((uint16_t)0x0020)  // PIN 5 selected
#define GPIO_PIN_6						((uint16_t)0x0040)  // PIN 6 selected
#define GPIO_PIN_7						((uint16_t)0x0080)  // PIN 7 selected
#define GPIO_PIN_8						((uint16_t)0x0100)  // PIN 8 selected
#define GPIO_PIN_9						((uint16_t)0x0200)  // PIN 9 selected
#define GPIO_PIN_10						((uint16_t)0x0400)  // PIN 10 selected
#define GPIO_PIN_11						((uint16_t)0x0800)  // PIN 11 selected
#define GPIO_PIN_12						((uint16_t)0x1000)  // PIN 12 selected
#define GPIO_PIN_13						((uint16_t)0x2000)  // PIN 13 selected
#define GPIO_PIN_14						((uint16_t)0x4000)  // PIN 14 selected
#define GPIO_PIN_15						((uint16_t)0x8000)  // PIN 15 selected
#define GPIO_PIN_ALL					((uint16_t)0xFFFF)  // ALL PIN selected  Binary: 1111 1111 1111 1111
#define GPIO_PIN_MASK					0x0000FFFFu  //Used for validation/assertions to ensure only valid pins are selected

//@ref GPIO_MODE_define
#define GPIO_MODE_ANALOG				0x00000000u // 1: Analog MODE
#define GPIO_MODE_INPUT_FLO				0x00000001u // 2: Floating input
#define GPIO_MODE_INPUT_PU				0x00000002u // 3: Input with pull-up
#define GPIO_MODE_INPUT_PD				0x00000003u // 3: Input with pull-up
#define GPIO_MODE_OUTPUT_PP				0x00000004u // 4: General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u // 5: General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u // 6: Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u // 7: Alternate function output Open-drain
#define GPIO_MODE_AF_INPUT				0x00000008u // 8: Alternate function INPUT.

//@ref GPIO_SPEED_define
#define GPIO_SPEED_10MHZ				0x00000001u //Output mode, max speed 10 MHz
#define GPIO_SPEED_2MHZ					0x00000002u //Output mode, max speed 2 MHz
#define GPIO_SPEED_50MHZ				0x00000003u //Output mode, max speed 50 MHz

//@ref GPIO_PIN_State
#define GPIO_PIN_SET					1
#define GPIO_PIN_RESET		            0

//@ref GPIO_LCK_STATE
#define GPIO_RETURN_LCK_ENABLE          1
#define GPIO_RETURN_LCK_ERROR           0

/********************************************************************************************************************************************/
/*
 * =================================================================================================================
 *                                     APIs Supported by "MCAL GPIO DRIVER"
 * =================================================================================================================
 */

void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);

uint8_t MCAL_GPIO_Read_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber);
uint16_t MCAL_GPIO_Read_PORT(GPIO_TypeDef* GPIOx);

void MCAL_GPIO_Write_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_Write_PORT(GPIO_TypeDef* GPIOx,uint16_t Value);

void MCAL_GPIO_Toggle_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber);

uint8_t MCAL_GPIO_LOCK_PIN(GPIO_TypeDef* GPIOx,uint16_t PinNumber);








#endif /* INCLUDES_GPIO_DRIVER_H_ */
