/*
 * fifo.h
 *
 *  Created on: Mar 5, 2025
 *      Author: oussa
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//select the element type (uint8_t, uint16_t, .....)
#define element_type uint8_t
//create buffer
#define width1 5


typedef struct {
    unsigned int length;    // Total capacity of the FIFO buffer
    unsigned int count;     // Current number of elements in the FIFO buffer
    element_type* base;     // Pointer to the base of the buffer
    element_type* head;     // Pointer to the head of the buffer
    element_type* tail;     // Pointer to the tail of the buffer
} FIFO_BUF_t;

typedef enum {
    FIFO_no_ERROR,  // No error, operation successful
    FIFO_FULL,      // Buffer is full
    FIFO_EMPTY,     // Buffer is empty
    FIFO_NULL       // Invalid buffer (NULL pointer)
} FIFO_BUF_Status;

/*************************************APIs**********************************/
// Initialize the FIFO buffer
FIFO_BUF_Status FIFO_INIT(FIFO_BUF_t* fifo, element_type* buffer, unsigned int length);

// Enqueue (add) an item to the FIFO buffer
FIFO_BUF_Status FIFO_ENQUEUE(FIFO_BUF_t* fifo, element_type item);

// Dequeue (remove) an item from the FIFO buffer
FIFO_BUF_Status FIFO_DEQUEUE(FIFO_BUF_t* fifo, element_type* item);

// Check if the FIFO buffer is full
FIFO_BUF_Status FIFO_IS_FULL(FIFO_BUF_t* fifo);

// Print all elements in the FIFO buffer
void FIFO_PRINT(FIFO_BUF_t* fifo);





#endif /* FIFO_H_ */
