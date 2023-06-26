#include "monty.h"

/**
 * mul - multiplies second top element with top element of stack
 * @stack: double pointer to head of stack
 * @line_number: line number in monty byte
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int mul_result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		mul_result = (*stack)->n * (*stack)->next->n;
		pop(stack, line_number);
		(*stack)->n = mul_result;
	}
}
