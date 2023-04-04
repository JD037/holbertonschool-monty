#ifndef MONTY_H
#define MONTY_H

/* Libraries */
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */

void instruction_checker(
		char **buffer,
		stack_t **stack,
		char *file,
		int line_number
		);

void print_error(
		unsigned int error_code,
		char *file,
		unsigned int line_number,
		char *opcode
		);

void push(stack_t **stack, unsigned int line_number);
void push_error(stack_t **newNode, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void free_stack_t(stack_t *stack);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

#endif
