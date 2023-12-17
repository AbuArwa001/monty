#include "monty.h"

/**
 * push - inserts in an doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
*/
void push(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = malloc(sizeof(stack_t));

	if (datas.data == -9999)
		stderr_int(line_number);
	if (pointer == NULL)
		stderr_malloc();
	else
	{
		pointer->n = datas.data;
		pointer->prev = NULL;
		if (strcmp(datas.mode, "stack") == 0)
		{
			pointer->next = *temp;
			if (*temp != NULL)
				(*temp)->prev = pointer;

			*temp = pointer;
		}
		else
			if (strcmp(datas.mode, "queue") == 0)
			{
				stack_t *last = *temp;

				if (*temp == NULL)
				{
					pointer->next = NULL;
					*temp = pointer;
				}
				else
				{
					while (last->next != NULL)
						last = last->next;
					last->next = pointer;
					pointer->next = NULL;
					pointer->prev = last;
				}
			}
	}
	datas.data = -9999;
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

	if (pointer == NULL && line_number != 1)
	{
		free_dlistint(pointer);
		exit(EXIT_SUCCESS);
	}

	if (pointer != NULL)
	{
		while (pointer != NULL)
		{
			printf("%d\n", pointer->n);
			pointer = pointer->next;
		}
	}
}
/**
 * pint - Print the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pint(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer = NULL;

	if (*temp == NULL)
	{
		pint_err(line_number);
		return;
	}

	pointer = *temp;
	printf("%d", pointer->n);
	printf("\n");
}

/**
 * swap - Print the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = NULL;

	if (*temp == NULL || (*temp)->next == NULL)
		op_err(line_number, "swap");

	pointer = (*temp)->next;

	(*temp)->next = pointer->next;

	if (pointer->next != NULL)
		(*temp)->next->prev = *temp;

	pointer->next = *temp;
	pointer->prev = NULL;
	(*temp)->prev = pointer;
	*temp = pointer;

}

/**
 * nop - does not do anything
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **temp, unsigned int line_number)
{
	(void)temp;
	(void)line_number;
}
