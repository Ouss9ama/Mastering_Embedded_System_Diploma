/*
 * LCD.c
 *
 * Created: 2/6/2025 7:41:07 PM
 *  Author: oussama
 */ 

#include "LCD.h"
 


void LCD_KICK(){
	// Set EN pin LOW (end of the pulse)
	LCD_CONTROL |= (1<<ENABLE_SWITCH); 
	// Wait for a short time (to ensure the LCD processes the signal)
	_delay_ms(50);
	 // Set EN pin HIGH (start of the pulse)
	LCD_CONTROL &= ~(1<<ENABLE_SWITCH); // ENABLE_SWITCH : PIN3, LCD_CONTROL: PORTB
	 
	
	}  //The LCD expects the EN pin to transition from low (0) to high (1) and then back to low (0) . This transition is called an Enable pulse .
	   // it tells the LCD to process the data or command that has been sent to it.
	   
void LCD_GO_TO_XY(int line, int pos){ //line:row, column pos 0-15 for the first row, column pos 0-15 for the second row
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
	   
	   
	   
void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
	_delay_ms(2);
}
	
void LCD_IS_BUSY() {
	//a. set the DDRA (DDR_LCD_PORT) to receive data on the micro controller as input
	#ifdef EIGHT_BIT_MODE
	DDR_LCD_PORT = 0x00; //remove the  // if 8_bit mode
	#endif
	#ifdef FOUR_BIT_MODE
	DDR_LCD_PORT &= ~(0xFF<<DATA_SHIFT);
	 
	#endif
	
	//b. put the LCD in read mode (RW on)
	LCD_CONTROL |= (1<<RW_SWITCH); //MCU reads data from LCD  
	//c. put the LCD in command mode (RS off)
	LCD_CONTROL &= ~(1<<RS_SWITCH);  
	
	/*unsigned char nb;
	unsigned char busy_state;
	do{ //i tried here to write my own implementation to confirm that the lcd is not busy
		LCD_CONTROL|= (1<<ENABLE_SWITCH);
		_delay_us(2);
		nb = LCD_PORT; //read the state of the port
		LCD_CONTROL &= ~ (1 << ENABLE_SWITCH);
		
		busy_state = (nb & (1<<7)); //extract the status of D7
		
	} while (busy_state); //we repeat untill the flag*/	 
	LCD_KICK();  // Send Enable pulse to read busy flag
	#ifdef EIGHT_BIT_MODE
	DDR_LCD_PORT = 0xFF;// we return the LCD port to output
	#endif
	#ifdef FOUR_BIT_MODE
	DDR_LCD_PORT |= (0xFF<<DATA_SHIFT);// we return the LCD port to output
	 
	#endif
	
	LCD_CONTROL &= ~(1<<RW_SWITCH); // set write mode, the MCU writes to the LCD.
}

void LCD_INIT(){
		_delay_ms(20); //we will wait for LCD to power on 
		LCD_IS_BUSY();
		DDR_LCD_CONTROL |= (1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH); //set the control pin (pin of port b as output)
		LCD_CONTROL &= ~((1<<ENABLE_SWITCH) | (1<<RW_SWITCH) | (1<<RS_SWITCH)); //clear the control pin connected to LCD 
		DDR_LCD_PORT = 0xFF;//set data of port A (LCD port as output)
		LCD_clear_screen(); // we clear the display
	#ifdef EIGHT_BIT_MODE
		LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
		 
		LCD_WRITE_COMMAND(0x02); 
		LCD_WRITE_COMMAND(LCD_FUNCT	ION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW); //we set the cursor on to first row 
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK); 
}

void LCD_WRITE_COMMAND(unsigned char command){
		 
	#ifdef EIGHT_BIT_MODE
		LCD_IS_BUSY();
		LCD_PORT = command; //we put command to data port A
		LCD_CONTROL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH)); //we set LCD to Write & command mode
		_delay_ms(1);
		LCD_KICK(); //send the pulse
    #endif
	#ifdef FOUR_BIT_MODE 
		LCD_IS_BUSY();
	//sending the 1st half of the command
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0); // we take half of the command 
		LCD_CONTROL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH)); //we set LCD to Write & command mode
		_delay_ms(1);
		LCD_KICK();
		//sending the 2nd half of the command
		LCD_PORT = (LCD_PORT & 0x0F) | (command << 4); // we take half of the command
		LCD_CONTROL &= ~((1<<RW_SWITCH) | (1<<RS_SWITCH)); //we set LCD to Write & command mode
		_delay_ms(1);
		LCD_KICK();
	#endif
}


void LCD_WRITE_CHAR(unsigned char data){
	 
	#ifdef EIGHT_BIT_MODE
	LCD_IS_BUSY();
	LCD_CONTROL &= ~(1<<RW_SWITCH);//we set the LCD to write mode 
	LCD_CONTROL |= (1<<RS_SWITCH); // but this time we send data 
	LCD_PORT = data;
	LCD_KICK(); //send pulse
	#endif
	
	#ifdef FOUR_BIT_MODE
	 LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0); 
	 LCD_CONTROL &= ~(1<<RW_SWITCH);//we set the LCD to write mode
	 LCD_CONTROL |= (1<<RS_SWITCH); // but this time we send data
	 _delay_ms(1);
	 LCD_KICK(); //send pulse
	 LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
	 LCD_CONTROL &= ~(1<<RW_SWITCH);//we set the LCD to write mode
	 LCD_CONTROL |= (1<<RS_SWITCH); // but this time we send data
	 _delay_ms(1);
	 LCD_KICK(); //send pulse
	#endif
}

void LCD_WRITE_STRING(char* data){
	int counter = 0; //the counter we used here keeps track of how many characters have been written
	while(*data >0)	{ //our loop is on as long as the current character is not '\0' (end of string)
		counter ++;
		LCD_WRITE_CHAR(*data++);// write the character and move to the next one
		if(counter == 16){ //if 16 char have been written we move to the second row 
			LCD_GO_TO_XY(2, 0);
		}
		else if(counter == 32){//if 32 char have been written we clear the screen and start all over again from the first row
			LCD_clear_screen();
			LCD_GO_TO_XY(1,0);
			counter = 0;
		}
	}
}