/*
 * main.c
 *
 *  Created on: Apr 16, 2025
 *      Author: oussa
 */

#include "queue.h"



Student_info Base[70];
Queue_st FIFO;


int main() {
	char input[40]; // Buffer to store user input for menu selection

	// Initialize the queue with the static buffer and capacity of 70
	Queue_init(&FIFO, Base, 70);

	// Display welcome message for the student management system
	DPRINTF("\n Welcome to the Student Management System \n\n");

	// Main loop to keep the program running until user exits
	while (1) {
		// Display menu options for user to choose from
		DPRINTF("\t >>>>>> Choose The Task that you want to perform <<<<<< \n\n");
		DPRINTF("1: Add the Student details manually  \n");
		DPRINTF("2: Add the Student details from a file  \n");
		DPRINTF("3: Find the Student details trough ID \n");
		DPRINTF("4: Find the Student details trough First Name \n");
		DPRINTF("5: Find the Student details trough Course ID\n");
		DPRINTF("6: Find the total number of Students \n");
		DPRINTF("7: Delete the students details trough ID \n");
		DPRINTF("8: Update the students details trough ID \n");
		DPRINTF("9: Show all infos \n");
		DPRINTF("10: Exist the menu \n");
		DPRINTF("  \t ************************\n");
		DPRINTF("\n Enter the choosed option: \n");

		// Read user input as a string
		gets(input);

		// Convert input string to integer for switch statement
		switch (atoi(input)) {
		case 1:
			// Call function to add student details manually
			Add_Student_Manually(&FIFO);
			break;
		case 2:
			// Call function to add students from a file
			Add_Student_from_file(&FIFO);
			break;
		case 3:
			// Call function to search for a student by ID
			find_Student_Trough_ID(&FIFO);
			break;
		case 4:
			// Call function to search for students by first name
			find_Student_Trough_First_Name(&FIFO);
			break;
		case 5:
			// Call function to find students by course ID
			find_Student_Trough_Course_ID(&FIFO);
			break;
		case 6:
			// Call function to display total number of students
			find_Totale_NB_of_Students(&FIFO);
			break;
		case 7:
			// Call function to delete a student by ID
			Delete_Students_Trough_ID(&FIFO);
			break;
		case 8:
			// Call function to update a student's details by ID
			Update_Students_Trough_ID(&FIFO);
			break;
		case 9:
			// Call function to display all student information
			Show_all_Infos(&FIFO);
			break;
		case 10:
			// Exist
			break;
		default:
			// Handle invalid menu option
			DPRINTF("WRONG OPTION \n");
			break;
		}
	}
}


