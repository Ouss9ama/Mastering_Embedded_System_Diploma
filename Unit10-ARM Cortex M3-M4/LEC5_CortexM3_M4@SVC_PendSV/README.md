# Task Switching and Privilege Management in ARM Cortex-M3

## Overview
This lab demonstrates task switching and privilege management in **ARM Cortex-M3** using the **STM32F103** microcontroller. It sets up two tasks (Task A and Task B), assigns them separate stack regions, and switches execution between them using the **Process Stack Pointer (PSP)** and **Main Stack Pointer (MSP)**.

## Features
- **Manual Stack Management:** Allocates separate stack regions for Task A and Task B.
- **Privilege Level Switching:** Uses **SVC (Supervisor Call) exception** to switch between **privileged** and **unprivileged** modes.
- **Interrupt-Based Task Scheduling:** Uses an external interrupt (EXTI9) to switch between tasks.
- **Assembly Macros:** Inline assembly macros handle stack switching and privilege management.

## Stack Management
The stack memory is manually allocated as follows:
- **Main Stack (MSP):** Reserved 512 bytes for OS use.
- **Task A Stack (PSP_TA):** Allocated 100 bytes.
- **Task B Stack (PSP_TB):** Allocated 100 bytes.

Memory layout:
```
|------------------------|  <- _S_MSP (Main Stack Start)
| OS Stack (512 bytes)  |
|------------------------|  <- _E_MSP
| Task A Stack (100 B)  |
|------------------------|  <- _S_PSP_TA
| Task B Stack (100 B)  |
|------------------------|  <- _S_PSP_TB
```

## Task Switching Logic
Task switching is handled in `MainOS()` based on external interrupts:
1. **Task A Execution:**
   - Switches to **Process Stack (PSP)**
   - Executes in **unprivileged mode**
   - Returns to **privileged mode** via SVC
   - Switches back to **Main Stack (MSP)**
2. **Task B Execution:**
   - Similar to Task A but with a different stack pointer.

### Key Assembly Instructions
| Macro | Description |
|--------|-------------|
| `OS_SET_PSP(add)` | Loads a new **PSP** stack pointer |
| `OS_SWITCH_SP_TO_PSP` | Switches stack pointer to **PSP** |
| `OS_SWITCH_SP_TO_MSP` | Switches stack pointer to **MSP** |
| `OS_Generate_Exception` | Triggers **SVC** exception to regain privileges |
| `Switch_CPU_Access_to_Priviledge` | Sets **CONTROL[0] = 0** for privileged mode |
| `Switch_CPU_Access_to_UnPriviledge` | Sets **CONTROL[0] = 1** for unprivileged mode |

 
