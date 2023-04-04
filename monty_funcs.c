#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: pointer to head node
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode, *temp = *stack;
	char *n;
	int i;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack_t(*stack);

		errno = 12;
		return;
	}
	newNode->prev = NULL;
	n = strtok(NULL, " \n");
	if (n)
	{
		for (i = 0; n[i] != '\0'; i++)
			if ((n[i] != '-') && (isdigit(n[i]) == 0))
			{
				push_error(&newNode, line_number);
				return;
			}
		newNode->n = atoi(n);
	}
	else
	{
		push_error(&newNode, line_number);
		return;
	}
	if (temp == NULL)
	{
		newNode->next = NULL;
		*stack = newNode;
		return;
	}
	newNode->next = temp;
	temp->prev = newNode;
	*stack = newNode;
}

/**
 * push_error - prints error message, frees node, and sets errno
 * @node: pointer to node
 * @line_number: line number to print in error
 */
void push_error(stack_t **node, unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free(*node);
	errno = 1;
}

/**
 * pall - prints all values on the stack, starting from the top of the stack.
 * @stack: the stack
 * @line_number: the current line number
 *
 * Return: void
 */
void pall(stack_t **stack,
		__attribute__((unused)) unsigned int line_number
	 )
{
	stack_t *tmp;

	tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack
 * @stack: The stack
 * @line_number: The line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number of the opcode in the Monty file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL || temp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	(*stack)->prev = NULL;
	temp->prev = *stack;
}
