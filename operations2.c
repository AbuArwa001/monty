#include "monty.h"

/**
 * pop - Add node to the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer;

	if (*temp == NULL)
	{
		free_dlistint(*temp);
		pop_err(line_number); }
	if (*temp == NULL)
	{
		free_dlistint(*temp);
		pop_err(line_number); }
	pointer = *temp;
	*temp = (*temp)->next;
	free(pointer);
	pointer = NULL;
}
/**
 * add - adds the top two elements of the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void add(stack_t **temp, unsigned int line_number)
{
	stack_t *pointer = NULL;
	stack_t *pointer2 = NULL;

	if (*temp == NULL || (*temp)->next == NULL)
	{
		op_err(line_number, "add");
	}
	pointer = *temp;
	pointer2 = (*temp)->next;
	pointer2->n = pointer2->n + pointer->n;
	*temp = pointer2;
	free(pointer);
}
/**
 * sub - subtracts the top e of stack from the 2nd top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */

void sub(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer = NULL;
	stack_t *pointer2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*temp == NULL || temp == NULL)
	{
		op_err(line_number, "sub");
	}
	pointer = *temp;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
		i++;
		flag = 1;
	}
	pointer2 = *temp;
	while (j < (i - 1))
	{
		pointer2 = pointer2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*temp), op_err(line_number, "sub");
	else
	{
		pointer2->n = pointer2->n - pointer->n;
		pointer2->next = NULL;
		free(pointer);
		pointer = NULL;
		return;
	}
}
/**
 * mul - Mul 2nd val from top of a stack_t by top value.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void mul(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer = NULL;
	stack_t *pointer2 = NULL;
	int i = 0, j = 0, flag = 0;

	if (*temp == NULL || temp == NULL)
	{
		op_err(line_number, "mul");
		return;
	}

	pointer = *temp;
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
		i++;
		flag = 1;
	}
	pointer2 = *temp;
	while (j < (i - 1))
	{
		pointer2 = pointer2->next;
		j++;
	}
	if (i == 0 && flag == 0)
		free_dlistint(*temp), op_err(line_number, "mul");
	else
	{
		pointer2->n = pointer2->n * pointer->n;
		pointer2->next = NULL;
		free(pointer);
		pointer = NULL;
		return;
	}

}
/**
 * pchar - Print char.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer;

	if (*temp == NULL || temp == NULL)
	{
		pchar_err(line_number, "stack empty");
		return;
	}
	pointer = (*temp);
	while (pointer->next != NULL)
	{
		pointer = pointer->next;
	}
	if (pointer->n < 0 || pointer->n > 127)
	{
		pchar_err(line_number, "value out of range");
	}
	printf("%c\n", pointer->n);
}
