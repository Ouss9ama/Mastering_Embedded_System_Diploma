/*
 * fifo.c
 *
 *  Created on: Mar 5, 2025
 *      Author: oussa
 */

#include "fifo.h"

/**
 * @brief Initializes the FIFO buffer.
 *
 * This function initializes the FIFO buffer by setting up the base, head, tail,
 * length, and count fields of the FIFO structure. It checks if the provided
 * buffer is valid (not NULL) before proceeding with initialization.
 *
 * @param fifo Pointer to the FIFO buffer structure to initialize.
 * @param buffer Pointer to the memory block used as the FIFO buffer.
 * @param length The size of the FIFO buffer (number of elements it can hold).
 * @return FIFO_BUF_Status Returns FIFO_no_ERROR on success, or FIFO_NULL if the buffer is invalid.
 */
FIFO_BUF_Status FIFO_INIT(FIFO_BUF_t* fifo, element_type* buffer, unsigned int length){
    if (buffer == NULL)
        return FIFO_NULL;
    fifo->base = buffer;
    fifo->head = buffer;
    fifo->tail = buffer;
    fifo->length = length;
    fifo->count = 0;

    return FIFO_no_ERROR;
}

/**
 * @brief Enqueues an item into the FIFO buffer.
 *
 * This function adds an item to the FIFO buffer if there is space available.
 * It checks if the buffer is full before attempting to enqueue. If the buffer
 * is full, it returns FIFO_FULL. Otherwise, it places the item at the current
 * head position and updates the head pointer.
 *
 * @param fifo Pointer to the FIFO buffer structure.
 * @param item The item to be enqueued into the FIFO buffer.
 * @return FIFO_BUF_Status Returns FIFO_no_ERROR on success, FIFO_FULL if the buffer is full,
 *         or FIFO_NULL if the buffer is invalid.
 */
FIFO_BUF_Status FIFO_ENQUEUE(FIFO_BUF_t* fifo, element_type item){
    if(!fifo->base ||!fifo->head || !fifo->tail)
        return FIFO_NULL;

    if(FIFO_IS_FULL(fifo) == FIFO_FULL)
        return FIFO_FULL ;

    *(fifo->head) = item;
    if(fifo->head == fifo->base + (fifo->length * sizeof(element_type)))
        fifo->head = fifo->base;
    else
        fifo->head++;
    fifo->count++;


    return FIFO_no_ERROR;
}

/**
 * @brief Dequeues an item from the FIFO buffer.
 *
 * This function removes an item from the FIFO buffer if the buffer is not empty.
 * It retrieves the item from the current tail position and updates the tail pointer.
 * If the buffer is empty, it returns FIFO_EMPTY.
 *
 * @param fifo Pointer to the FIFO buffer structure.
 * @param item Pointer to store the dequeued item.
 * @return FIFO_BUF_Status Returns FIFO_no_ERROR on success, FIFO_EMPTY if the buffer is empty,
 *         or FIFO_NULL if the buffer is invalid.
 */
FIFO_BUF_Status FIFO_DEQUEUE(FIFO_BUF_t* fifo, element_type* item){
    if(!fifo->base ||!fifo->head || !fifo->tail)
        return FIFO_NULL;
    if(fifo->count == 0)
        return FIFO_EMPTY;
    *item = *(fifo->tail);
    if(fifo->tail == fifo->base + (fifo->length * sizeof(element_type)))
        fifo->tail = fifo->base;
    else
        fifo->tail++;
    fifo->count--;


    return FIFO_no_ERROR;
}

/**
 * @brief Checks if the FIFO buffer is full.
 *
 * This function determines whether the FIFO buffer is full by comparing the
 * current count of items in the buffer with its maximum length.
 *
 * @param fifo Pointer to the FIFO buffer structure.
 * @return FIFO_BUF_Status Returns FIFO_FULL if the buffer is full, FIFO_no_ERROR if not full,
 *         or FIFO_NULL if the buffer is invalid.
 */
FIFO_BUF_Status FIFO_IS_FULL(FIFO_BUF_t* fifo){
    if(!fifo->base ||!fifo->head || !fifo->tail)
        return FIFO_NULL;

    if(fifo->count == fifo->length)
        return FIFO_FULL;
    return FIFO_no_ERROR;
}

/**
 * @brief Prints the contents of the FIFO buffer.
 *
 * This function prints the current state of the FIFO buffer. If the buffer is
 * empty, it prints a message indicating so. Otherwise, it iterates through the
 * buffer starting from the tail and prints each item until it reaches the head.
 *
 * @param fifo Pointer to the FIFO buffer structure.
 */
void FIFO_PRINT(FIFO_BUF_t* fifo){
    element_type* temp;
    int i;
    if(fifo->count == 0)
        printf("FIFO is empty \n");
    else{
        temp = fifo->tail;
        printf("=========FIFO_PRINT========\n");
        for(i=0 ; i<fifo->count ; i++){
            printf("\t %d \n", *temp);
            temp++;
            if(temp == fifo->base + (fifo->length * sizeof(element_type)))
                temp = fifo->base;
        }
    }
}
