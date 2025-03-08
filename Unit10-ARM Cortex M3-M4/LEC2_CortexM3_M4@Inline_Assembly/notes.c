lab2:
>>>>>>>>>>>in C --> (with VAL global var = 0)
__asm("nop \t\n nop \t\n nop");

	/*VAL as output*/
	//mov VAL, 0xff
	__asm("mov %0, #0xff"//%0 is a placeholder for the first operand (output)
			:"=r" (VAL) ); // =r means "write-only output operand in a general-purpose register."
						   //VAL is the C variable (global) that will receive the result

	__asm("nop \t\n nop \t\n nop");

>>>>>>>>>>>in Assembly -->

8000e14:	f04f 03ff 	mov.w	r3, #255	@ 0xff
//This is the compiled version of mov %0, #0xff
//mov.w is a 32-bit ARM instruction to move the immediate value 0xff (255) into register r3

8000e18:	4a0b      	ldr	r2, [pc, #44]	@ (8000e48 <main+0x94>) /*(Fetch the address of VAL)*/
//Loads the address of VAL into r2
//[pc, #44] means "load from memory at address PC + 44"
//The compiler stores the address of VAL in a nearby memory location (likely in the .data or .bss section), and this instruction fetches it

8000e1a:	6013      	str	r3, [r2, #0] /*(Write the result to VAL's memory location)*/
//Stores the value in r3 (0xff) into the memory address held by r2 (which is VAL's address).

==================================================================================================================================
lab3:
>>>>>>>>>>>in C --> (with VAL global var = 0)
__asm("nop \t\n nop \t\n nop");

/* VAL as input */
__asm("mov R0, %0" //%0 is a placeholder for the first input operand (VAL)
        :        // No output operands
        : "r" (VAL) ); // Input operand: "r" = use a register for VAL,VAL is the global variable (input) being read.

__asm("nop \t\n nop \t\n nop");

>>>>>>>>>>>in Assembly -->
8000e14:   4b0b         ldr     r3, [pc, #44]    @ Load address of VAL into r3
//This loads the address of VAL into r3
//pc (Program Counter) is the current instruction address. [pc, #44] means "look 44 bytes ahead in memory".

8000e16:   681b         ldr     r3, [r3, #0]     @ Load value of VAL (3) into r3
// Dereferences the address in r3 to read the value of VAL (3) into r3

8000e18:   4618         mov     r0, r3           @ Copy r3 (VAL) to r0
// Copies the value from r3 (3) into r0.
// This corresponds to the inline assembly instruction mov R0, %0.

========================================================================================================================================
>>>>>>>>>>>in C --> (with VAL global var = 0)
__asm("add %0, %1, %2"     // %0 = %1 + %2 (VAL3 = VAL1 + VAL2)
    : "=r" (VAL3)          // Output: VAL3 (write-only)
    : "r" (VAL1),
     "r" (VAL2) 			// Inputs: VAL1 and VAL2 (read-only)
);

>>>>>>>>>>>in Assembly -->
8000e14: ldr r3, [pc, #52]  @ Load address of VAL1 into r3
8000e16: ldr r3, [r3, #0]    @ Load value of VAL1 into r3
8000e18: ldr r2, [pc, #52]  @ Load address of VAL2 into r2
8000e1a: ldr r2, [r2, #0]    @ Load value of VAL2 into r2
8000e1c: add r3, r2          @ r3 = VAL1 + VAL2
8000e1e: ldr r2, [pc, #52]  @ Load address of VAL3 into r2
8000e20: str r3, [r2, #0]    @ Store result (r3) into VAL3