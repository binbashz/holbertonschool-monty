#include "monty.h"
                                        
comandos *head = NULL;


int checking_blank(char *s)
{
	size_t i = 0;

	for (; s[i] && (s[i] == ' '); i++)		
		
	if (s[i] == EOF)
		return (0);
	return (1);
}

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
	
		
	free(s), fclose(f);
	
	
	
	return (EXIT_SUCCESS);
}
