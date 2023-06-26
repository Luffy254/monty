#include "monty.h"

/**
 * sub - subtracts top element from second elemnt in stack
 * @stack: double pointer to the head of stack
 * @line_number: line number in monty byte code
 *
 * Return: nothing
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
