#include "monty.h"

/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to the top of the stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

/**
 * is_number - checks if a string represents a number
 * @str: the string to check
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	if (!str || *str == '\0')
		return (0);

	if (*str == '-')
		i = 1;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * add_node - adds a new node at the beginning of a stack_t stack
 * @stack: pointer to the top of the stack
 * @n: the integer value to store in the new node
 *
 * Return: pointer to the new node, or NULL if allocation fails
 */
stack_t *add_node(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;

	return (new_node);
}
