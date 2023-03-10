#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define DELIMETERS "\n\t\r "

/**
 * struct stack_s - doubly linked representation of a stack( or queue)
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack(or queue)
 *
 * Description: doubly linked list node structure
 * for stack, ques, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack
 * ques, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

ssize_t getline(char **string, size_t *n, FILE *stream);
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number, char *n);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
size_t stack_len(stack_t **stack);
void free_stack(stack_t **stack);
void free_all(stack_t *stack, char *line, FILE *file);
void add_(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub_(stack_t **stack, unsigned int line_number);
void div_(stack_t **stack, unsigned int line_number);
void mul_(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
#endif /*MONTY_H*/
