/*
 * queue.h
 *
 *  Created on: Apr 14, 2025
 *      Author: oussa
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

// Macro to safely print with flushing stdout and stdin
#define DPRINTF(...)       {fflush(stdout);\
                           fflush(stdin);\
                           printf(__VA_ARGS__);\
                           fflush(stdout);\
                           fflush(stdin);} // Ensures output is displayed immediately and input buffer is clear

// Macro to safely scan input with flushing stdout and stdin
#define DSCANF(...)       {fflush(stdout);\
                          fflush(stdin);\
                          scanf(__VA_ARGS__);\
                          fflush(stdout);\
                          fflush(stdin);} // Ensures input is read cleanly with no leftover buffer data

/*
 * Structure: Student_info
 * ----------------------
 * Defines the data structure to store information for a single student.
 */
typedef struct {
    char First_name[30]; // Array to store student's first name (up to 29 characters)
    char Last_name[30];  // Array to store student's last name (up to 29 characters)
    int ID;              // Unique identifier for the student
    float GPA;           // Student's grade point average
    int Course_ID[5];    // Array to store IDs of up to 5 courses the student is enrolled in
} Student_info;

/*
 * Structure: Queue_st
 * -------------------
 * Defines the circular queue structure to manage student records.
 */
typedef struct {
    int length;            // Maximum number of students the queue can hold
    int count;             // Current number of students in the queue
    Student_info* base;    // Pointer to the start of the queue buffer
    Student_info* head;    // Pointer to the next position for enqueueing a student
    Student_info* tail;    // Pointer to the next position for dequeuing a student
} Queue_st;

/*
 * Enumeration: queue_Status_t
 * ---------------------------
 * Defines possible status codes for queue operations.
 */
typedef enum {
    FIFO_NO_ERROR, // Operation completed successfully
    FIFO_FULL,     // Queue is at maximum capacity
    FIFO_EMPTY,    // Queue is empty
    FIFO_NULL      // Queue or buffer pointer is NULL
} queue_Status_t;

/*
 * Enumeration: ID_st
 * ------------------
 * Defines status codes for checking ID uniqueness.
 */
typedef enum {
    ID_is_duplicated, // ID already exists in the queue
    ID_is_unique      // ID does not exist in the queue
} ID_st;

/*************************************APIs**********************************/

/*
 * Function Prototype: Queue_init
 * -----------------------------
 * Initializes the queue with a given buffer and size.
 * Parameters:
 *     fifo   - Pointer to the queue structure
 *     buffer - Pointer to the student info buffer
 *     length - Maximum number of students
 * Returns: queue_Status_t (status of initialization)
 */
queue_Status_t Queue_init(Queue_st* fifo, Student_info* buffer, unsigned int length);

/*
 * Function Prototype: ENQUEUE
 * ---------------------------
 * Adds a student to the queue.
 * Parameters:
 *     fifo    - Pointer to the queue structure
 *     student - Student_info structure to enqueue
 * Returns: queue_Status_t (status of enqueue operation)
 */
queue_Status_t ENQUEUE(Queue_st* fifo, Student_info student);

/*
 * Function Prototype: DEQUEUE
 * ---------------------------
 * Removes a student from the queue and returns their details.
 * Parameters:
 *     fifo    - Pointer to the queue structure
 *     student - Pointer to store dequeued student info
 * Returns: queue_Status_t (status of dequeue operation)
 */
queue_Status_t DEQUEUE(Queue_st* fifo, Student_info* student);

/*
 * Function Prototype: FIFO_IS_FULL
 * -------------------------------
 * Checks if the queue is full.
 * Parameters:
 *     fifo - Pointer to the queue structure
 * Returns: queue_Status_t (full or not full status)
 */
queue_Status_t FIFO_IS_FULL(Queue_st* fifo);

/*
 * Function Prototype: Add_Student_Manually
 * ---------------------------------------
 * Adds a student to the queue by prompting user for details.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void Add_Student_Manually(Queue_st* fifo);

/*
 * Function Prototype: Add_Student_from_file
 * ----------------------------------------
 * Adds students to the queue by reading from a text file.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void Add_Student_from_file(Queue_st* fifo);

/*
 * Function Prototype: find_Student_Trough_ID
 * -----------------------------------------
 * Searches for a student by ID and displays their details.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void find_Student_Trough_ID(Queue_st* fifo);

/*
 * Function Prototype: find_Student_Trough_First_Name
 * -------------------------------------------------
 * Searches for students by first name and displays their details.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void find_Student_Trough_First_Name(Queue_st* fifo);

/*
 * Function Prototype: find_Student_Trough_Course_ID
 * ------------------------------------------------
 * Finds students enrolled in a specific course and displays their details.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void find_Student_Trough_Course_ID(Queue_st* fifo);

/*
 * Function Prototype: find_Totale_NB_of_Students
 * ---------------------------------------------
 * Displays the total number of students and queue capacity.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void find_Totale_NB_of_Students(Queue_st* fifo);

/*
 * Function Prototype: Delete_Students_Trough_ID
 * --------------------------------------------
 * Deletes a student from the queue by ID.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void Delete_Students_Trough_ID(Queue_st* fifo);

/*
 * Function Prototype: Update_Students_Trough_ID
 * --------------------------------------------
 * Updates a student's details by ID via a menu.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void Update_Students_Trough_ID(Queue_st* fifo);

/*
 * Function Prototype: Show_all_Infos
 * ---------------------------------
 * Displays details of all students in the queue.
 * Parameters:
 *     fifo - Pointer to the queue structure
 */
void Show_all_Infos(Queue_st* fifo);

/*
 * Function Prototype: is_ID_unique
 * -------------------------------
 * Checks if a student ID is unique in the queue.
 * Parameters:
 *     fifo - Pointer to the queue structure
 *     id   - ID to check for uniqueness
 * Returns: ID_st (unique or duplicated status)
 */
ID_st is_ID_unique(Queue_st * fifo, int id);

#endif /* QUEUE_H_ */
