#include "monty.h"

/**
 * push - inserts in an doubly linked list
 * @stack: datastructure to be modified
 *
*/
void push(stack_t **temp, unsigned int)
{
	stack_t *pointer = malloc(sizeof(instruction_t));

	if (pointer == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
	}
	else
	{
		if (temp == NULL)
		{
			pointer -> n = data;
			pointer -> next = NULL;
			temp = pointer;
		}
		else
		{
			pointer -> n = data;
			pointer -> next = temp;
			temp = pointer;
		}
	}
}