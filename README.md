# Thumbmulator

Thumbmulator is a ARM thumb mode code emulator that runs your the hexadecimal format of assembly code and show the results of regisgters, memory and stack.

Compile:
> make

Go to the bin/ in the project folder and run it.

Usage: 
> ./thumbmulator asmcode 

To make your code in the bin/thumb edit the startup.s and put you code ther, after simple run make in bin/thumb path and use the generated startup.lst to emule  with thumbnator

## Dependencies 
    arm-none-gnueabi (you can download in arm page) //maybe using the linux-gnueabi not work
