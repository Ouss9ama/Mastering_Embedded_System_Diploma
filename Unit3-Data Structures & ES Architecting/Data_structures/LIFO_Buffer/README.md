# LIFO Buffer Implementation

## Overview
This project implements a **Last-In-First-Out (LIFO) buffer** in C with both **statically and dynamically allocated buffers**. The program demonstrates pushing and popping elements from two LIFO buffers:  
- **UART_LIFO** (statically allocated)  
- **I2C_LIFO** (dynamically allocated)

## Features
- Static and dynamic memory allocation for LIFO buffers.
- Push and pop operations with status checks.
- Handles buffer overflow and underflow conditions.
- Uses **malloc()** for dynamic allocation and checks for allocation failure.

## Code Structure
- **`main.c`** → Implements the LIFO buffer test with UART_LIFO and I2C_LIFO.
- **`lifo.h`** → Header file containing LIFO structure and function prototypes.
- **`lifo.c`** → LIFO functions implementation (initialization, push, pop).

## Example Output
(Insert an image of your output here)

  
