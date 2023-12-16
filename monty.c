#include "monty.h"

int data = 0;

/**
 * process_file - Process Monty code from a file
 * @file: FILE pointer to the Monty code file
 */
void process_file(FILE *file)
{
	char line[120];
	char **tok = NULL;
	unsigned int line_number = 0, tk_size = 0;
	stack_t *temp = NULL;
	int *dt = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		remove_emptyspaces(line);
		if (strlen(line) == 0 || *line == '#')
			continue;
		tk_size = tokenize(&tok, line, " ");
		dt = _atoi(tok[1]);
		if (dt)
			data = *dt;
		else
			data = -9999;
		free(dt);
		if (get_op_func(tok[0]) != NULL)
			get_op_func(tok[0])(&temp, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tok[0]);
			exit(EXIT_FAILURE);
		}

		free_arr(&tok, tk_size);
	}

	free_dlistint(temp);
}

/**
 * main - execute monty code
 * @argc: keep track of number of arguments
 * @argv: the argument vector
 * Return: returns zero on success, 1 on failure
 */
int main(int argc, char const *argv[])
{
	FILE *file;

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r+");

	if (file != NULL)
	{
		process_file(file);
		fclose(file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
