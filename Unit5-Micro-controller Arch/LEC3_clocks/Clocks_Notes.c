1- to know the max frequency of mp (cotrex m3) we look up to the block diagram in datasheet (70 Mhz) 
clocks

2 - for the stm32f103xx(cortex-M3), we can find the clocks in the system arch/ block diagram
Reset & clock control (RCC) is linked with AHB system bus
  - look in the memory map of modules linked with the AHB system bus to know the base address of the RCC
  0x40021000 (base address) - 0x400213FF (end) 
 Three different clock sources can be used to drive the system clock (SYSCLK):
 • HSI oscillator clock
 • HSE oscillator clock
 • PLL clock

3- after getting the .elf file of led toggle of stm32f103c6 mcu from stm32cudeIDE and running it the simulation
 in keil5 we got an error regarding the DWARF-5 debug information: 
    * we changed the DWARF-5 TO DWARF-3 
    -MCU GCC Compiler: Add -gdwarf-3 under the Miscellaneous options.
    -MCU GCC Assembler: Add -gdwarf-3 under its Miscellaneous options.
    -MCU GCC Linker: Add -gdwarf-3 under its Miscellaneous options.
    then run "arm-none-eabi-readelf -w Led_toggle_clocks_lab_STM32F103C6.elf | grep "DWARF" " cmd.

    *in keil, under the debug section, we modified the next command:
    -The Dialog DLL and Parameter are correctly set in the simulator settings:

      Dialog DLL: DARMSTM.DLL

      Parameter: -pSTM32F103C6

4- peripheral clocks must be enabled before you can use any peripheral, including GPIO ports.
 This is done through the Reset and Clock Control (RCC) module.

 lab2:
  Configure Board to run with the Following rates:
  APB1 Bus frequency 4 MHZ
  APB2 Bus frequency 2 MHZ
  AHB frequency 8 MHZ
  SysClk 8 MHZ 
  Use only internal HSI_RC

 lab3:
  Configure Board to run with the 
Following rates:
  APB1 Bus frequency 16MHZ
  APB2 Bus frequency 8MHZ
  AHB frequency 32 MHZ
  SysClk 32 MHZ 
 Use only internal HSI_R
--------->
Step 1: Enable the Clock Source (HSI)
Step 2: Configure the PLL:
      Choose the input clock source (HSI).

      Set the multiplication factor (e.g., x8 for 32 MHz).

      Enable the PLL by setting the PLLON bit in the RCC_CR register.

Step 3: Switch the System Clock to PLL:
      Set the SW bits in the RCC_CFGR register to select the PLL as the system clock source
Step 4: Configure the Bus Prescalers

-Enable the Clock Source First (HSI), The PLL cannot function without a stable input clock
-The PLL configuration (input source and multiplication factor) must be set before enabling the PLL.
-switch the system clock to the PLL

****If i am setting a single bit or multiple independent i can use |=.

****If i am writing a multi-bit field (e.g., 2 bits, 3 bits, etc.), should clear the field first
 using &= ~ and then set the new value using |=.
 0000 0001 (current)
|
 0000 0010 (new value)
 ---------
 Result:    01 | 10 = 11 (false)
 REGISTER &= ~(0b11 << 0); // Clear bits 1:0 to 00
 REGISTER |= (0b10 << 0); // Set bits 1:0 to 10

 -Mode Selection Registers: Clear first, then set.

 -Multiplication/Division Registers: Can often be set directly (if the default value is 0), but clearing first is a good practice.
 *************
 host=b2fe5da22bfb