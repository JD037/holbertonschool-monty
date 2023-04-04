Monty Bytecode Interpreter by Josh Davis

Monty is a simple interpreter for the Monty byte code language, which reads from a file containing Monty byte code, and interprets it in order to perform various operations. This program is written in C language and is executed from the command line.

How to use
Monty requires a file with Monty byte code commands to run. This file should be passed as the only argument to the program on the command line.

sh
Copy code
./monty file.m
Monty byte code commands
Monty byte code commands are a series of single byte commands, which can be executed by the Monty interpreter. The following is a list of supported Monty byte code commands:

Command	Description
push n	Pushes an element to the stack. n is an integer.
pall	Prints all the values on the stack, starting from the top of the stack.
pint	Prints the value at the top of the stack, followed by a new line.
pop	Removes the top element of the stack.
swap	Swaps the top two elements of the stack.
add	Adds the top two elements of the stack. The result is then stored in the second element from the top, and the top element is removed.
nop	Doesn't do anything.
#	Indicates the start of a comment. Comments are ignored by the interpreter.
Examples
The following is an example of a file containing Monty byte code commands:

sh
Copy code
$ cat test.m
push 1
push 2
push 3
pall
pop
pall
Executing this file with Monty would produce the following output:

sh
Copy code
$ ./monty test.m
3
2
1
2
1
Exit status
Monty returns with a status of 0 on success, and a non-zero status on failure. Possible failures include:

Status	Description
1	Incorrect number of arguments.
2	Unable to open file.
3	Invalid instruction.
4	Unable to allocate memory.
Authors
Monty was written by Adrian Londoño.
