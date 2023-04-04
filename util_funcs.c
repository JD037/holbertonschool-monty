#include "monty.h"

/**
 * free_stack_t - frees a stack_t list.
 * @stack: a pointer to the head of the list
 * Return: void
 */
void free_stack_t(stack_t *stack)
{
	stack_t *ptr = stack;

	if (stack == NULL)
	{
		return;
	}

	while (ptr->next)
	{
		stack = stack->next;
		free(ptr);
		ptr = stack;
	}
	free(ptr);
}

/**
 * pop - removes the top element of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * add - adds the top two elements of the stack.
 * and removes the top element from the stack.
 * @stack: The head of the stack
 * @line_number: The line number of the monty file
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack: unused parameter
 * @line_number: unused parameter
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

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
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_number, opcode);
			errno = 3;
			break;
	}
}
