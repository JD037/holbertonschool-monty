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
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&line, &len, file)) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \n\t\r");
			if (arg == NULL || !is_number(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free_stack(&stack);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(arg));
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			free_stack(&stack);
			free(line);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(&stack);
	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}
