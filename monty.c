#include "monty.h"

data_t datas;
/**
 * initializeDatas - initialize data
 */
void initializeDatas(void)
{
	datas.data = 0;
	datas.size = 0;
	datas.mode = "stack";
	datas.arr = NULL;
}
/**
 * process_file - Process Monty code from a file
 * @file: FILE pointer to the Monty code file
 */
void process_file(FILE *file)
{
	char  line[120];
	unsigned int line_number = 0, *dt = 0;
	stack_t *temp = NULL;

	initializeDatas();
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		remove_emptyspaces(line);
		if (strlen(line) == 0 || *line == '#')
			continue;
		datas.size = tokenize(&datas.arr, line, " ");
		dt = _atoi(datas.arr[1]);
		if (dt)
			datas.data = *dt;
		else
			datas.data = -9999;
		free(dt);
		if (strcmp("stack", datas.arr[0]) == 0)
		{
			datas.mode = "stack";
			free_arr(&datas.arr, datas.size);
			continue;
		}
		else if (strcmp("queue", datas.arr[0]) == 0)
		{
			datas.mode = "queue";
			free_arr(&datas.arr, datas.size);
			continue;
		}
		if (get_op_func(datas.arr[0]) != NULL)
			get_op_func(datas.arr[0])(&temp, line_number);
		else
			stderr_unknown(datas.arr[0], line_number);
		free_arr(&datas.arr, datas.size);
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
