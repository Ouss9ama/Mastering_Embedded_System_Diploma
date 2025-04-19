# Student Management System

The **Student Management System** is a console-based C application that manages student records using a circular queue (FIFO) data structure. It allows users to add, search, update, delete, and display student information, including IDs, names, GPAs, and course enrollments. Designed for educational environments, the system supports manual data entry and file-based input, making it suitable for small-scale student record management. This project demonstrates proficiency in C programming, data structures, and file handling.

## Features

- **Manual Student Addition**: Add student details (ID, name, GPA, courses) via console input, with unique ID validation.
- **File-Based Input**: Import student data from `text_file.txt`, skipping duplicate IDs.
- **Search Capabilities**:
  - Find students by ID, first name, or course ID.
- **Data Modification**:
  - Delete students by ID.
  - Update student details (name, ID, GPA, courses) via a menu.
- **Reporting**:
  - Display all student records or queue status (total students, capacity).
- **Error Handling**:
  - Validates queue state (full/empty) and file operations.
  - Ensures unique student IDs.

## Requirements

- **C Compiler**: GCC, Clang, or any standard C compiler (e.g., MinGW for Windows).
- **Operating System**: Windows, Linux, or macOS (note: `conio.h` may limit portability).
- **Text Editor/IDE**: VS Code, Code::Blocks, or similar for editing and building.
- **Input File**: A `text_file.txt` file for file-based input (optional).


1. **Interact with the Menu**:

   - Choose options 1–9 to perform tasks:
     - **1**: Add a student manually.
     - **2**: Add students from `text_file.txt`.
     - **3**: Search by student ID.
     - **4**: Search by first name.
     - **5**: Search by course ID.
     - **6**: View total students and queue status.
     - **7**: Delete a student by ID.
     - **8**: Update a student’s details.
     - **9**: Display all student records.
   - Note: Option 10 (exit) is listed but not implemented; use `Ctrl+C` to exit.

2. **Example Workflow**:

   - Select option 1, enter student details (e.g., ID: 1001, Name: Alice Smith, GPA: 3.8, Courses: 201–205).
   - Use option 2 to import students from `text_file.txt`.
   - Search for a student by ID (option 3) or view all records (option 9).

## File Structure

- `queue.h`: Header file defining structures (`Student_info`, `Queue_st`), enums, macros (`DPRINTF`, `DSCANF`), and function prototypes.
- `queue.c`: Implementation of queue operations and student management functions.
- `main.c`: Main program with the menu-driven interface and queue initialization.
- `text_file.txt` (optional): Input file for batch student addition.

 
 
**Author**: Oussa\
**Date**: April 18, 2025