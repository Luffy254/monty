#include "monty.h"

/**
 * _div - divides second top emenent of stack with top element
 * @stack: double pointer to head of stack
 * @line_number: line number in the monty byte
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int div_result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		div_result = (*stack)->n;
		pop(stack, line_number);
		(*stack)->n /= div_result;
	}
}
