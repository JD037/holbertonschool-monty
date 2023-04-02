#include "monty.h"

/**
 * get_opcode_func - selects the correct function to perform the
 * operation asked by the user
 * @opcode: the operation code to perform
 *
 * Return: a pointer to the function to perform the operation
 */
void (*get_opcode_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		/* add more opcode-function pairs here */
		{NULL, NULL}
	};

	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}

	return (NULL);
}

/**
 * push - pushes an element to the top of a stack_t stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number in the file being executed
 *
 * Return: 0 on success, 1 on failure
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n;
	int num;

	n = strtok(NULL, " \n\t\r");
	if (n == NULL || !is_number(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(n);
	if (add_node(stack, num) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values on a stack_t stack, starting from the top
 * @stack: pointer to the top of the stack
 * @line_number: the line number in the file being executed
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
