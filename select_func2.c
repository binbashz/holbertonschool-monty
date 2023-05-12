/**
 * monty_pall - Function that print all values on the stack
 * starting from the top of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */
#include "monty.h"

void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (temp == NULL)
		return;
	while (temp->next != NULL)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}


/**
 * push_q - push on queue mode
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void push_q(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;

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
	new_node->n = atoi(head->command_argument[1]);
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}


/**
 * is_int - checks if s could be converted to an decimal int
 * @s: sourcer string
 * Return: 0 on success, otherwise 1
 */
int is_int(char *s)
{
	size_t i;

	if (!s)
		return (1);
	for (i = 0; s[i]; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != '-'))
			return (1);
	}
	return (0);
}
