

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


