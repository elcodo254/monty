#include "monty.h"
/**
 * div_ - divides the second top element of the stack by the top element
 * @stack: stack
 * @line_number: line number
 */
void div_(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	if (a == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = b / a;
	pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * mul_ - multiplies top two elements of a stack
 * @stack: stack
 * @line_number: line number
 */
void mul_(stack_t **stack, unsigned int line_number)
{
	int a, b, result;

	if (stack_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a = (*stack)->n;
	b = (*stack)->next->n;
	result = a * b;
	pop(stack, line_number);
	(*stack)->n = result;
}
