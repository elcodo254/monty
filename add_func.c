#include "monty.h"

/**
 * add_ - adds the top two elements of the stack
 * @stack: stack
 * @line_number: line number
 */
void add_(stack_t **stack, unsigned int line_number)
{

	int first;
	int second;
	int result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = (*stack)->n;
	second = (*stack)->next->n;

	result = (first + second);

	pop(stack, line_number);

	(*stack)->n = result;
}

/**
 * nop - doesn't do anything
 * @stack: stask
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_ - subtracts the top element of the stack from the 2nd top
 * @stack: stack
 * @line_number: line_number
 */
void sub_(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	result = b - a;

	pop(stack, line_number);
	(*stack)->n = result;
}
