#include "monty.h"
/**
 * pall - prints all the values in the stack
 * @stack: pointer
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		return;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - printsthe value at the top of the stack
 * @stack: pointer
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	int val;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->n;
	printf("%d\n", val);
}
