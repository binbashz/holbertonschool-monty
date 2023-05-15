# Monty - Stacks and Queues - FIFO and LIFO

This is a simple interpreter for **Monty Byte code files**.

## Learning objectives:

* What do LIFO and FIFO mean
* What is a stack, and when to use it
* What is a queue, and when to use it
* What are the common implementations of stacks and queues
* What are the most common use cases of stacks and queues
* What is the proper way to use global variables

## Environment

* Language: C
* Operating System: Ubuntu 20.04 LTS
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)
* Compiler: gcc
 > **Note:** The code will be compiled this way: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

## Instalation.
Follow the following instructions to get a copy of the program and run in your local machine.

- Clone the following repository.
 > `https://github.com/binbashz/holbertonschool-monty`

- Compile it with GCC
 > `gcc -Wall -Werror -Wextra -pedantic *.c -g -o monty`

- Run the program
 > `./executable_name`

 - Run with debugger
 > `valgrind --leak-check=full --show-leak-kinds=all ./executable_name`

------------
# Tasks
## 0. push, pall
The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function
## 1. pint
The pint opcode

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE
## 2. pop
The pop opcode

The opcode pop removes the top element of the stack.

Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE
## 3. swapThe swap opcode

The opcode swap swaps the top two elements of the stack.

Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
## 4. add
The add opcode

The opcode add adds the top two elements of the stack.

Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter
## 5. nop
The nop opcode

The opcode nop doesn’t do anything.

Usage: nop

------------

## Authors

* [Nicolás Valles] https://github.com/NicoV00
* [Mauricio Correa] https://github.com/binbashz
