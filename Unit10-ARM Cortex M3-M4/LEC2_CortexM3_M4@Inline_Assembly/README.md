# Inline Assembly in STM32 (Control & IPSR Registers)

## Overview
This project demonstrates how to use **inline assembly** in **C** to read the **CONTROL** and **IPSR** registers of an STM32 microcontroller using the ARM Cortex-M3/M4 architecture. The code is written in **STM32CubeIDE** and debugged in **Keil uVision**.

## Features
- Reads the **CONTROL** register in **Thread mode** and stores its value in a C variable.
- Reads the **IPSR** register in **Handler mode** during an **EXTI interrupt** and stores its value in a C variable.
- Implements an external interrupt (EXTI) on **PB9** using **GPIO and NVIC**.
- Uses **LCD display** to visualize outputs.

 

 

## Inline Assembly Implementation

### 1. Reading the CONTROL Register (Thread Mode)
In the `main()` function, the **CONTROL** register is read using inline assembly:

```c
__asm("MRS %0, CONTROL"
     : "=r" (CR)); // Store CONTROL register value in CR variable
```
- The `MRS` (Move to Register from Special Register) instruction moves the **CONTROL** register value into a general-purpose register.
- The **C variable `CR`** stores the result.

### 2. Reading the IPSR Register (Handler Mode)
When an external interrupt on **PB9** occurs, the **IPSR** register is read in the **EXTI9PB9_CALLBACK()** function:

```c
__asm("MRS %0, IPSR"
     : "=r" (IPSRS)); // Store IPSR register value in IPSRS variable
```
- The **IPSR (Interrupt Program Status Register)** tells whether the CPU is handling an exception.
- The retrieved value is stored in the **IPSRS variable**.

## Interrupt Handling (EXTI on PB9)
- **GPIOB Pin 9** is configured as an external interrupt.
- When an interrupt occurs, the **EXTI9PB9_CALLBACK()** function is triggered.
- The **IPSR register value** is read and stored.
- The **IRQ flag** is set for further processing.


## Expected Output
- **CONTROL register value** is read and stored when in **Thread Mode**.
- **PB9 interrupt triggers IPSR reading**.
- **IPSR register value** is captured inside the **Interrupt Handler**.

 

 
