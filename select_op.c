/**
 * monty_push - function that pusher an element to the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */
#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *temp = *stack;

	if (head->mode)
	{
		push_q(stack, line_number);
		return;
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	if (is_int(head->command_argument[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(head->[1]);
	new_node->next = NULL;
	if (!(*stack))
	{
		new_node->prev = *stack;
		*stack = new_node;
		return;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}



/**
 * select_ops - Function to execute options
 *
 * @stack: address of double linked list
 *
 */

void select_ops(stack_t **stack)
{
	int i = 0;
	instruction_t options[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop",  monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{NULL, NULL}
	};

	while (options[i].opcode)
	{
		if (!strcmp(options[i].opcode, head->command_argument[0]))
		{
			(*options[i].f)(stack, head->line_number);
			break;
		}
		i++;
	}
	if (!options[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				head->line_number, head->command_argument[0]);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}


/**
 * free_all - Function free all linked list
 *
 * @stack: address of double linked list
 *
 */

void free_all(stack_t **stack)
{
	stack_t *temp = NULL;
	comandos *temp2 = NULL;

	for (; *stack; *stack = (*stack)->next, free(temp))
		temp = *stack;
	for (; head; head = head->next, free(temp2))
	{
		temp2 = head;
		free(head->command_argument[1]);
		free(head->command_argument[0]);
	}
}
