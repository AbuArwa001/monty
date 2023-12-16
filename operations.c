#include "monty.h"

/**
 * push - inserts in an doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
*/
void push(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = malloc(sizeof(stack_t));


	if (data == -9999)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (pointer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (*temp == NULL)
		{
			pointer->n = data;
			pointer->next = NULL;
			pointer->prev = NULL;
			*temp = pointer;
		}
		else
		{
			pointer->n = data;
			(*temp)->prev = pointer;
			pointer->next = *temp;

			*temp = pointer;
		}
	}

	data = -9999;
}
/**
 * pall - displays a doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
 *
*/
void pall(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer;

	pointer = *temp;

	if (pointer == NULL)
	{
		return;
	}
	else
	{
	if (pointer->n == -9999)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
		while (pointer != NULL)
		{
			printf("%d\n", pointer->n);
			pointer = pointer->next;
		}
	}
}
