#include "monty.h"

/**
 * monty_pint - Add a new node in the end of a list
 *
 * @stack: address of the double linked list
 * @line_number: number of line
 *
 */

void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	for (; temp->next; temp = temp->next)
		;
	printf("%d\n", temp->n);

}

/**
 * monty_pop - Function that removes top element of the stack
 *
 * @stack: address of the double linked list
 * @line_number: number of line
 *
 */

void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp2 = NULL;

	if (!temp)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	for (; temp && temp->next; temp = temp->next)
		;
	temp2 = temp;
	temp->prev->next = NULL;
	free(temp2);
}

/**
 * monty_swap - Function that swaps the top of two elements from the stack
 *
 * @stack: address of the double linked list
 * @line_number: number of line
 *
 */

void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t i = 1;

	for (; temp && temp->next; temp = temp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	if (i == 2)
	{
		(*stack)->prev = temp;
		temp->next = (*stack);
		(*stack)->next = NULL;
		*stack = temp;
		(*stack)->prev = NULL;
		return;
	}
	temp->prev = temp->prev->prev;
	temp->prev->next->next = NULL;
	temp->next = temp->prev->next;
	temp->prev->next->prev = temp;
	temp->prev->next = temp;
}

/**
 * monty_add - Function that adds the top two elements of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void monty_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	size_t i = 1;

	for (; temp && temp->next; temp = temp->next, i++)
		;
	if (i < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	temp->prev->n += temp->n;
	monty_pop(stack, line_number);
}

/**
 * monty_nop - Function that dont anything
 *
 * @stack: address of the double linked list
 * @line_number: number of line
 *
 */

void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
