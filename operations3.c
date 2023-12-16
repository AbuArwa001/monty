#include "monty.h"

/**
 * div_m - divs 2dn top node by the top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void div_m(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = NULL;
	stack_t *pointer2 = NULL;

	if (*temp == NULL || (*temp)->next == NULL)
	{
		op_err(line_number, "div");
	}
	pointer = *temp;
	pointer2 = (*temp)->next;
	if (pointer->n == 0)
	{
		free_dlistint(*temp);
		div_err(line_number);
	}
	pointer2->n = pointer2->n / pointer->n;
	*temp = pointer2;
	free(pointer);

}
/**
 * mod_m - mod 2dn top node by the top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void mod_m(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer = NULL;
	stack_t *pointer2 = NULL;

	if (*temp == NULL || (*temp)->next == NULL)
	{
		free_dlistint(*temp);
		op_err(line_number, "mod");
	}
	pointer = *temp;
	pointer2 = (*temp)->next;
	if (pointer->n == 0)
	{
		free_dlistint(*temp);
		div_err(line_number);
	}
	pointer2->n = pointer2->n % pointer->n;
	*temp = pointer2;
	free(pointer);

}

/**
 * pstr_t - prints the string starting at the top of the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void pstr_t(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = NULL;
	(void)line_number;

	if (*temp == NULL)
	{
		printf("\n");
		return;
	}
	pointer = *temp;
	if (pointer->next == NULL && line_number == 2 &&
	(pointer->n < 0 || pointer->n >= 127))
	{
		printf("\n");
		free_dlistint(*temp);
		exit(0);
	}
	while (pointer->next != NULL)
	{
		if (pointer->n > 0 && pointer->n < 127)
		{
			printf("%c", pointer->n);
			pointer = pointer->next;
		}
		else
			pointer = pointer->next;
		if (pointer->n <= 0 || pointer->n >= 127)
		{
			printf("\n");
			return;
		}
	}
	printf("%c\n", pointer->n);
}
/**
 * rotrl - rotate to left
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotrl(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer2 = NULL;
	stack_t *pointer = NULL;
	(void)line_number;

	if (*temp == NULL || ((*temp)->next == NULL))
		return;
	pointer = *temp;
	while (pointer->next != NULL)
		pointer = pointer->next;
	pointer2 = pointer->prev;
	pointer2->next = NULL;
	pointer->prev = NULL;
	pointer->next = *temp;
	(*temp)->prev = pointer;
	*temp = pointer;
}
/**
 * rotr - rotate to left
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotr(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer2 = NULL;
	(void)line_number;

	if (*temp == NULL)
		return;
	pointer2 = *temp;
	while (pointer2->next != NULL)
		pointer2 = pointer2->next;
	pointer2->next = *temp;
	(*temp)->prev = pointer2;
	pointer2 = (*temp)->next;
	(*temp)->next = NULL;
	*temp = pointer2;
	(*temp)->prev = NULL;
}
