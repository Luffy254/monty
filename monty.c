#include "monty.h"
#include <stdio.h>

/**
 * push_ins - pushes a value onto the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the push instruction
 * @value_str: string representation of the value to be pushed
 *
 * Return: nothing
 */

void push_ins(stack_t **stack, unsigned int line_number, char *value_str)
{
	int value;

	if (value_str == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(value_str);
	push(stack, value, line_number);
}

/**
 * proces_inst - process a single instruction
 * @instruction: the instruction to process
 * @line_number: the current line number
 * @stack: double pointer to the stack
 *
 * Return: nothing
 */

void proces_inst(char *instruction, unsigned int line_number, stack_t **stack)
{
	if (strcmp(instruction, "push") == 0)
	{
		char *value_str = strtok(NULL, " \t\n");

		push_ins(stack, line_number, value_str);
	}
	else if (strcmp(instruction, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(instruction, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(instruction, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(instruction, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(instruction, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(instruction, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else if (strcmp(instruction, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - Frees a stack
 * @stack: Pointer to the head of the stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}

/**
 * parse_file - parse the Monty file and execute instructions
 * @file: pointer to the Monty file
 */

void parse_file(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	ssize_t chars_read;
	char *opcode;

	while ((chars_read = getline(&line, &line_len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		proces_inst(opcode, line_number, &stack);
	}

	fclose(file);
	free(line);
	free_stack(stack);
}

/**
 * main - entry point of the Monty interpreter
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: exit status
 */

int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	parse_file(file);
	return (0);
}
