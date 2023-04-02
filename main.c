#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
	char *line = NULL, *opcode, *data;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	void (*op_func)(stack_t **, unsigned int) = NULL;
	stack_t *stack = NULL;
	FILE *fp;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue;

		op_func = get_opcode_func(opcode);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n",
					line_number, opcode);
			free(line);
			free_stack(&stack);
			fclose(fp);
			exit(EXIT_FAILURE);
		}

		data = strtok(NULL, " \t\n");
		if (data != NULL && data[0] != '#')
		{
			if (is_number(data) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n",
						line_number);
				free(line);
				free_stack(&stack);
				fclose(fp);
				exit(EXIT_FAILURE);
			}
		}

		op_func(&stack, line_number);
	}

	free(line);
	free_stack(&stack);
	fclose(fp);
	exit(EXIT_SUCCESS);
}
