Macro Definition (#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE))


#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
This pointer points to a memory location starting at 0x40010800, where a GPIO_TypeDef structure is laid out
-This macro defines GPIOA as a pointer to a GPIO_TypeDef structure, starting at the memory address GPIOA_BASE.
-Here’s what happens step by step:
	1.GPIOA_BASE is the base address of the GPIOA peripheral (0x40010800UL).
	2.(GPIO_TypeDef *) casts the base address to a pointer of type GPIO_TypeDef *. 
	This tells the compiler to treat the memory at 0x40010800UL as if it were a GPIO_TypeDef structure.
	3.The macro GPIOA now acts as a shorthand for accessing the GPIOA peripherals registers.

-volatile Keyword: This tells the compiler that the values of these registers can change at any time (e.g., by hardware),
 so it should not optimize out accesses to these registers

 -"The first member of the structure (CRL) is at 0x40010800, the second member (CRH) is at 0x40010804, and so on."

file layout.h
 //-----------------------------
//Includes
//-----------------------------
//-----------------------------
//User type definitions (structures)
//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------
/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

-void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_PinConfig_t* PinConfig)
example:

GPIO Driver Black Box Analysis
1. Inputs to the GPIO Driver
The GPIO driver requires the following inputs to configure and control GPIO pins:

a. GPIO Configuration Structure (GPIO_PinConfig_t)
This structure is passed to the MCAL_GPIO_Init function to configure a GPIO pin. It contains the following fields:

GPIO_PinNumber: Specifies the GPIO pin to configure (e.g., GPIO_PIN_0, GPIO_PIN_1, etc.).

Range: GPIO_PIN_0 to GPIO_PIN_15 (or GPIO_PIN_ALL for all pins).

Purpose: Identifies which pin to configure.

GPIO_MODE: Specifies the operating mode of the GPIO pin.

Options:

GPIO_MODE_ANALOG: Analog mode (for ADC/DAC).

GPIO_MODE_INPUT_FLO: Floating input (no pull-up/pull-down).

GPIO_MODE_INPUT_PU: Input with pull-up resistor.

GPIO_MODE_INPUT_PD: Input with pull-down resistor.

GPIO_MODE_OUTPUT_PP: Output in push-pull mode.

GPIO_MODE_OUTPUT_OD: Output in open-drain mode.

GPIO_MODE_OUTPUT_AF_PP: Alternate function in push-pull mode.

GPIO_MODE_OUTPUT_AF_OD: Alternate function in open-drain mode.

GPIO_MODE_AF_INPUT: Alternate function input.

Purpose: Determines how the pin behaves (input, output, alternate function, etc.).

GPIO_Output_Speed: Specifies the output speed for the GPIO pin (only relevant for output modes).

Options:

GPIO_SPEED_10MHZ: Maximum output speed of 10 MHz.

GPIO_SPEED_2MHZ: Maximum output speed of 2 MHz.

GPIO_SPEED_50MHZ: Maximum output speed of 50 MHz.

Purpose: Controls the slew rate of the output signal.

b. GPIO Port (GPIOx)
Specifies the GPIO port to which the pin belongs (e.g., GPIOA, GPIOB, etc.).

Purpose: Identifies the GPIO port (A, B, C, etc.) where the pin is located.

c. Pin Number (PinNumber)
Specifies the specific pin to read, write, or toggle.

Range: GPIO_PIN_0 to GPIO_PIN_15.

Purpose: Identifies the exact pin to operate on.

d. Value (Value)
Specifies the value to write to a GPIO pin (high or low).

Options:

GPIO_PIN_SET: Set the pin high.

GPIO_PIN_RESET: Set the pin low.

Purpose: Controls the state of the GPIO pin.

2. Outputs of the GPIO Driver
The GPIO driver produces the following outputs based on the inputs provided:

a. GPIO Pin Configuration
The GPIO pin is configured according to the parameters provided in GPIO_PinConfig_t.

Purpose: Sets up the GPIO pin for the desired operation (input, output, alternate function, etc.).

b. GPIO Pin State
For read operations (MCAL_GPIO_Read_PIN), the driver returns the current state of the GPIO pin.

Options:

GPIO_PIN_SET: Pin is high.

GPIO_PIN_RESET: Pin is low.

Purpose: Allows the application to read the state of a GPIO pin.

c. GPIO Port State
For read operations (MCAL_GPIO_Read_PORT), the driver returns the current state of the entire GPIO port.

Purpose: Allows the application to read the state of all pins in a GPIO port.

d. GPIO Pin Lock Status
For lock operations (MCAL_GPIO_LOCK_PIN), the driver returns whether the pin configuration was successfully locked.

Options:

GPIO_RETURN_LCK_ENABLE: Pin configuration is locked.

GPIO_RETURN_LCK_ERROR: Pin configuration is not locked.

Purpose: Prevents accidental changes to the GPIO pin configuration.

3. Functionality of the GPIO Driver
The GPIO driver provides the following functionalities:

a. GPIO Initialization (MCAL_GPIO_Init)
Configures a GPIO pin based on the provided GPIO_PinConfig_t structure.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

PinConfig: Configuration structure (GPIO_PinConfig_t).

Outputs:

The GPIO pin is configured as specified.

b. GPIO De-initialization (MCAL_GPIO_DeInit)
Resets all GPIO registers for a given port.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

Outputs:

All GPIO registers for the port are reset to their default values.

c. GPIO Pin Read (MCAL_GPIO_Read_PIN)
Reads the current state of a specific GPIO pin.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

PinNumber: GPIO pin to read (e.g., GPIO_PIN_0).

Outputs:

Returns GPIO_PIN_SET (high) or GPIO_PIN_RESET (low).

d. GPIO Port Read (MCAL_GPIO_Read_PORT)
Reads the current state of an entire GPIO port.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

Outputs:

Returns the state of all pins in the port as a 16-bit value.

e. GPIO Pin Write (MCAL_GPIO_Write_PIN)
Writes a value (high or low) to a specific GPIO pin.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

PinNumber: GPIO pin to write (e.g., GPIO_PIN_0).

Value: Value to write (GPIO_PIN_SET or GPIO_PIN_RESET).

Outputs:

The GPIO pin is set to the specified value.

f. GPIO Port Write (MCAL_GPIO_Write_PORT)
Writes a value to an entire GPIO port.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

Value: 16-bit value to write to the port.

Outputs:

All pins in the port are set according to the provided value.

g. GPIO Pin Toggle (MCAL_GPIO_Toggle_PIN)
Toggles the state of a specific GPIO pin.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

PinNumber: GPIO pin to toggle (e.g., GPIO_PIN_0).

Outputs:

The GPIO pin state is toggled (high to low or low to high).

h. GPIO Pin Lock (MCAL_GPIO_LOCK_PIN)
Locks the configuration of a specific GPIO pin.

Inputs:

GPIOx: GPIO port (e.g., GPIOA, GPIOB).

PinNumber: GPIO pin to lock (e.g., GPIO_PIN_0).

Outputs:

Returns GPIO_RETURN_LCK_ENABLE (success) or GPIO_RETURN_LCK_ERROR (failure).