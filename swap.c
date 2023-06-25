#include "monty.h"

/**
 * swap - swap top two elements of stack
 * @stack: double pointer to the head of stack
 * @line_number: line number in monty byte code file
 *
 * Return: nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
