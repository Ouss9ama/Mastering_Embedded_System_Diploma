#@copyright: Oussama //this is just a comment 
CC=arm-none-eabi- //Sets the cross-compiler prefix to "arm-none-eabi-" for ARM target
CFLAGS=-g -mcpu=arm926ej-s //sets flags for compiling
INCS=-I . //setd to replace the include option
LIBS= //placeholders for libraries
SRC=$(wildcard *.c) //Finds all .c source files in the current directo
OBJ=$(SRC:.c=.o) //Converts all .c source filenames to .o filenames for object files
As=$(wildcard *.s) //Finds all .s assembly files in the current directory
AsOBJ=$(As:.s=.o) //Converts all .s filenames to .o filenames for assembly object files
Project_name=Learn-In-Depth //Set the project name

ALL: $(Project_name).bin //Define the main build target
	@echo "============Build is done============" // Prints a message after building to confirm completion
%.o: %.c // pattern rule for compiling .c files into .o object files
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@ // $< the dependency files  $@ the target file
	 
startup.o: startup.s // compile startup.s to startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: startup.o $(OBJ) //link all teh objects files into a single executable file
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) -o $@

$(Project_name).bin: $(Project_name).elf //converts the elf file to bin
	$(CC)objcopy.exe -O binary $< $@


