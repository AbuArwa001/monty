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

	if (*temp == NULL || (*temp)->next == NULL)
	{
		op_err(line_number, "sub");
	}
	pointer = *temp;
	pointer2 = (*temp)->next;
	pointer2->n = pointer2->n - pointer->n;
	*temp = pointer2;
	free(pointer);
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

	if (*temp == NULL || (*temp)->next == NULL)
	{
		op_err(line_number, "mul");
	}
	pointer = *temp;
	pointer2 = (*temp)->next;
	pointer2->n = pointer2->n * pointer->n;
	*temp = pointer2;
	free(pointer);

}
/**
 * pchar - Print char.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **temp, unsigned int line_number)
{

	stack_t *pointer;

	if (*temp == NULL)
	{
		pchar_err(line_number, "stack empty");
		return;
	}
	pointer = (*temp);
	if (pointer->n < 0 || pointer->n > 127)
	{
		pchar_err(line_number, "value out of range");
	}
	printf("%c\n", pointer->n);
}
