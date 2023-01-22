#include "monty.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	size_t len = 0;
	ssize_t read;
	char *opcode;
	stack_t *stack;
/*	char *n;*/
	unsigned int line_number = 0;

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
	read = getline(&line, &len, file);
	if (read == -1)
		exit(EXIT_FAILURE);
	while (read != -1 && read != EOF)
	{
		line_number++;
		opcode = strtok(line, DELIMETERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			opcode = strtok(NULL, DELIMETERS);
	/*		printf("%s\n", opcode);*/
			push(&stack, line_number, opcode);
		}
		else
			opcode_struct(opcode, &stack, line_number);
		line_number++;
	}
	free_all(stack, line, file);
	return (EXIT_SUCCESS);
}
