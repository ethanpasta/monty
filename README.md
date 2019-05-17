# Monty Python

## Description
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
push 0
push 1
push 2
  push 3
                   pall    
push 4
    push 5    
      push    6        
pall
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account.

## Installation
First, clone this repository onto your local machine using:
```
git clone https://github.com/ethanpasta/monty.git
```
After `cd`ing into the directory, compile all files with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
You should now have a `monty` executable file.

## Usage
`./monty file` where `file` is the path to the file containing Monty byte code

The monty program runs the bytecodes line by line and stops if either:
 - It executed properly every line of the file
 - It finds an error in the file
 - An error occured

## Commands
| Command |                                                                                        Description                                                                                       |                                    File                                    |
|:-------:|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:--------------------------------------------------------------------------:|
|   push  |                                                                              Pushes an element to the stack                                                                              |  [opcode_f.c](https://github.com/ethanpasta/monty/blob/master/opcode_f.c)  |
|   pall  |                                                                            Prints all the values on the stack                                                                            |  [opcode_f.c](https://github.com/ethanpasta/monty/blob/master/opcode_f.c)  |
|   pint  |                                                                         Prints the value at the top of the stack                                                                         |  [opcode_f.c](https://github.com/ethanpasta/monty/blob/master/opcode_f.c)  |
|   pop   |                                                                           Removes the top element of the stack                                                                           |  [opcode_f.c](https://github.com/ethanpasta/monty/blob/master/opcode_f.c)  |
|   swap  |                                                                          Swaps the top two elements of the stack                                                                         |  [opcode_f.c](https://github.com/ethanpasta/monty/blob/master/opcode_f.c)  |
|   add   |                                                                          Adds the top two elements of the stack                                                                          | [opcode_f2.c](https://github.com/ethanpasta/monty/blob/master/opcode_f2.c) |
|   nop   |                                                                                    Doesn’t do anything                                                                                   | [opcode_f2.c](https://github.com/ethanpasta/monty/blob/master/opcode_f2.c) |
|   sub   |              Subtracts the top element of the stack from the second top element. The result is stored in the second top element of the stack, and the top element is removed             | [opcode_f2.c](https://github.com/ethanpasta/monty/blob/master/opcode_f2.c) |
|   div   |                Divides the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed               | [opcode_f2.c](https://github.com/ethanpasta/monty/blob/master/opcode_f2.c) |
|   mul   |             Multiplies the second top element of the stack with the top element. The result is stored in the second top element of the stack, and the top element is removed             | [opcode_f2.c](https://github.com/ethanpasta/monty/blob/master/opcode_f2.c) |
|   mod   | Computes the rest of the division of the second top element of the stack by the top element. The result is stored in the second top element of the stack, and the top element is removed | [opcode_f3.c](https://github.com/ethanpasta/monty/blob/master/opcode_f3.c) |
|  pchar  |                     Prints the char at the top of the stack. The integer stored at the top of the stack is treated as the ascii value of the character to be printed                     | [opcode_f4.c](https://github.com/ethanpasta/monty/blob/master/opcode_f4.c) |
|   pstr  | Prints the string starting at the top of the stack, followed by a new line. The integer stored in each element of the stack is treated as the ascii value of the character to be printed | [opcode_f3.c](https://github.com/ethanpasta/monty/blob/master/opcode_f3.c) |
|   rotl  |                                                                               Rotates the stack to the top                                                                               | [opcode_f3.c](https://github.com/ethanpasta/monty/blob/master/opcode_f3.c) |
|   rotr  |                                                                              Rotates the stack to the bottom                                                                             | [opcode_f3.c](https://github.com/ethanpasta/monty/blob/master/opcode_f3.c) |
|  stack  |                                                Sets the format of the data to a stack (LIFO). This is the default behavior of the program                                                | [opcode_f4.c](https://github.com/ethanpasta/monty/blob/master/opcode_f4.c) |
|  queue  |                                                                       Sets the format of the data to a queue (FIFO)                                                                      | [opcode_f4.c](https://github.com/ethanpasta/monty/blob/master/opcode_f4.c) |

## Examples
1. push, sub, pall

#### byte.m
```
push 1
push 2
push 10
push 3
sub
pall
```
#### Output
```
7
2
1
```

2. push, pstr
#### byte.m
```
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 110
push 111
push 116
push 114
push 101
push 98
push 108
push 111
push 72
pstr
```
#### Output
```
Holberton
```

### Comments
If the first non-whitespace character of a line is `#`, this line is skipped.

* **Ethan Mayer** - [ethanpasta](https://github.com/ethanpasta)