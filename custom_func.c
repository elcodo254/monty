#include "monty.h"

/**
 * stack_len - return length of stack
 * @stack: pointer
 * Return: length of stack
 */
size_t stack_len(stack_t **stack)
{
	stack_t *current;
	unsigned int n;

	current = *stack;
	n = 0;
	while (current != NULL)
	{
		current = current->next;
		n++;
	}
	return (n);
}

/**
 * free_stack - frees stack
 * @stack: stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current;

	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		free(current);
	}
}

/**
 * free_all - free
 * @stack: stack
 * @line: line from getline
 * @file: file
 */
void free_all(stack_t *stack, char *line, FILE *file)
{
	if (stack != NULL)
		free_stack(&stack);

	free(line);
	fclose(file);
}
