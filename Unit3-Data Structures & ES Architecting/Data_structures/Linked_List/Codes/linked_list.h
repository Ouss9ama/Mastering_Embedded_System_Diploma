/*
 * linkedlist.h
 *
 *  Created on: Mar 6, 2025
 *      Author: oussa
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

// Effective data structure to hold student information
typedef struct SDATA {
    int ID;             // Student ID
    char NAME[40];      // Student name
    float HEIGHT;       // Student height
} SDATA;

// Linked list node structure
typedef struct SStudent {
    struct SDATA Student;               // Student data
    struct SStudent* Ptr_Next_Student; // Pointer to the next student in the list
} SStudent;

/*************************APIs*********************************/
void ADD_STUDENT();                     // Add a new student to the list
void FILL_RECORD(SStudent* RECORD);     // Fill student record with data
int DELETE_STUDENT();                   // Delete a student by ID
void VIEW_STUDENTS();                   // View all students in the list
void DELETE_ALL();                      // Delete all students from the list
void GET_DATA_FROM_INDEX();             // Get student data by index
void PRINTF_DATA_STUDENT(SStudent* RECORD); // Print student data
void NB_RECORDS();                      // Get the number of records in the list
void GET_DATA_FROM_INDEX_REVERSE();     // Get student data by index from the end
void INVERSE_THE_LIST();                // Reverse the linked list

#endif /* LINKED_LIST_H_ */
