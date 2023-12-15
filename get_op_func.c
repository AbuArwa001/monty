#include "monty.h"
/**
 * get_op_func - selects the correct function to perform
 *               the operation aske by the user
 * @s: operator passed by the user
 */
int (*get_op_func(char *s))(stack_t **stack, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (ops[i].opcode != NULL)
	{

		if (strcmp(ops[i].opcode, s) == 0)
		{
			return (ops[i].f);
		}

		i++;
	}

	return (NULL);
}