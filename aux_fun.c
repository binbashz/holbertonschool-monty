#include "monty.h"

/**
 * command_generator - add node end singly linked list of parsed commands.
 * @head: head of the linked list
 * @s: command to be parsed
 * @i: line number of the script
 * Return: new node, NULL if it fails.
 */
comandos *command_generator(comandos **head, char *s, int i); 
{
	comandos *temp = *head, *new = NULL;
	char *str;

	new = malloc(sizeof(comandos));
	if (!new)
		return (NULL);
	new->comandos[0] = strdup(strtok(s, " \t"));
	if (!(new->comandos[0]))
	{
		free(new);
		return (NULL);
	}
	str = strtok(NULL, " \t");
	if (str)
	{
		new->comandos[1] = strdup(str);
		if (!(new->comandos[1]))
		{
			free(new->comandos[1]);
			free(new);
			return (NULL);
		}
	}
	else
	new->comandos[1] = NULL;
	new->line_number = i;
	new->next = NULL;
	new->mode = 0;
	if (!(*head))
	{
		*head = new;
		return (new);
	}
	for (; temp->next; temp = temp->next)
		continue;
	temp->next = new;
	return (new);
}
