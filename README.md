# monty

## The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific 
instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

The monty program runs the bytecodes line by line and stop if either:

- it executed properly every line of the file
- it finds an error in the file
- an error occured

## Learning Objectives

### General

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

### More info

#### Compilation command

     $ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

#### Monty opcodes

     #mandatoy
     push <data>    #add element at stak
     pall           #prints all the values on the stack
     pint           #prints the value at the top of the stack
     pop	    #removes the top element of the stack
     swap	    #swaps the top two elements of the stack
     add	    #adds the top two elements of the stack
     nop	    #doesn’t do anything

     #optional
     sub	    #subtracts the top 2 elements of stack (1, 10, 3 = 1, 7)
     div	    #divides the top 2 elements of stack
     mul	    #multiplies the top 2 elements of stack
     mod	    #computes the module of the top 2 elements of stack
     pchar	    #prints the char at the top of the stack
     pstr	    #prints the string starting at the top of the stack, followed by a new line
     rotl	    #The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
     rotr	    #The last element of the stack becomes the top element of the stack
     stack	    #sets the format of the data to a stack (LIFO)
     queue	    #sets the format of the data to a queue (FIFO)

#### Monty file example

     $ cat -e bytecodes/00.m
     push 1$
     push 2$
     push 3$
     pall$

     $ ./monty bytecodes/00.m
     3
     2
     1
     $

#### Errors

      USAGE: monty <file>
      Error: Can't open file <file>
      Error: malloc failed
      L<line_number>: usage: push integer
      L<line_number>: can't pint, stack empty
      L<line_number>: can't pop an empty stack
      L<line_number>: can't swap, stack too short
      L<line_number>: can't add, stack too short
      L<line_number>: can't sub, stack too short
      L<line_number>: can't div, stack too short
      L<line_number>: division by zero
      L<line_number>: unknown instruction <opcode>