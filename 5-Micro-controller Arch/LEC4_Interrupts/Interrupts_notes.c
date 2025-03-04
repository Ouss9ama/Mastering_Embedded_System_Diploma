Updated Summary of the ISR Process
1-Receive interrupt signal.

2-Complete current instruction.

3-Save Program Counter (PC) and CPU state (registers, flags) onto the stack.

4-Determine interrupt source (via vector table or polling).

5-Send acknowledgment to the device.

6-Clear interrupt status bit (if required).

7-Jump to the ISR address.

8-Execute the ISR.

9-Restore CPU state from the stack.

10-Return to the main program by loading the saved PC.

11-Continue normal execution.

***************************************************
-Interrupt latency is defined as the time elapsed from when an interrupt signal is generated by a device
 or event until the CPU starts executing the interrupt handling process (i.e., the first instruction of the Interrupt Service Routine or ISR)
-In real-time systems, minimizing interrupt latency is critical
*************************************************************
- "functional description" & "register" sections are necessary
-Registers:

-Use EXTI_IMR for interrupts.

-Use EXTI_EMR for events.
**********************************************************
"EXTI Configuration Overview"
1-Enable the EXTI Line:
	-Set the corresponding bit in the EXTI_IMR (Interrupt Mask Register) to enable the interrupt.
	-Set the corresponding bit in the EXTI_RTSR (Rising Trigger Selection Register) or EXTI_FTSR (Falling Trigger Selection Register)
2-Enable the NVIC:
	-Enable the interrupt line in the NVIC using the NVIC_ISER (Interrupt Set Enable Register)
3-Clear the pending bit in the EXTI_PR.
*******************************************************
Why Configure Pin A0 as an Input?
-EXTI0 (External Interrupt 0) is tied to Pin A0 in your setup. This means that EXTI0 will monitor the state of Pin A0 for changes (e.g., a rising edge, falling edge, or both).

-For EXTI0 to detect these changes, Pin A0 must be configured as an input pin. This allows the pin to read the voltage level applied to it by an external source (like a push button).
*********************************************
AFIO_EXTICR1 Explanation
The register AFIO_EXTICR1 is used to configure the mapping for EXTI0, EXTI1, EXTI2, and EXTI3.
Each EXTI line (0 to 3) has 4 bits in the register to select the GPIO port.
************************************************
-----STEPS OF THE LAB 1-------------STM32F103C6
1. Enable Required Clocks
Enable the clock for GPIOA (to use PA0 for the button and PA13 for the LED).
Enable the clock for AFIO (to configure the EXTI mapping).
2. Configure GPIO Pins
PA0 (Button Pin):
Configure PA0 as input mode.
Set the input type to floating input or input with pull-up/pull-down (optional).
PA13 (LED Pin):
Configure PA13 as output mode.
Set the output type to push-pull (optional, depends on requirements).
3. Configure AFIO (EXTI Mapping)
Use the AFIO_EXTICR1 register to map EXTI0 to PA0.
Select GPIO port A as the source input for EXTI0.
4. Configure EXTI Registers
Interrupt Mask Register (IMR):
Unmask the EXTI0 line to allow the interrupt signal to pass through.
Rising/Falling Trigger Selection Register (RTSR/FTSR):
Configure the trigger type (e.g., rising edge, falling edge, or both).
Rising edge: Trigger interrupt when the button is pressed.
Falling edge: Trigger interrupt when the button is released.
5. Enable NVIC Interrupt
Enable the EXTI0 interrupt line in the NVIC (Nested Vector Interrupt Controller).
Set the priority for the EXTI0 interrupt (optional, but recommended for proper interrupt handling).
6. Write the Interrupt Service Routine (ISR)
Implement the ISR for EXTI0.
In the ISR:
Clear the pending bit for EXTI0 to prevent repeated interrupts.
Toggle the state of the LED connected to PA13.

 ******************************************************
 -  the main difference is that STM32 needs explicit clock and AFIO configuration, 
 while ATmega32 directly supports INT0 on PD2 without extra mapping
 	***********************************
 --------STEPS OF THE lab2------------------ATmega32
 Here’s how you should configure it on ATmega32:
 Steps in Correct Order
1. "Configure Pins as Inputs or Outputs":
Configure PD5 , PD6 , and PD7 as outputs for the LEDs:
Set the corresponding bits in the DDRD register to 1 to make these pins outputs.
Configure PD2 and PD3 as inputs for INT0 and INT1 :
Clear the corresponding bits in the DDRD register to make these pins inputs.
Configure PB2 as an input for INT2 :
Clear the corresponding bit in the DDRB register to make this pin an input.
2. "Initialize External Interrupts":
Configure INT0 (PD2) to trigger on any logical change :
Set the ISC00 bit in the MCUCR register.
Enable INT0 by setting the INT0 bit in the GICR register.
Configure INT1 (PD3) to trigger on a rising edge :
Set both the ISC11 and ISC10 bits in the MCUCR register.
Enable INT1 by setting the INT1 bit in the GICR register.
Configure INT2 (PB2) to trigger on a falling edge :
Clear the ISC2 bit in the MCUCSR register.
Enable INT2 by setting the INT2 bit in the GICR register.
3. "Enable Global Interrupts":
Enable global interrupts by setting the I-bit (bit 7) in the SREG register:
Use the traditional method: SREG |= (1 << 7).
4. "Define Interrupt Service Routines (ISRs)":
Define the ISR for INT0 (PD2) :
When triggered, turn on LED0 (PD5) for 1 second and then turn it off.
Define the ISR for INT1 (PD3) :
When triggered, turn on LED1 (PD6) for 1 second and then turn it off.
Define the ISR for INT2 (PB2) :
When triggered, turn on LED2 (PD7) for 1 second and then turn it off.
5. "Main Loop":
Continuously turn off all LEDs in the main loop:
Clear the bits corresponding to PD5 , PD6 , and PD7 in the PORTD register to ensure the LEDs remain off unless explicitly turned on by an interrupt.
********************************************************
1. Why is there no base and offset address of the clock or registers in the ATmega32 datasheet, unlike in STM32F103C6?
The difference lies in the architecture and design philosophy of the microcontrollers:

ATmega32 (AVR Architecture):
-The ATmega32 is an 8-bit microcontroller based on the AVR architecture. It has a simpler design compared to ARM Cortex-M-based microcontrollers like the STM32F103C6.
-In the ATmega32, peripherals (like GPIO, timers, interrupts, etc.) are directly memory-mapped, and their registers are accessed using predefined names (e.g., PORTD, DDRD, PIND, MCUCR, etc.). These names are defined in the AVR toolchain headers (e.g., avr/io.h), so you dont need to manually calculate base addresses or offsets.
-There is no separate "clock tree" configuration like in STM32 because the ATmega32 uses a single system clock for all peripherals. You configure the clock source (e.g., internal RC oscillator, external crystal) using fuse bits during programming, but this is not done dynamically in software.
-The datasheet provides detailed information about the register names and their bit fields, which are sufficient for programming the microcontroller.
STM32F103C6 (ARM Cortex-M Architecture):
-The STM32F103C6 is a 32-bit microcontroller based on the ARM Cortex-M3 core. It has a more complex architecture with multiple buses (AHB, APB1, APB2) and peripherals that require clock gating and configuration.
-In STM32, peripherals are accessed through base addresses and offsets, and you often use libraries (like HAL or LL) or manually configure registers to enable clocks, configure GPIOs, and set up interrupts.
-The clock tree in STM32 is highly configurable, allowing you to enable/disable clocks for specific peripherals, set prescalers, and configure PLLs. This flexibility requires explicit clock configuration in software.
****************************************
the ATmega32 (and most AVR microcontrollers), you configure a pin as an output or input
 by setting or clearing the corresponding bit in the Data Direction Register (DDR) for the port:
 -DDRD |= (1 << PD5);  // Set PD5 as output
 -DDRD &= ~(1 << PD2); // Clear PD2 to set it as input

 Example for Port D:
DDRD controls the direction of all pins on Port D (PD0 to PD7).
If DDRD = 0b00100100, then:
PD5 and PD2 are outputs (bits 5 and 2 are 1).
All other pins (PD7, PD6, PD4, PD3, PD1, PD0) are inputs (bits 7, 6, 4, 3, 1, 0 are 0).