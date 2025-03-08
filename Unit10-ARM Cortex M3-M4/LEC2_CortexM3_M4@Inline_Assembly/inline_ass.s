RESET    ;CPU entry point, 
		mov		r0, #5 ;load r0 with 5
		bl		main	  ;branch to main function, with saving return address
		
main
		mov		r2, #0x100	;load r2  with memory address 0x100
		str		r0, [r2]		;store the value in r0 to adress 0x100
		STRB		r0, [r2, #0x1]	;store byte to 0x1
		STRB		r0, [r2, #0x2]	;store byte to 0x2
		STRB		r0, [r2, #0x3]	;store byte to 0x3
		ldr		r3, [r2]		;load word from adress r2 0x100 to r3
		
substract
		sub		r0, r0, #1  ; Decrement r0 by 1
		cmp		r0, #1	  ;compare r0 with 1
		bne		substract   ;loop if r0 != 1
		mov		pc, lr	  ;Return to caller (LR)
