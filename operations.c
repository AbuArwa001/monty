#include "monty.h"

/**
 * push - inserts in an doubly linked list
 * @stack: datastructure to be modified
 *
*/
void push(stack_t **temp, unsigned int line_number)
{
  stack_t *pointer = malloc(sizeof(stack_t));
	/*memset()*/
	if (data == -9999)
	{
	  fprintf(stderr,"L<%d>: usage: push integer\n", line_number);
	  exit(EXIT_FAILURE);
	}
	if (pointer == NULL)
	{
        fprintf(stderr, "Error: malloc failed\n");
	}
	else
	{
		if (*temp == NULL)
		{
			pointer -> n = data;
			pointer -> next = NULL;
			*temp = pointer;
		}
		else
		{
			pointer -> n = data;
			pointer -> next = *temp;
			*temp = pointer;
		}
	}
	data = -9999;
}
void pall(stack_t **temp, unsigned int line_number)
{
stack_t *pointer;
pointer = *temp;
 if (data-= -9999)
  {
    fprintf(stderr,"L<%d>: usage: push integer\n", line_number);
    exit(EXIT_FAILURE);
  }
if(pointer == NULL)
{
printf("Stack underflow\n");
}
else
{
printf("The elements of the stack are:\n");
while(pointer!= NULL)
{
printf("%d\n",pointer -> n);
pointer = pointer -> next;
}
}
}
