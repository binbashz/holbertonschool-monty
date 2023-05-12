#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct commands - function struct
 * @line_number: The line number where the command appears in the script
 * @command_arguments: imput strig
 * @mode: The mode of the command. 
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */


typedef struct commands
{
	int mode;
	unsigned int line_number;
	char *command_argument[2];
	struct commands *next;
} comandos;


/* prototypes */

extern comandos *head;
comandos *command_generator(comandos **head, char *s, int i);

int hash_finder(char **s);
void select_ops(stack_t **stack);

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);
void monty_add(stack_t **stack, unsigned int line_number);
void monty_nop(stack_t **stack, unsigned int line_number);

int is_int(char *s);
void push_q(stack_t **stack, unsigned int line_number);
void free_all(stack_t **stack);

#endif
