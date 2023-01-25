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

	if (n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; n[i] != '\0'; i++)
	{
		if (n[0] == '-' && i == 0)
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

/**
 * pstr - prints string strting at the top with elements in ascii
 * @stack: double pointer to a stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int c;
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		c = current->n;
		if (c > 0 && c <= 127)
		{
			current = current->next;
			putchar(c);
		}
		else
			break;
	}
	putchar('\n');
}
