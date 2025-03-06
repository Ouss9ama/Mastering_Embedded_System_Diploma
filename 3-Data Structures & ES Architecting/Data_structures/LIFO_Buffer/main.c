/*
 * main.c
 *
 *  Created on: Mar 5, 2025
 *      Author: oussama
 */


#include "lifo.h"


unsigned int data_buffer1 [5]; // static buffer of 5 int (5*4 = 20 bytes)


int main(){

	LIFO_Buf_t UART_LIFO, I2C_LIFO;
	int i = 0;
	unsigned int Popped_item = 0;
	//static allocation
	LIFO_INIT(&UART_LIFO, data_buffer1, 5);

	//dynamic allocation
	unsigned int* data_buffer2 = (unsigned int*) malloc(5 * sizeof(unsigned int ));
	if (data_buffer2 == NULL){
		printf("Allocating memory for data_buffer2 was failed\n ");
		return 1;
	}
	LIFO_INIT(&I2C_LIFO, data_buffer2, 5);

	printf("\t******UART_LIFO********\n");
	 // Pushing items into UART_LIFO
	for(int i = 0; i<7 ; i++){
		LIFO_status lifo_push_status = LIFO_PUSH_Item(&UART_LIFO, i);

		if(lifo_push_status == LIFO_no_ERROR)
			printf("Item pushed in the UART_LIFO: %d \n", i);
		if(lifo_push_status == LIFO_FULL)
			printf("The UART_LIFO is full\n");

	}
	// Popping items from UART_LIFO
	for(i = 0; i<7 ; i++){
		LIFO_status lifo_pop_status = LIFO_POP_Item(&UART_LIFO, &Popped_item);
		if(lifo_pop_status == LIFO_no_ERROR)
			printf("Item popped from the UART_LIFO: %d \n", Popped_item);
		if(lifo_pop_status == LIFO_EMPTY)
					printf("The UART_LIFO is empty\n");
		}

	printf("\t******I2C_LIFO********\n");
	 // Pushing items into I2C_LIFO
	for(int i = 0; i<7 ; i++){
		LIFO_status lifo_push_status = LIFO_PUSH_Item(&I2C_LIFO, i);

		if(lifo_push_status == LIFO_no_ERROR)
			printf("Item pushed in the I2C_LIFO: %d \n", i);
		if(lifo_push_status == LIFO_FULL)
			printf("The I2C_LIFO is full\n");

	}
	// Popping items from I2C_LIFO
	for(i = 0; i<7 ; i++){
		LIFO_status lifo_pop_status = LIFO_POP_Item(&I2C_LIFO, &Popped_item);
		if(lifo_pop_status == LIFO_no_ERROR)
			printf("Item popped from the I2C_LIFO: %d \n", Popped_item);
		if(lifo_pop_status == LIFO_EMPTY)
					printf("The I2C_LIFO is empty\n");
		}

	free(data_buffer2);
	return 0;
}
