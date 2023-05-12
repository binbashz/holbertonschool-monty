#include "monty.h"

/**
 * command_generator - add node end singly linked list of parsed commands.
 * @head: head of the linked list
 * @s: command to be parsed
 * @i: line number of the script
 * Return: new node, NULL if it fails.
 */
comandos *command_generator(comandos **head, char *s, int i)
{
	comandos *temp = *head, *new = NULL;
	char *str;

	new = malloc(sizeof(comandos));
	if (!new)
		return (NULL);
	new->command_argument[0] = strdup(strtok(s, " \t"));
	if (!(new->command_argument[0]))
	{
		free(new);
		return (NULL);
	}
	str = strtok(NULL, " \t");
	if (str)
	{
		new->command_argument[1] = strdup(str);
		if (!(new->command_argument[1]))
		{
			free(new->command_argument[1]);
			free(new);
			return (NULL);
		}
	}
	else
	new->command_argument[1] = NULL;
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

/**
 * hash_finder - Function that find # in the line.
 * @s: line to read
 *
 * Return: 1 if find # and 0 if not find.
 */
int hash_finder(char **s)
{
	int i = 0;

	for (; (*s)[i] && ((*s)[i] == ' ' || (*s)[i] == '\t'); i++)
		;
	if ((*s)[i] == '#')
		return (1);
	for (i = 0; (*s)[i] && (*s)[i] != '#'; i++)
		;
	(*s)[i] = '\0';
	return (0);
}
