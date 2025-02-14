#@copyright: Oussama
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -g -mthumb -gdwarf-2 -std=c99
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=Led_Toggling_Cortex_m4

ALL: $(Project_name).bin 
	@echo "============Build is done============"

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

#startup.o: startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ)
	$(CC)ld.exe -T linker_script.ld  $(LIBS)  $(OBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
