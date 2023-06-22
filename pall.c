#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: double pointer to the head of stack
 * @line_number: line number in monty byte
 *
 * Return: nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *present = *stack;
	(void)line_number;

	if (present == NULL)
		return;

	while (present)
	{
		printf("%d\n", present->n);
		present = present->next;
	}
}
