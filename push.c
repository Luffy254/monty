#include "monty.h"
#include <stdio.h>

/**
 * push - pushes an element to the stack
 * @stack: double pointer to head of stack
 * @value: value to be pushed onto the stack
 * @line_number: line in monty byte code
 *
 * Return: nothing
 */

void push(stack_t **stack, int value, __attribute__ ((unused))unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
