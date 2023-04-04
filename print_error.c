#include "monty.h"

/**
 * print_error - prints error code to stderr and sets errno
 * @error_code: error code
 * @file: filename
 * @line_number: line number error occured on
 * @opcode: opcode at time of failure
 */

void print_error(
		unsigned int error_code,
		char *file,
		unsigned int line_number,
		char *opcode
		)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			errno = 1;
			exit(EXIT_FAILURE);
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", file);
			errno = 2;
			exit(EXIT_FAILURE);
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			errno = 3;
			break;
	}
}
