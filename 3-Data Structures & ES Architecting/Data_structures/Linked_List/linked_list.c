/*
 * linked_list.c
 *
 *  Created on: Mar 6, 2025
 *      Author: oussa
 */

#include "linked_list.h"
#define  DPRINTF(...)       {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

#define  DSCANF(...)       {fflush(stdout);\
		fflush(stdin);\
		scanf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

// Global pointer to the first student in the list
SStudent* gPtr_First_Student = NULL;

// Function to add a new student to the list
void ADD_STUDENT() {
	SStudent* Ptr_New_Student;  // Pointer to the new student record
	SStudent* Ptr_Last_Student; // Pointer to the last student in the list

	// Check if the list is empty
	if (gPtr_First_Student == NULL) {
		// Create new record
		Ptr_New_Student = (SStudent*)malloc(sizeof(SStudent));
		if (!Ptr_New_Student) {
			DPRINTF("Memory allocation failed!\n");
			return;
		}
		gPtr_First_Student = Ptr_New_Student; // Set the new student as the first in the list
	} else {
		// Navigate to the last student in the list
		Ptr_Last_Student = gPtr_First_Student;
		while (Ptr_Last_Student->Ptr_Next_Student)
			Ptr_Last_Student = Ptr_Last_Student->Ptr_Next_Student;

		// Create new record
		Ptr_New_Student = (SStudent*)malloc(sizeof(SStudent));
		if (!Ptr_New_Student) {
			DPRINTF("Memory allocation failed!\n");
			return;
		}
		Ptr_Last_Student->Ptr_Next_Student = Ptr_New_Student; // Link the new student to the last student
	}

	// Fill the new student record with data
	FILL_RECORD(Ptr_New_Student);

	// Set the next pointer of the new student to NULL
	Ptr_New_Student->Ptr_Next_Student = NULL;
}

// Function to fill a student record with data
void FILL_RECORD(SStudent* RECORD) {
	char TEMP_TEXT[40];

	// Get the ID from the user
	DPRINTF("\nPlease Enter the ID: \n");
	gets(TEMP_TEXT);
	RECORD->Student.ID = atoi(TEMP_TEXT);

	// Get the name from the user
	DPRINTF("\nPlease Enter the student's Name: \n");
	gets(RECORD->Student.NAME);

	// Get the height from the user
	DPRINTF("\nPlease Enter the student's height: \n");
	gets(TEMP_TEXT);
	RECORD->Student.HEIGHT = atof(TEMP_TEXT);
}

// Function to delete a student by ID
int DELETE_STUDENT() {
	char TEMP_TEXT[40];
	unsigned int SELECTED_ID;
	SStudent* Ptr_Previous_Student; // Pointer to the previous student
	SStudent* Ptr_Selected_Student; // Pointer to the selected student

	// Get the selected ID from the user
	DPRINTF("Enter the ID of the student: \n");
	gets(TEMP_TEXT);
	SELECTED_ID = atoi(TEMP_TEXT);

	if (gPtr_First_Student) {
		Ptr_Selected_Student = gPtr_First_Student;
		Ptr_Previous_Student = NULL;
		while (Ptr_Selected_Student) {
			if (Ptr_Selected_Student->Student.ID == SELECTED_ID) {
				if (Ptr_Previous_Student) {
					Ptr_Previous_Student->Ptr_Next_Student = Ptr_Selected_Student->Ptr_Next_Student;
				} else {
					gPtr_First_Student = Ptr_Selected_Student->Ptr_Next_Student;
				}
				printf("Student %s with ID %d has been deleted", Ptr_Selected_Student->Student.NAME, SELECTED_ID);
				free(Ptr_Selected_Student);
				return 1;
			}
			Ptr_Previous_Student = Ptr_Selected_Student;
			Ptr_Selected_Student = Ptr_Selected_Student->Ptr_Next_Student;
		}
		DPRINTF("no student with this ID was found\n");
		return 0;
	}
}

// Function to view all students in the list
void VIEW_STUDENTS() {
	SStudent* Ptr_Current_Student = gPtr_First_Student;
	int count = 0;

	if (gPtr_First_Student == NULL) {
		DPRINTF("The list of the student is empty\n");
	} else {
		while (Ptr_Current_Student) {
			DPRINTF("\nRecord of the student number %d :\n ", count + 1);
			DPRINTF("\t ID: %d :\n ", Ptr_Current_Student->Student.ID);
			DPRINTF("\t Name: %s :\n ", Ptr_Current_Student->Student.NAME);
			DPRINTF("\t Height: %f :\n ", Ptr_Current_Student->Student.HEIGHT);
			Ptr_Current_Student = Ptr_Current_Student->Ptr_Next_Student;
			count++;
		}
	}
}

// Function to delete all students from the list
void DELETE_ALL() {
	SStudent* Ptr_Current_Student = gPtr_First_Student;
	if (gPtr_First_Student == NULL) {
		DPRINTF("The list of the student is already empty\n");
	} else {
		while (Ptr_Current_Student) {
			SStudent* Ptr_to_delete = Ptr_Current_Student;
			Ptr_Current_Student = Ptr_Current_Student->Ptr_Next_Student;
			free(Ptr_to_delete);
		}
		gPtr_First_Student = NULL;
	}
	DPRINTF("All records are deleted\n");
}

// Function to get student data by index
void GET_DATA_FROM_INDEX() {
	int index = 0;
	int counter = 1;
	DPRINTF("\n Enter the index: \n");
	DSCANF("%d", &index);

	SStudent* ptr_current_Student;
	if (!gPtr_First_Student)
		printf("\nThe list in empty \n");
	else {
		ptr_current_Student = gPtr_First_Student;
		while (ptr_current_Student) {
			if (index == counter) {
				PRINTF_DATA_STUDENT(ptr_current_Student);
				return;
			} else {
				ptr_current_Student = ptr_current_Student->Ptr_Next_Student;
				counter++;
			}
		}
		DPRINTF("there is no data in the selected index");
	}
}

// Function to print student data
void PRINTF_DATA_STUDENT(SStudent* RECORD) {
	DPRINTF("\t ID: %d \n ", RECORD->Student.ID);
	DPRINTF("\t Name: %s \n ", RECORD->Student.NAME);
	DPRINTF("\t Height: %f \n ", RECORD->Student.HEIGHT);
}

// Function to get the number of records in the list
void NB_RECORDS() {
	SStudent* ptr_current_Student;
	int count = 1;

	if (!gPtr_First_Student)
		printf("\nThe list in empty \n");
	else {
		ptr_current_Student = gPtr_First_Student;
		while (ptr_current_Student) {
			ptr_current_Student = ptr_current_Student->Ptr_Next_Student;
			count++;
		}
		DPRINTF("\nThe number or records in the list is %d\n", count);
	}
}

// Function to get student data by index from the end
void GET_DATA_FROM_INDEX_REVERSE() {
	SStudent* Ptr_Ref;
	SStudent* Ptr_Mov;
	int index;
	int counter = 0;

	DPRINTF("\n Enter the index: \n");
	DSCANF("%d", &index);

	if (!gPtr_First_Student) {
		DPRINTF("\nThe list in empty \n");
		return;
	}

	Ptr_Ref = gPtr_First_Student;
	Ptr_Mov = gPtr_First_Student;
	while (counter < index) {
		if (!Ptr_Mov) {
			DPRINTF("the index is out of reach");
			return;
		}
		Ptr_Mov = Ptr_Mov->Ptr_Next_Student;
		counter++;
	}
	while (Ptr_Mov) {
		Ptr_Mov = Ptr_Mov->Ptr_Next_Student;
		Ptr_Ref = Ptr_Ref->Ptr_Next_Student;
	}

	PRINTF_DATA_STUDENT(Ptr_Ref);
}

// Function to reverse the linked list
void INVERSE_THE_LIST() {
	SStudent* Ptr_current = gPtr_First_Student;
	SStudent* Ptr_next = NULL;
	SStudent* Ptr_prev = NULL;
	int counter;
	if (!gPtr_First_Student) {
		DPRINTF("\nThe list in empty \n");
		return;
	}

	while (Ptr_current) {
		Ptr_next = Ptr_current->Ptr_Next_Student; // Store next node
		Ptr_current->Ptr_Next_Student = Ptr_prev; // Reverse the current node's pointer
		Ptr_prev = Ptr_current; // Move prev to current node
		Ptr_current = Ptr_next; // Move current to next node
	}
	gPtr_First_Student = Ptr_prev;

	DPRINTF("\nThe reversed list of data:\n");
	while (Ptr_prev) {
		DPRINTF("\nRecord of the student number %d :\n ", counter + 1);
		DPRINTF("\t ID: %d :\n ", Ptr_prev->Student.ID);
		DPRINTF("\t Name: %s :\n ", Ptr_prev->Student.NAME);
		DPRINTF("\t Height: %f :\n ", Ptr_prev->Student.HEIGHT);
		Ptr_prev = Ptr_prev->Ptr_Next_Student;
	}
}
