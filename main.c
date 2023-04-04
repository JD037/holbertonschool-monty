#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *buffer = NULL;
	size_t buffsize = 0;
	stack_t *stack = NULL;
	int line_number = 0;

	if (argc != 2)
		print_error(1, argv[1], 0, NULL);

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		print_error(2, argv[1], 0, NULL);

	while ((getline(&buffer, &buffsize, fp) != EOF) && (errno == 0))
	{
		line_number++;
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			errno = 12;
		}

		instruction_checker(&buffer, &stack, argv[1], line_number);
		buffsize = 0;
	}

	free_stack_t(stack);
	free(buffer);
	fclose(fp);

	if (errno != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * instruction_checker - parses lines in file,
 * and compares to instruction_t array to find function pointer.
 * @buffer: pointer to buffer storing line from .m file
 * @stack: pointer to head of stack_t list
 * @file: name of file being read
 * @line_number: current line
 */

void instruction_checker(
			char **buffer,
			stack_t **stack,
			char *file,
			int line_number
			)

{
	char *opcode = NULL;
	int i;
	instruction_t commands[] = {
		{"push", push},		{"pall", pall},
		{"pop", pop},		{"pint", pint},
		{"add", add},		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}


};

	opcode = strtok(*buffer, " \n");

	if (opcode != NULL)
	{
		for (i = 0; commands[i].opcode; i++)
		{
			if (strcmp(opcode, commands[i].opcode) == 0)
			{
				commands[i].f(&(*stack), line_number);
				break;
			}
		}

		if (commands[i].opcode == NULL)
		{
			print_error(3, file, line_number, opcode);
		}
	}
	free(*buffer);
	*buffer = NULL;
}
