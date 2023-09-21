The monty program
Usage: monty file
	where file is the path to the file containing Monty byte code
If the user does not give any file or more than one argument to your program,
	print the error message USAGE: monty file, followed by a new line, and
exit
	with the status EXIT_FAILURE
If, for any reason, its not possible to open the file, print the error message
Error: Can't open file <file>, followed by a new line, and exit with the status
EXIT_FAILURE 
	where <file> is the name of the file
If the file contains an invalid instruction, print the error message
L<line_number>: unknown instruction <opcode>, followed by a new line, and exit
with the status EXIT_FAILURE
	where is the line number where the instruction appears.
Line numbers always start at 1
The monty program runs the bytecodes line by line and stop if either:
	it executed properly every line of the file
	it finds an error in the file
	an error occured
If you cant malloc anymore, print the error message Error: malloc failed,
followed by a new line, and exit with status EXIT_FAILURE.
You have to use malloc and free and are not allowed to use any other function
from man malloc (realloc, calloc, )

push, pall
Implement the push and pall opcodes.

The push opcode

The opcode push pushes an element to the stack.

Usage: push <int>
	where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the
error message L<line_number>: usage: push integer, followed by a new line, and
exit with the status EXIT_FAILURE
	where is the line number in the file

The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the
stack.

Usage pall
If the stack is empty, dont print anything
