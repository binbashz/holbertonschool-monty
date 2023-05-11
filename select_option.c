#include "monty.h"

/**
 * monty_push - function that pusher an element to the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *temp = *stack;

	if (head->mode)
	{
		monty_pushq(stack, line_number); /* checkear monty_pushq o m_pushq*/
		return;
	}
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freell(stack);
		exit(EXIT_FAILURE);
	}

	if (isint(head->command_argument[1]))    /* checkear isint !! */
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
		{"pall", },
		{"pint", },
		{"pop", },
	
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
		freell(stack);
		exit(EXIT_FAILURE);
	}
}

