#include "monty.h"
                                          
comandos *head = NULL;

/**
 * checking_blank - checks for blank spaces
 * @s: source string
 * Return: 0 if successful, 1 otherwise
 */
int checking_blank(char *s)
{
	size_t i = 0;

	for (; s[i] && (s[i] == ' ' || s[i] == '\t'); i++)
		;
	if (s[i] == '\0')
		return (0);
	return (1);
}
/**
 * main - entry point, evaluates path name.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * Return: EXIT_SUCCESS, EXIT_FAILURE.
 */
int main(int argc, char **argv)
{
	FILE *f;
	char *s = NULL;
	size_t n, i;
	int r;
	stack_t *stk = NULL;
	comandos *temp2;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (i = 1; (r = getline(&s, &n, f)) != EOF; i++)
	{
		s[r - 1] = '\0';
		if (!checking_blank(s) || hash_finder(&s) || !(*s))
			continue;
		if (!command_generator(&head, s, i))
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			free_all(&stk);
			exit(EXIT_FAILURE);
		}
	}
	free(s), fclose(f);
	for (; head; free(temp2->command_argument[1]), free(temp2->command_argument[0]), free(temp2))
	{
		temp2 = head;
		select_ops(&stk);
		head = head->next;
	}
	free_all(&stk);
	return (EXIT_SUCCESS);
}
