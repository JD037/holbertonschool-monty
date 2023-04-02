#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Data structures */

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

/* Function prototypes */

/* main.c */
int main(int argc, char **argv);

/* stack_ops.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* queue_ops.c */
void push_queue(stack_t **stack, unsigned int line_number);
void pall_queue(stack_t **stack, unsigned int line_number);

/* util.c */
void free_stack(stack_t **stack);
int is_number(char *str);

#endif /* MONTY_H */
