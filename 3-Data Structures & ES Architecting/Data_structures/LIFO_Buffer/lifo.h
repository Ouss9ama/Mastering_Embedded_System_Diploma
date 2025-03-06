/*
 * lifo.h
 *
 *  Created on: Mar 5, 2025
 *      Author: oussa
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdio.h"
#include "stdlib.h"

/*******types definitions*********/

// LIFO Buffer Structure
typedef struct {
    unsigned int length;   // Maximum number of items the buffer can hold
    unsigned int count;    // Current number of items in the buffer
    unsigned int* base;    // Pointer to the first element (start of buffer)
    unsigned int* head;    // Pointer to the top element (last added item)
} LIFO_Buf_t;

// LIFO Status Codes
typedef enum {
    LIFO_no_ERROR,  // No error, operation successful
    LIFO_FULL,      // LIFO buffer is full
    LIFO_EMPTY,     // LIFO buffer is empty
    LIFO_NULL       // LIFO buffer is not initialized (NULL pointer)
} LIFO_status;

/******APIs*******/
// Pushes an item onto the LIFO buffer and updates head & count
LIFO_status LIFO_PUSH_Item(LIFO_Buf_t *buffer, unsigned int item);

// Pops an item from the LIFO buffer and updates head & count
LIFO_status LIFO_POP_Item(LIFO_Buf_t *buffer, unsigned int* item);

// Initializes the LIFO buffer with a given data storage array.
LIFO_status LIFO_INIT(LIFO_Buf_t *buffer, unsigned int* dataBuffer, unsigned int length);

//>>>>*buffer (LIFO_Buf_t buffer)<<<<<<<<
//->A pointer to the LIFO_Buf_t structure that will be initialized.
//>>>>*dataBuffer (unsigned int dataBuffer)<<<<<<<<<<<
//->A pointer to the pre-allocated storage array that will be used as the stack.
//>>>>length (unsigned int length)<<<<<<<<<<<<<<<<
//->The maximum number of elements that the buffer can hold.





#endif /* LIFO_H_ */
