#include "monty.h"
#include <stdio.h>

/**
 * push - pushes an element to the stack
 * @stack: double pointer to head of stack
 * @line_number: line in monty byte code
 * @argument: pointer to value of new node
 *
 * Return: nothing
 */

void push(stack_t **stack, unsigned int line_number, char *argument)
{
	int i = 0;
	int element;
	stack_t *new_node;

	if (argument == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (argument[0] == '-' || argument[0] == '+')
		i = 1;
	for (; argument[i] != '\0'; i++)
	{
		if (argument[i] < '0' || argument[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	element = atoi(argument);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = element;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
