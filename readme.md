# num-convert
`num-convert` is a command-line utility written in C that
quickly and conveniently converts numbers between binary, hexadecimal,
and decimal formats.

## Installation
If you are on x86\_64 bit GNU Linux, simply grab the newest binary from Releases. Alternatively,
you can follow the instructions below to build from the
source yourself. Then, you probably want to place the binary in
a convenient location like your `bin`, or really any directory
that is in your path

### Build instructions
1. Clone repository and `cd` into it
2. Compile `num-convert.c`, for example with `gcc`: `gcc num-convert.c -Wall -std=c11 -o num-convert`
3. Done!

## Usage
`./num-convert [number]`

### Examples
* Inputting decimal number: `./num-convert 1024`
* Inputting binary number: `./num-convert 1001b`
* Inputting hexadecimal number: `./num-convert 0x004f2`
