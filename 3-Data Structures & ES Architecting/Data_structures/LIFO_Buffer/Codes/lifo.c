/*
 * lifo.c
 *
 *  Created on: Mar 5, 2025
 *      Author: oussa
 */

#include "lifo.h"

LIFO_status LIFO_PUSH_Item(LIFO_Buf_t *buffer, unsigned int item){
	// Check if buffer is NULL before accessing its members
	if(buffer == NULL || buffer->base == NULL)
		return LIFO_NULL;

	//check if buffer is FULL
	if(buffer->count == buffer->length)
		return LIFO_FULL;

	//push item
	*(buffer->head) = item;  // Store the item at the head position
	  buffer->head++;          // Move head forward
	  buffer->count++;         // Increase count

	return LIFO_no_ERROR;
}


LIFO_status LIFO_POP_Item(LIFO_Buf_t *buffer, unsigned int* item){

	// Check if buffer is NULL before accessing its members
	if(buffer == NULL || buffer->base == NULL)
		return LIFO_NULL;

	// Check if buffer is empty
	if(buffer->count == 0)
		return LIFO_EMPTY;

	// Pop item
	buffer->head--;      // Move head back
	*item = *(buffer->head);  // Read the popped value
	buffer->count--;

	return LIFO_no_ERROR;
}

LIFO_status LIFO_INIT(LIFO_Buf_t *buffer, unsigned int* dataBuffer, unsigned int length){

	if(dataBuffer == NULL || buffer == NULL)
		return LIFO_NULL;

	buffer->length = length;
	buffer->base = dataBuffer; // base points to the first element of the base
	buffer->head = dataBuffer; // head points to the first element of the base
	buffer->count = 0;
	return LIFO_no_ERROR;
}
