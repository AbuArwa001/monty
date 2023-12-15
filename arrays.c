#include "monty.h"

/**
 * free_arr - frees an array for tokenization
 * @arr: array to be freed
 * @tokens: number of tokens to be freed
*/
void free_arr(char ***arr, int tokens)
{
	int i = 0;

	if ((*arr) == NULL)
	{
		return;
	}

	for (i = 0; i < tokens; i++)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
	}

	free(*arr);
	(*arr) = NULL;
}
/**
 * free_dlistint - free list
 * @head: head of the list
*/
void free_dlistint(stack_t *head)
{
	if (head == NULL)
		return;

	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
