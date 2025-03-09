 # CPU Modes and Debugging in STM32

## Overview

This repository contains two labs demonstrating the behavior of **Thread Mode** and **Handler Mode** in STM32 development. The projects were written in **STM32CubeIDE** and debugged using **Keil uVision**.

---

## Lab 1: Observing CONTROL and IPSR Registers

### Description

This lab focuses on understanding **Privileged and Unprivileged execution modes** in ARM Cortex-M3/M4. It also explores different stack pointer (MSP/PSP) configurations. The transitions between **Thread Mode** and **Handler Mode** were marked and analyzed through debugging in Keil.

### Features

- Demonstrates switching between **Privileged** and **Unprivileged** modes.
- Observes changes in the **CONTROL** and **IPSR** registers during execution.
- Monitors **stack pointer transitions (MSP vs. PSP)**.
- Uses **EXTI (External Interrupt)** for mode-switching demonstration.
- Displays results on an LCD.

### Key Concepts

- **Privileged Mode**: Full access to system resources and registers.
- **Unprivileged Mode**: Restricted access, limiting system-level control.
- **Main Stack Pointer (MSP) vs. Process Stack Pointer (PSP)**: Understanding different stack pointer roles in mode switching.
- **Thread Mode**: Normal execution mode for user applications.
- **Handler Mode**: Activated when an exception or interrupt occurs.
- **IPSR Register**: Indicates the current exception number.
- **CONTROL Register**: Determines the execution privilege level and stack usage.

 
