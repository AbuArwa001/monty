#include "monty.h"
int data = 0;

/**
 * main - execute monty code
 * Return: returns zero on success 1 on failure
*/
int main(int argc, char const *argv[])
{
	FILE *file;
	char line [120];
    char **tok = NULL;
    unsigned int line_number = 0;
    stack_t *temp;
	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r+");

	if (file != NULL)
	{
		while (fgets(line, sizeof(line), file) != NULL)
		{
            remove_emptyspaces(line);
            tokenize(&tok, line, " ");
            line_number++;
	    if(!tok[0])
	    {
	      fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, tok[0]);
	      exit(EXIT_FAILURE);
	    }
	    if (!tok[1] && tok[0])
	    {
	      tok[1] = "0";
	    }
            data = atoi(tok[1]);
            if (get_op_func(tok[0]) != NULL)
            {
	      get_op_func(tok[0])(&temp, line_number);
            }
            else
            {
                fprintf(stderr, "L<%d>: unknown instruction <%s>\n", line_number, tok[0]);
                exit(EXIT_FAILURE);
            }
            
            
		}
		fclose(file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return 0;
}
