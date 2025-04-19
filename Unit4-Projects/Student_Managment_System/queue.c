
/*
 * queue.c
 *
 *  Created on: Apr 14, 2025
 *      Author: Oussa
 *
 * Description:
 *     This file implements a circular queue (FIFO) for a student management system.
 *     It provides functions to initialize, enqueue, dequeue, and check the status of the queue,
 *     as well as manage student information (add, delete, update, search, and display).
 *     The queue stores student records with details like ID, name, GPA, and course IDs.
 *     Additional features include manual and file-based student addition, searching by ID,
 *     name, or course, and updating or deleting student records.
 */

#include "queue.h"

/*
 * Function: Queue_init
 * --------------------
 * Initializes the queue structure with a provided buffer and length.
 *
 * Parameters:
 *     fifo   - Pointer to the queue structure to initialize.
 *     buffer - Pointer to the array of Student_info to store queue elements.
 *     length - Maximum number of elements the queue can hold.
 *
 * Returns:
 *     FIFO_NO_ERROR if initialization is successful.
 *     FIFO_NULL if fifo or buffer is NULL.
 *
 * Notes:
 *     Sets base, head, and tail to the start of the buffer, initializes count to 0,
 *     and stores the queue's capacity.
 */
queue_Status_t Queue_init(Queue_st* fifo, Student_info* buffer, unsigned int length) {
	// Validate input pointers to ensure queue and buffer are not NULL
	if (fifo == NULL || buffer == NULL)
		return FIFO_NULL; // Return error if pointers are invalid

	fifo->base = buffer;          // Set base to point to the start of the buffer
	fifo->head = buffer;          // Set head to buffer start (where first enqueue will occur)
	fifo->tail = buffer;          // Set tail to buffer start (where first dequeue will occur)
	fifo->length = length;        // Store the maximum capacity of the queue
	fifo->count = 0;              // Initialize count to 0 (queue is empty)

	return FIFO_NO_ERROR; // Return success status
}

/*
 * Function: ENQUEUE
 * -----------------
 * Adds a student to the queue at the head position.
 *
 * Parameters:
 *     fifo    - Pointer to the queue structure.
 *     student - Student_info structure containing student details to enqueue.
 *
 * Returns:
 *     FIFO_NO_ERROR if the student is added successfully.
 *     FIFO_NULL if the queue or its pointers are uninitialized.
 *     FIFO_FULL if the queue is full.
 *
 * Notes:
 *     Implements circular queue behavior by wrapping head to base when it reaches
 *     the end of the buffer. Increments count after adding the student.
 */
queue_Status_t ENQUEUE(Queue_st* fifo, Student_info student) {
	// Check for invalid queue or uninitialized pointers to ensure queue is valid
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL; // Return error if any pointer is NULL

	// Prevent overflow if queue is full by checking current capacity
	if (FIFO_IS_FULL(fifo) == FIFO_FULL)
		return FIFO_FULL; // Return error if queue cannot accept more students

	// Add student at the head location by copying student data to head pointer
	*(fifo->head) = student;

	// Move head forward (circularly wrap around if needed)
	if (fifo->head == (fifo->base + fifo->length - 1))
		fifo->head = fifo->base;      // Wrap head to start of buffer if at end
	else
		fifo->head++;                 // Move head to next position in buffer

	// Increase number of stored elements to track queue size
	fifo->count++;

	return FIFO_NO_ERROR; // Return success status
}

/*
 * Function: FIFO_IS_FULL
 * ----------------------
 * Checks if the queue is full.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     FIFO_FULL if the queue is full (count equals length).
 *     FIFO_NO_ERROR if the queue is not full.
 *     FIFO_NULL if the queue or its pointers are uninitialized.
 *
 * Notes:
 *     Compares the current count with the queue's capacity to determine fullness.
 */
queue_Status_t FIFO_IS_FULL(Queue_st* fifo) {
	// Validate pointers to ensure queue is properly initialized
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL; // Return error if any pointer is NULL

	// Return full if count equals the capacity, indicating no more space
	if (fifo->count == fifo->length)
		return FIFO_FULL; // Queue is at maximum capacity

	return FIFO_NO_ERROR; // Queue has space for more students
}

/*
 * Function: DEQUEUE
 * -----------------
 * Removes a student from the queue at the tail position and returns their details.
 *
 * Parameters:
 *     fifo    - Pointer to the queue structure.
 *     student - Pointer to Student_info structure to store the dequeued student's details.
 *
 * Returns:
 *     FIFO_NO_ERROR if the student is removed successfully.
 *     FIFO_NULL if the queue or its pointers are uninitialized.
 *     FIFO_EMPTY if the queue is empty.
 *
 * Notes:
 *     Implements circular queue behavior by wrapping tail to base when it reaches
 *     the end of the buffer. Decrements count after removing the student.
 */
queue_Status_t DEQUEUE(Queue_st* fifo, Student_info* student) {
	// Check for invalid queue or uninitialized pointers to ensure queue is valid
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_NULL; // Return error if any pointer is NULL

	// Check if the queue is already empty to avoid dequeuing from empty queue
	if (fifo->count == 0)
		return FIFO_EMPTY; // Return error if no students to dequeue

	// Get the student by copying data from tail to the provided student pointer
	*student = *(fifo->tail);

	// Move tail forward (circularly wrap around if needed)
	if (fifo->tail == (fifo->base + fifo->length - 1))
		fifo->tail = fifo->base;	 // Wrap tail to start of buffer if at end
	else
		fifo->tail++;		// Move tail to next position in buffer

	// Decrease number of stored elements to reflect removal
	fifo->count--;

	return FIFO_NO_ERROR; // Return success status
}

/*
 * Function: Add_Student_Manually
 * -----------------------------
 * Allows the user to manually add a student to the queue by entering details via input.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for student ID, first name, last name, GPA, and five course IDs.
 *     Checks for duplicate IDs using is_ID_unique before enqueuing the student.
 *     Displays queue status (total students, capacity, and remaining space) after adding.
 *     Uses DPRINTF and DSCANF macros for formatted output and input.
 */
void Add_Student_Manually(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold new student data

	// Check if the entered queue is not null to ensure queue is initialized
	if (!fifo || !fifo->base) {
		DPRINTF("Queue is not initialized! \n"); // Inform user of initialization error
		return; // Exit function if queue is invalid
	}

	// Display header for adding student details
	DPRINTF("---------------------------------\n");
	DPRINTF("\t Add the Student Details\n");
	DPRINTF("---------------------------------\n");

	// Prompt and read student ID
	DPRINTF("Enter the student's ID: \n");
	DSCANF("%d", &temp_student_info.ID); // Store user input in ID field

	// Check if the ID is duplicated to ensure uniqueness
	if (is_ID_unique(fifo, temp_student_info.ID) == ID_is_duplicated) {
		DPRINTF("The entered ID already exists \n"); // Inform user of duplicate ID
		return; // Exit function to prevent adding duplicate
	}

	// Prompt and read first name
	DPRINTF("Student First name: \n");
	DSCANF("%s", &temp_student_info.First_name); // Store first name

	// Prompt and read last name
	DPRINTF("Student Second name: \n");
	DSCANF("%s", &temp_student_info.Last_name); // Store last name

	// Prompt and read GPA
	DPRINTF("Enter the student's GPA: \n");
	DSCANF("%f", &temp_student_info.GPA); // Store GPA

	// Prompt and read course IDs
	DPRINTF("Enter the ID of each course>> \n");
	DPRINTF("1st course ID: \n");
	DSCANF("%d", &temp_student_info.Course_ID[0]); // Store first course ID
	DPRINTF("2nd course ID: \n");
	DSCANF("%d", &temp_student_info.Course_ID[1]); // Store second course ID
	DPRINTF("3rd course ID: \n");
	DSCANF("%d", &temp_student_info.Course_ID[2]); // Store third course ID
	DPRINTF("4th course ID: \n");
	DSCANF("%d", &temp_student_info.Course_ID[3]); // Store fourth course ID
	DPRINTF("5th course ID: \n");
	DSCANF("%d", &temp_student_info.Course_ID[4]); // Store fifth course ID

	// Attempt to enqueue the new student
	if (ENQUEUE(fifo, temp_student_info) == FIFO_NO_ERROR) {
		DPRINTF("Student added successfully \n"); // Confirm successful addition
	} else {
		DPRINTF("Failed to add the student! \n"); // Report failure (e.g., queue full)
	}

	// Display queue status
	DPRINTF("[info] the total number of students is %d \n", fifo->count); // Show current student count
	DPRINTF("[info] You can add up to %d students \n", fifo->length); // Show queue capacity
	DPRINTF("[info] you still can add %d students \n", (fifo->length - fifo->count)); // Show remaining space
}

/*
 * Function: is_ID_unique
 * ---------------------
 * Checks if a given student ID is unique in the queue.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *     id   - Student ID to check for uniqueness.
 *
 * Returns:
 *     ID_is_unique if the ID is not found in the queue.
 *     ID_is_duplicated if the ID already exists.
 *
 * Notes:
 *     Iterates through the queue from tail to head, checking each student's ID.
 *     Handles circular queue traversal by wrapping around to base when needed.
 */
ID_st is_ID_unique(Queue_st * fifo, int id) {
	Student_info* ID_ptr_spotter = fifo->tail; // Start scanning from tail (first valid student)

	// Iterate through all students in the queue
	for (int i = 0; i < fifo->count; i++) {
		if (ID_ptr_spotter->ID == id) { // Check if current student's ID matches input ID
			return ID_is_duplicated; // Return duplicated status if match found
		}

		// Move to next student, handling circular queue
		if (ID_ptr_spotter == (fifo->base + fifo->length - 1)) {
			ID_ptr_spotter = fifo->base; // Wrap to start of buffer if at end
		} else {
			ID_ptr_spotter++; // Move to next student
		}
	}

	return ID_is_unique; // Return unique status if no match found
}

/*
 * Function: find_Student_Trough_ID
 * -------------------------------
 * Searches for a student by their ID and displays their details if found.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for a student ID, then iterates through the queue to find a match.
 *     Displays the student's name, GPA, and course IDs if found; otherwise, reports no match.
 *     Handles circular queue traversal.
 */
void find_Student_Trough_ID(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold input ID
	Student_info * ID_ptr_spotter; // Pointer to scan through queue
	ID_ptr_spotter = fifo->tail; // Start from tail (first valid student)

	// Prompt and read student ID to search for
	DPRINTF("Add the ID of the student \n");
	DSCANF("%d", &temp_student_info.ID); // Store input ID

	// Iterate through all students in the queue
	for (int i = 0; i < fifo->count; i++) {
		if (ID_ptr_spotter->ID == temp_student_info.ID) { // Check if ID matches
			DPRINTF("Student found\n"); // Confirm student found
			DPRINTF("First Name is %s\n", ID_ptr_spotter->First_name); // Display first name
			DPRINTF("Last Name is %s\n", ID_ptr_spotter->Last_name); // Display last name
			DPRINTF("The GPA is %.2f\n", ID_ptr_spotter->GPA); // Display GPA
			DPRINTF("The IDs of his registered courses are >>\n"); // Display course header
			for (int j = 0; j < 5; j++) { // Loop through all course IDs
				DPRINTF("Course %d : %d \n", j + 1, ID_ptr_spotter->Course_ID[j]); // Display each course ID
			}
			return; // Exit function after displaying student details
		}

		// Move to next student, handling circular queue
		if (ID_ptr_spotter == (fifo->base + fifo->length - 1)) {
			ID_ptr_spotter = fifo->base; // Wrap to start of buffer if at end
		} else {
			ID_ptr_spotter++; // Move to next student
		}
	}

	DPRINTF("NO student found with this ID!"); // Report no match found
}

/*
 * Function: find_Student_Trough_First_Name
 * ---------------------------------------
 * Searches for students by their first name and displays their details if found.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for a first name, then iterates through the queue to find matches.
 *     Displays each matching student's details (name, ID, GPA, courses).
 *     Reports if no students are found with the given name.
 *     Uses strcmp for string comparison and handles circular queue traversal.
 */
void find_Student_Trough_First_Name(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold input name
	Student_info * Name_ptr_spotter; // Pointer to scan through queue
	Name_ptr_spotter = fifo->tail; // Start from tail (first valid student)

	// Prompt and read first name to search for
	DPRINTF("Add the Name of the student \n");
	DSCANF("%s", &temp_student_info.First_name); // Store input first name

	// Iterate through all students in the queue
	for (int i = 0; i < fifo->count; i++) {
		// Check if first name matches using string comparison
		if (strcmp(Name_ptr_spotter->First_name, temp_student_info.First_name) == 0) {
			DPRINTF("Student found\n"); // Confirm student found
			DPRINTF("First Name is %s\n", Name_ptr_spotter->First_name); // Display first name
			DPRINTF("Last Name is %s\n", Name_ptr_spotter->Last_name); // Display last name
			DPRINTF("ID is %d\n", Name_ptr_spotter->ID); // Display ID
			DPRINTF("The GPA is %.2f\n", Name_ptr_spotter->GPA); // Display GPA
			DPRINTF("The IDs of his registered courses are >>\n"); // Display course header
			for (int j = 0; j < 5; j++) { // Loop through all course IDs
				DPRINTF("Course %d : %d \n", j + 1, Name_ptr_spotter->Course_ID[j]); // Display each course ID
			}
			DPRINTF("\n\n"); // Add spacing for readability
		}

		// Move to next student, handling circular queue
		if (Name_ptr_spotter == (fifo->base + fifo->length - 1)) {
			Name_ptr_spotter = fifo->base; // Wrap to start of buffer if at end
		} else {
			Name_ptr_spotter++; // Move to next student
		}
	}

	DPRINTF("NO student found with this first name!"); // Report no matches found
}

/*
 * Function: find_Student_Trough_Course_ID
 * --------------------------------------
 * Finds students enrolled in a specific course and displays their details.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for a course ID, then checks each student's course IDs.
 *     Displays name, ID, and GPA for students enrolled in the course.
 *     Uses a flag to track if any matches are found; reports if no matches exist.
 *     Handles circular queue traversal.
 */
void find_Student_Trough_Course_ID(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold input course ID
	Student_info * Course_ptr_spotter = fifo->tail; // Start from tail (first valid student)
	char flag_course = 0; // Flag to track if any students are found with the course

	// Prompt and read course ID to search for
	DPRINTF("Enter the course ID \n");
	DSCANF("%d", &temp_student_info.Course_ID[0]); // Store input course ID

	// Iterate through all students in the queue
	for (int i = 0; i < fifo->count; i++) {
		// Check each of the student's course IDs
		for (int j = 0; j < 5; j++) {
			if (Course_ptr_spotter->Course_ID[j] == temp_student_info.Course_ID[0]) { // Match found
				DPRINTF("First Name is %s\n", Course_ptr_spotter->First_name); // Display first name
				DPRINTF("Last Name is %s\n", Course_ptr_spotter->Last_name); // Display last name
				DPRINTF("ID is %d\n", Course_ptr_spotter->ID); // Display ID
				DPRINTF("The GPA is %.2f\n", Course_ptr_spotter->GPA); // Display GPA
				DPRINTF("\n"); // Add spacing for readability
				flag_course = 1; // Set flag to indicate at least one match
			}
		}

		// Move to next student, handling circular queue
		if (Course_ptr_spotter == (fifo->base + fifo->length - 1)) {
			Course_ptr_spotter = fifo->base; // Wrap to start of buffer if at end
		} else {
			Course_ptr_spotter++; // Move to next student
		}
	}

	// Check if no students were found with the course ID
	if (!flag_course)
		DPRINTF("Course ID was not found\n"); // Report no matches
}

/*
 * Function: Delete_Students_Trough_ID
 * ----------------------------------
 * Deletes a student from the queue based on their ID.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for a student ID, then locates the student in the queue.
 *     Shifts subsequent students to fill the gap, effectively removing the student.
 *     Updates head and decrements count to maintain queue integrity.
 *     Reports if the ID is not found or if deletion is successful.
 */
void Delete_Students_Trough_ID(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold input ID
	Student_info * ID_current = fifo->tail; // Start from tail (first valid student)
	char id_found = 0; // Flag to track if student ID is found

	// Prompt and read student ID to delete
	DPRINTF("Enter the student ID \n");
	DSCANF("%d", &temp_student_info.ID); // Store input ID

	// Iterate through queue to find student with matching ID
	for (int i = 0; i < fifo->count; i++) {
		if (ID_current->ID == temp_student_info.ID) { // Check if ID matches
			id_found = 1; // Set flag to indicate student found
			break; // Exit loop to keep ID_current at found student
		}

		// Move to next student, handling circular queue
		if (ID_current == (fifo->base + fifo->length - 1)) {
			ID_current = fifo->base; // Wrap to start of buffer if at end
		} else {
			ID_current++; // Move to next student
		}
	}

	// Check if ID was not found
	if (!id_found)
		DPRINTF("The student with this ID was not found \n"); // Report no match

	Student_info * ID_next = ID_current; // Pointer to next student for shifting
	// Loop to replace the current student with the next to delete it
	for (int j = 0; j < fifo->count - 1; j++) {
		// Move to next student
		if (ID_next == fifo->base + fifo->length - 1) // If next student is at end of queue
		{
			ID_next = fifo->base; // Wrap to start of buffer
		} else {
			ID_next++; // Move to next student
		}

		*ID_current = *ID_next; // Copy next student's data to current position
		// Move the current pointer forward
		if (ID_current == fifo->base + fifo->length - 1)
			ID_current = fifo->base; // Wrap to start of buffer
		else
			ID_current++; // Move to next position
	}

	// Update head to reflect removal
	if (fifo->head == fifo->base)
		fifo->head = fifo->base + fifo->length - 1; // Wrap head to end of buffer
	else
		fifo->head--; // Move head back one position

	// Decrease count to reflect deletion
	fifo->count--;

	DPRINTF("Student deleted successfully. \n"); // Confirm deletion
}

/*
 * Function: Update_Students_Trough_ID
 * ----------------------------------
 * Updates a student's details based on their ID via a menu-driven interface.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Prompts the user for a student ID, then locates the student.
 *     Offers a menu to update first name, last name, ID, GPA, or course IDs.
 *     Checks for duplicate IDs when updating the ID.
 *     Continues until the user exits the menu.
 *     Reports if the ID is not found.
 */
void Update_Students_Trough_ID(Queue_st* fifo) {
	Student_info temp_student_info; // Temporary structure to hold input ID
	Student_info * ID_current = fifo->tail; // Start from tail (first valid student)
	int temp_ID = 0; // Temporary variable for new ID input
	char ID_found_flag = 0; // Flag to track if student ID is found

	// Prompt and read student ID to update
	DPRINTF("Enter the student ID \n");
	DSCANF("%d", &temp_student_info.ID); // Store input ID

	// Iterate through queue to find student with matching ID
	for (int i = 0; i < fifo->count; i++) {
		if (ID_current->ID == temp_student_info.ID) { // Check if ID matches
			ID_found_flag = 1; // Set flag to indicate student found
			int input; // Variable to store user menu choice
			while (1) { // Loop until user exits menu
				// Display update menu options
				DPRINTF("1. first name \n");
				DPRINTF("2. last name\n");
				DPRINTF("3. id\n");
				DPRINTF("4. Gpa\n");
				DPRINTF("5. Course ID\n");
				DPRINTF("6. Exit the menu\n");

				DSCANF("%d", &input); // Read user choice
				switch (input) { // Handle menu selection
				case 1:
					DPRINTF("Enter the updated first name\n:");
					DSCANF("%s", &ID_current->First_name); // Update first name
					break;
				case 2:
					DPRINTF("Enter the updated last name\n:");
					DSCANF("%s", &ID_current->Last_name); // Update last name
					break;
				case 3:
					DPRINTF("Enter the updated ID\n:");
					DSCANF("%d", &temp_ID); // Read new ID
					// Check if new ID is unique
					if (is_ID_unique(fifo, temp_ID) == ID_is_unique) {
						ID_current->ID = temp_ID; // Update ID
					} else {
						DPRINTF("the ID already exists \n"); // Report duplicate ID
						break;
					}
					break;
				case 4:
					DPRINTF("Enter the updated GPA\n:");
					DSCANF("%f", &ID_current->GPA); // Update GPA
					break;
				case 5:
					// Update all course IDs
					DPRINTF("Enter the updated course ID2\n:");
					for (int j = 0; j < 5; j++) {
						DPRINTF(" COURSE %d ID: \n", j + 1); // Prompt for each course
						DSCANF("%d", &ID_current->Course_ID[j]); // Store new course ID
					}
					break;
				case 6:
					DPRINTF("Exiting the menu now\n"); // Confirm menu exit
					return;
				default:
					DPRINTF("Invalid choice, please try again.\n"); // Handle invalid input
				}
			}
		}

		// Move to next student, handling circular queue
		if (ID_current == (fifo->base + fifo->length - 1))
			ID_current = fifo->base; // Wrap to start of buffer
		else
			ID_current++; // Move to next student
	}

	// Check if ID was not found
	if (!ID_found_flag)
		DPRINTF("NO student found with this ID!\n"); // Report no match
}

/*
 * Function: find_Totale_NB_of_Students
 * -----------------------------------
 * Displays the total number of students, queue capacity, and remaining space.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Provides a summary of the queue's current state.
 */
void find_Totale_NB_of_Students(Queue_st* fifo) {
	// Display current number of students in queue
	DPRINTF("[info] the total number of students is %d \n", fifo->count);
	// Display maximum queue capacity
	DPRINTF("[info] You can add up to %d students \n", fifo->length);
	// Display remaining space in queue
	DPRINTF("[info] you still can add %d students \n", (fifo->length - fifo->count));
}

/*
 * Function: Show_all_Infos
 * -----------------------
 * Displays the details of all students in the queue.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Iterates through the queue from tail to head, printing each student's
 *     name, ID, GPA, and course IDs. Handles circular queue traversal.
 */
void Show_all_Infos(Queue_st* fifo) {
	Student_info* ptr_show_all_info = fifo->tail; // Start from tail (first valid student)

	if(fifo->count == 0)
	{
		DPRINTF(">>----the queue is already empty-----<<\n\n");
		return;
	}

	// Iterate through all students in the queue
	for (int i = 0; i < fifo->count; i++) {
		// Display header for student details
		DPRINTF("---------------------------------\n");
		DPRINTF("Student nb %d \n", i + 1); // Show student number
		DPRINTF("---------------------------------\n");

		DPRINTF(">>First Name is %s\n", ptr_show_all_info->First_name); // Display first name
		DPRINTF(">>Last Name is %s\n", ptr_show_all_info->Last_name); // Display last name
		DPRINTF(">>ID is %d\n", ptr_show_all_info->ID); // Display ID
		DPRINTF(">>The GPA is %.2f\n", ptr_show_all_info->GPA); // Display GPA
		DPRINTF(">>The IDs of his registered courses are:\n"); // Display course header
		// Loop through all course IDs
		for (int j = 0; j < 5; j++) {
			DPRINTF("\t-Course %d : %d \n", j + 1, ptr_show_all_info->Course_ID[j]); // Display each course ID
		}
		DPRINTF("\n\n"); // Add spacing for readability

		// Move to next student, handling circular queue
		if (ptr_show_all_info == fifo->base + fifo->length - 1) {
			ptr_show_all_info = fifo->base; // Wrap to start of buffer
		} else {
			ptr_show_all_info++; // Move to next student
		}
	}
}

/*
 * Function: Add_Student_from_file
 * ------------------------------
 * Adds students to the queue by reading details from a text file.
 *
 * Parameters:
 *     fifo - Pointer to the queue structure.
 *
 * Returns:
 *     None (void function).
 *
 * Notes:
 *     Reads student details (ID, first name, last name, GPA, and five course IDs)
 *     from "text_file.txt". Checks for duplicate IDs before enqueuing.
 *     Reports success or failure for each student and handles file errors.
 *     Assumes the file format matches the expected input structure.
 */
void Add_Student_from_file(Queue_st* fifo) {
	Student_info temp_studentt; // Temporary structure to hold student data from file

	// Open text file for reading
	FILE* file = fopen("text_file.txt", "r");

	// Check if file opened successfully
	if (!file) {
		DPRINTF("Error while opening the file\n"); // Report file opening error
		return; // Exit function if file cannot be opened
	}

	// Read student data from file until end or error
	while (fscanf(file, "%d %s %s %f %d %d %d %d %d",
			&temp_studentt.ID, // Read student ID
			&temp_studentt.First_name, // Read first name
			&temp_studentt.Last_name, // Read last name
			&temp_studentt.GPA, // Read GPA
			&temp_studentt.Course_ID[0], // Read first course ID
			&temp_studentt.Course_ID[1], // Read second course ID
			&temp_studentt.Course_ID[2], // Read third course ID
			&temp_studentt.Course_ID[3], // Read fourth course ID
			&temp_studentt.Course_ID[4]) == 9) { // Read fifth course ID, check for 9 successful reads
		// Check if ID is unique before adding
		if (is_ID_unique(fifo, temp_studentt.ID) == ID_is_duplicated) {
			DPRINTF("[ERROR] The ID %d already exists\n", temp_studentt.ID); // Report duplicate ID
			continue;
		}

		// Attempt to enqueue the student
		queue_Status_t status = ENQUEUE(fifo, temp_studentt);
		if (status == FIFO_NO_ERROR) {
			DPRINTF("[INFO] The student with ID %d was added successfully\n", temp_studentt.ID); // Confirm success
		} else if (status == FIFO_FULL) {
			DPRINTF("[ERROR] The queue is full"); // Report queue full error
		}
	}

	// Close the file
	fclose(file);
}

