#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer
 * @line_number: line number
 */
/*void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	free(*stack);
	*stack = next;
}*/
/**
 * swap - swaps the top two elements of the pack
 * @stack: pointer
 * @line_number: line number
 */
/*void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;
	int temp;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	temp = (*stack)->next->n;

	(*stack)->n = temp;
	(*stack)->next->n = tmp;
}*/
