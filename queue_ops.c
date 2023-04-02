#include "monty.h"

/**
 * push_queue - Add an element to the beginning of the stack
 * @stack: A pointer to the head of the stack_t list
 * @line_number: The current file line number
 */
void push_queue(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	int n;

	if (!arg || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	n = atoi(arg);

	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_queue - Prints all the elements of a stack.
 * @stack: A pointer to the head of the stack_t list.
 * @line_number: The current file line number.
 */
void pall_queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *node = *stack;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
