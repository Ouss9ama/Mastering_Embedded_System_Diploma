/*
 * main.c
 *
 *  Created on: Mar 5, 2025
 *      Author: oussa
 */

#include "fifo.h"

// Define FIFO buffer size
#define width1 5

// Global array used as the buffer for FIFO
element_type uart_buffer[width1];

int main() {
    FIFO_BUF_t FIFO_UART; // Define a FIFO buffer structure
    element_type i, temp;

    // Initialize FIFO buffer
    if (FIFO_INIT(&FIFO_UART, uart_buffer, width1) == FIFO_no_ERROR)
        printf("-----------The initialization of FIFO was successful---------------- \n");

    /*
     * Enqueue elements into FIFO
     * Loop through values 0 to 6 and attempt to enqueue them into the FIFO buffer.
     * If the enqueue operation is successful, print a success message.
     * Otherwise, print a failure message.
     */
    for (i = 0; i < 7; i++) {
        printf("FIFO Enqueue of (%x) \n", i);

        if (FIFO_ENQUEUE(&FIFO_UART, i) == FIFO_no_ERROR)
            printf(">>>>>>>>>>>>>FIFO Enqueue of %x is done<<<<<<<<<<<\n", i);
        else
            printf(">>>>>>>>>>>>>FIFO Enqueue of %x failed<<<<<<<<<<<<\n", i);
    }

    // Print FIFO buffer state after enqueue operations
    FIFO_PRINT(&FIFO_UART);

    /*
     * Dequeue elements from FIFO
     * Attempt to dequeue two elements from the FIFO buffer.
     * If the dequeue operation is successful, print the dequeued value.
     */
    if (FIFO_DEQUEUE(&FIFO_UART, &temp) == FIFO_no_ERROR)
        printf(">>>>>>>>>>>>>FIFO Dequeue of %x is done<<<<<<<<<<<\n", temp);

    if (FIFO_DEQUEUE(&FIFO_UART, &temp) == FIFO_no_ERROR)
        printf(">>>>>>>>>>>>>FIFO Dequeue of %x is done<<<<<<<<<<<\n", temp);

    // Print FIFO buffer state after dequeue operations
    FIFO_PRINT(&FIFO_UART);

    return 0;
}
