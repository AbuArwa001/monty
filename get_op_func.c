#include "monty.h"
/**
 * *get_op_func - selects the correct function to perform
 *               the operation aske by the user
 * @s: operator passed by the user
 * Return: returns the searched function or null if not foud
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{ "pop", pop},
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul },
		{ "div", div_m },
		{ "pchar", pchar },
		{ "mod", mod_m },
		{ "\n", nop },
		{ " ", nop },
		{ "\t", nop },
		{ "pstr", pstr_t },
		{ "rotl", rotrl },
		{ "rotr", rotr },
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
