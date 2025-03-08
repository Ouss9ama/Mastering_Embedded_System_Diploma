/*
 * LCD.c
 *
 * Created: 2/6/2025 7:41:07 PM
 *  Author: oussama
 */

#include "lcd.h"

GPIO_PinConfig_t PinCfg;
void my_wait(unsigned int x)
{
	unsigned int i,j;
	for(i=0; i<x ; i++)
	{
		for(j=0; j<255; j++);
	}
}

void LCD_KICK(){
	//Set EN pin LOW (end of the pulse)
	MCAL_GPIO_Write_PIN(LCD_CONTROL, ENABLE_SWITCH, GPIO_PIN_SET);
	//Wait for a short time (to ensure the LCD processes the signal)
	my_wait(10);
	//Set EN pin HIGH (start of the pulse)
	//ENABLE_SWITCH : PIN3, LCD_CONTROL: PORTB
	MCAL_GPIO_Write_PIN(LCD_CONTROL, ENABLE_SWITCH, GPIO_PIN_RESET);

}  //The LCD expects the EN pin to transition from low (0) to high (1) and then back to low (0) . This transition is called an Enable pulse .
// it tells the LCD to process the data or command that has been sent to it.

void LCD_WRITE_COMMAND(unsigned char command)
{
	LCD_IS_BUSY();
	//we put command to data port A
	MCAL_GPIO_Write_PORT(LCD_CONTROL, command);
	//we set LCD to Write & command mode
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RS_SWITCH, GPIO_PIN_RESET);
	my_wait(1);
	LCD_KICK(); //send the pulse
}



void LCD_INIT()
{
	my_wait(20);;
	RCC_GPIOA_CLK_EN();

	//my_wait(20); //we will wait for LCD to power on

	//ENABLE_SWITCH, RS_SWITCH and RW_SWITCH are set to be output floating

	PinCfg.GPIO_PinNumber = ENABLE_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);


	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);


	//my_wait(20);

	//PIN (0 ---> 7) PORTA set to output MODE
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	MCAL_GPIO_Write_PIN(LCD_CONTROL, ENABLE_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);

	my_wait(15);


	LCD_clear_screen(); // we clear the display
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW); //we set the cursor on to first row
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}



void LCD_GO_TO_XY(int line, int pos){


	//line:row, column pos 0-15 for the first row, column pos 0-15 for the second row
	if(line == 1){ // we check if the target line is the 1st line
		if(pos < 16 && pos >=0){ //ensure the pos is within the range 0-15
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + pos);//we send command to the cursor to move it to pos
		}
	}
	else if(line == 2){// we check if the target line is the 2nd row
		if(pos < 16 && pos >=0){//ensure the pos is within the range 0-15
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + pos);//we send command to the cursor to move it to pos
		}
	}
}



void LCD_clear_screen()
{
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
	my_wait(2);
}

void LCD_IS_BUSY()
{
	//a. set the PORTA (0--->7)to receive data on the micro controller as input

	GPIO_PinConfig_t PinCfg;
	//PIN (0 ---> 7) PORTA set to INPUT MODE
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);



	//b. put the LCD in read mode (RW on)
	//MCU reads data from LCD
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RW_SWITCH, GPIO_PIN_SET);

	//c. put the LCD in command mode (RS off)
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RS_SWITCH, GPIO_PIN_RESET);

	LCD_KICK();  // Send Enable pulse to read busy flag

	//DDR_LCD_PORT = 0xFF;// we return the LCD port to output
	//
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_1;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_2;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_3;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_4;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_5;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_6;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

		PinCfg.GPIO_PinNumber = GPIO_PIN_7;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10MHZ;
		MCAL_GPIO_Init(LCD_CONTROL,&PinCfg);

	//LCD_CONTROL &= ~(1<<RW_SWITCH); // set write mode, the MCU writes to the LCD.
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);
}





void LCD_WRITE_CHAR(unsigned char data)
{

	LCD_IS_BUSY();
	MCAL_GPIO_Write_PORT(LCD_CONTROL, data);
	//we set the LCD to write mode
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RW_SWITCH, GPIO_PIN_RESET);
	// but this time we send data
	MCAL_GPIO_Write_PIN(LCD_CONTROL, RS_SWITCH, GPIO_PIN_SET);
    my_wait(1);
	LCD_KICK(); //send pulse
}


void LCD_WRITE_STRING(char* data)
{
	int counter = 0; //the counter we used here keeps track of how many characters have been written
	while(*data >0)
	{ //our loop is on as long as the current character is not '\0' (end of string)
		counter ++;
		LCD_WRITE_CHAR(*data++);// write the character and move to the next one
		if(counter == 16)
		{
			//if 16 char have been written we move to the second row

			LCD_GO_TO_XY(2, 0);
		}
		else if(counter == 32)
		{//if 32 char have been written we clear the screen and start all over again from the first row
			LCD_clear_screen();
			LCD_GO_TO_XY(1,0);
			counter = 0;
		}
	}

}
