#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer
 * @line_number: line number
 * @n: new item value
 *
 */
void push(stack_t **stack, unsigned int line_number, char *n)
{
	stack_t *new = NULL;
	int i;

	if (!n)
	{
		fprintf(stderr, "L%d: usages: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[0] == '-')
			continue;
		if (isdigit(n[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(n);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
