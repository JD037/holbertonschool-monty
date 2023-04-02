#include "monty.h"

/**
 * push - pushes an element to the top of a stack_t stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number in the file being executed
 *
 * Return: 0 on success, 1 on failure
 */
int push(stack_t **stack, unsigned int line_number)
{
	char *n;
	int num;

	n = strtok(NULL, " \n\t\r");
	if (n == NULL || !is_number(n))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		return (1);
	}

	num = atoi(n);
	if (add_node(stack, num) == NULL)
		return (1);

	return (0);
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
