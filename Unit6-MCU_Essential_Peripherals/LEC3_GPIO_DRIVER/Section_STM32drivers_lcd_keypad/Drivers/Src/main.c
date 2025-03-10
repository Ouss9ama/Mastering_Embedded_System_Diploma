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

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32F103x6.h"
#include "gpio_driver.h"
#include "lcd.h"
#include "keypad.h"

void my_delay(int x)
{
	uint32_t i,j;
	for(i=0; i<x ; i++)
	{
		for(j=0; j<255; j++);
	}
}

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10



void clock_init()// Function to initialize the clock for GPIO ports
{

	// Enable clock for GPIOA (used by LCD)
	RCC_GPIOA_CLK_EN();

	// Enable clock for GPIOB (used by Keypad)
	RCC_GPIOB_CLK_EN();

}

void GPIO_inti(){


	GPIO_PinConfig_t PinCfg;



	//PORT B pin 9: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);


	//PORT B pin 10: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);

	//PORT B pin 11: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);

	//PORT B pin 12: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);

	//PORT B pin 13: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);

	//PORT B pin 14: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);

	//PORT B pin 15: output pushpull mode
	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(GPIOB,&PinCfg);


}



int main(void)
{

	clock_init();
	LCD_INIT();
	GPIO_inti();

	unsigned char Pressed_Key;
	LCD_WRITE_STRING("They call me OUS");
	my_delay(500);
	LCD_clear_screen();
	unsigned char seg[]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE, ZERO};
	unsigned char lcd[]= {'0','1','2','3','4','5','6','7','8','9','0'};
	for(unsigned char i=0;i<11;i++){
		MCAL_GPIO_Write_PORT(GPIOB, seg[i]<<9);
		LCD_WRITE_CHAR(lcd[i]);
		my_delay(50);
	}
	my_delay(250);
	LCD_clear_screen();
	KEYPAD_INIT();
	LCD_WRITE_STRING("Keypad is ready");
	my_delay(500);
	LCD_clear_screen();
	my_delay(250);
	while(1)
	{
		Pressed_Key = KEYPAD_GETCHAR();
		switch(Pressed_Key)
		{
		 	 case ('!'):
				LCD_clear_screen();
		 	 	 break;
		 	 case ('A'):
				break;
		 	 default:
		 		LCD_WRITE_CHAR(Pressed_Key);
		 		break;
		}
	}
	my_delay(100);



}

