#include "monty.h"
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

	return (0);
}
