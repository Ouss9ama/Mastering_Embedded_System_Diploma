/*
 * keypad.c
 *
 * Created: 2/7/2025 2:49:16 PM
 *  Author: oussama
 */ 

#include "keypad.h"
GPIO_PinConfig_t PinCfg_keypad;

void my_delay_1(int x)
{
	uint32_t i,j;
	for(i=0; i<x ; i++)
	{
		for(j=0; j<255; j++);
	}
}
int Keypad_Row[] = {R0, R1, R2, R3};
int Keypad_Column[] = {C0, C1, C2, C3};

void KEYPAD_INIT(){
	//	DDR_KEYPAD_PORT &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));

	//	DDR_KEYPAD_PORT |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));

	PinCfg_keypad.GPIO_PinNumber = R0;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = R1;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = R2;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = R3;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = C0;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = C1;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber = C2;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	PinCfg_keypad.GPIO_PinNumber =C3;
	PinCfg_keypad.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg_keypad.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinCfg_keypad);

	//KEYPAD_PORT = 0xFF;
	MCAL_GPIO_Write_PORT(KEYPAD_PORT, 0XFF);
}

char KEYPAD_GETCHAR()
{
	int i,j; //i to iterate over the column (0-->3) and j to iterate over the row (0-->3) 
	for(i = 0; i < 4; i++)
	{ //activating one column at a time
		//set all column high
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Keypad_Column[0], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Keypad_Column[1], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Keypad_Column[2], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Keypad_Column[3], GPIO_PIN_SET);
		MCAL_GPIO_Write_PIN(KEYPAD_PORT, Keypad_Column[i], GPIO_PIN_RESET );
		;//pull the current column low
		for(j = 0; j < 4; j++)
		{ //iterate over the rows to check which row pulled low
			if((MCAL_GPIO_Read_PIN(KEYPAD_PORT, Keypad_Row[j])) == 0)
			{ //see which row pulled the target column i, if its pin is low then is it one the one if(!0) == true
				while((MCAL_GPIO_Read_PIN(KEYPAD_PORT, Keypad_Row[j])) == 0);

				switch(i){
					case(0):
							if(j == 0) return '7';
							else if(j == 1) return '4';
							else if(j == 2) return '1';
						    else if(j == 3) return '!';
							break;
					case(1):
							if(j == 0) return '8';
							else if(j == 1) return '5';
							else if(j == 2) return '2';
							else if(j == 3) return '0';
							break;
					case(2):
							if(j == 0) return '9';
							else if(j == 1) return '6';
							else if(j == 2) return '3';
							else if(j == 3) return '=';
							break;
					case(3):
							if(j == 0) return '/';
							else if(j == 1) return '*';
							else if(j == 2) return '-';
							else if(j == 3) return '+';
							break;
				}
			}
		}
	}
	return 'A';
}
