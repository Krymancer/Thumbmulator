# Thumbmulator

Thumbmulator is a ARM thumb mode code emulator

Compile:

    make

Go to the `bin/` in the project folder and run it.

Usage:

    ./thumbmulator code

To make your code go in `bin/thumb/arm-assembly` edit the startup.s with you code, after simple run `lstsanitaze` to generate the file `code.lst` that alow to `Thumbmulator` run the code.

## Dependencies

`arm-none-gnueabi` [download](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) to cross-compiler the assembly.
`make`
`g++` or other, supporting c++11
