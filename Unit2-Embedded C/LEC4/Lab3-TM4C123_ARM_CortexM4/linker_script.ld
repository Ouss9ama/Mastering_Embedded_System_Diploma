/* Linker script CortexM3
   Oussama */

MEMORY
{
    flash (RX) : ORIGIN = 0X00000000, LENGTH = 512M
    sram (RWX) : ORIGIN = 0X20000000, LENGTH = 512M
}

SECTIONS
{
    .text : 
    {
        *(.vectors*)  /* take all the vectors section from any .o file and place it here */
        *(.text*)     /* any .text file put it here */
        *(.rodata*)   /* any rodata file should be placed here */
        _E_text = . ;
    } > flash              /*>VMA @> LMA, here >flash (VMA) @> flash (LMA)*/

    .data : 
    {
        _S_DATA = . ;
        *(.data)
        . = ALIGN(4) ; /*location counter moves to adress that is multiple of 4*/
        _E_DATA = . ;
    } > sram AT> flash /*will be burned in flash but get its virtual adress in sram*/

    .bss : 
    {
        _S_bss = . ;
        *(.bss*)
        _E_bss = . ; 
    } > sram
}