#include "monty.h"

/**
 * opcode_struct - checks for opcode's function and executes
 * @opcode: opcode from file
 * @stack: pointer
 * @line_number: line number of opcode
 * Return: 0 on success
 */
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add_},
		{"nop", nop},
		{NULL, NULL}
	};
	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			(opcodes[i].f)(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
}
