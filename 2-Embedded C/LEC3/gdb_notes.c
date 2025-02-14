// we should open 2 terminal, one to run the gdb commands and the other to simulate the hw
// the arm versatilepb has a gdb server called gdbstub that connet trough ethernet using IP|port number
*$ qemu-system-arm -M versatilepb -m 128M -nographic -s -S -kernel Learn-In-Depth.elf
// -s sets up the debugging server
// -S pauses the execution until you connect with a debugger like GDB
// in the other terminal we will run
*$ arm-none-eabi-gdb.exe Learn-In-Depth.elf
(gdb) target remote localhost:1234 //Tells GDB to connect to a remote debugging target
//localhost:IP of our machine since we are using the qemu 
(gdb) display/3i $pc// make the pc show the next 3 assembly instruction
b main // set break point at main
(gdb) b* 0x10010// set break point at adress 0x10010
(gdb) si // step an assembly instruction
(gdb) c // continue the instruction untill meeting a breakpoint
(gdb) s // step a line of c code
(gdb) l //shows you the source code of the current line
(gdb) where // display the current stack






