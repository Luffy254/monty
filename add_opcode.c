#include "monty.h"

/**
 * add - adds top two elements of stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the monty byte
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	sum = temp->n + temp->next->n;

	temp->next->n = sum;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
