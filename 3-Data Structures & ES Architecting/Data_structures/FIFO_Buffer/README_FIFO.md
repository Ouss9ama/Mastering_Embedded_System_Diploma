# FIFO Buffer

This project implements a simple circular FIFO (First In, First Out) buffer using a statically allocated array. It provides basic operations for adding, removing, and checking elements in the buffer.

## Features
- Efficient circular buffer implementation
- Supports enqueue (insertion) and dequeue (removal) operations
- Handles full and empty buffer conditions
- Provides a simple interface for embedded applications

## Usage
1. **Initialize the FIFO** with a pre-allocated buffer.
2. **Enqueue elements** into the buffer.
3. **Dequeue elements** when needed.
4. **Check buffer status** to determine if it's full or empty.

## Example Workflow
- Define a buffer array.
- Initialize the FIFO structure.
- Add and remove elements as needed.
- Use status checks to handle edge cases.

## Notes
- The buffer size must be pre-defined.
- The implementation follows a circular approach to optimize space.

This module is useful for embedded systems where dynamic memory allocation is not preferred.

