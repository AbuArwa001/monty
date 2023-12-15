#include "test.h"
 struct node *temp;
 
int main()
{

	printf("Welcome to DataFlair tutorials!\n\n");

	int choice;
	printf("LINKED LIST IMPLEMENTATION USING STACKS\n\n");

	do
	{

		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n");
		printf("Enter your choice:");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				push();
				break;

			case 2:
				pop();
				break;

			case 3:
				display();
				break;

			case 4:
				exit(0);
				break;

			default:
				printf("Sorry, invalid choice!\n");
				break;
		}
	} while (choice != 4);

	return 0;
}


void pop()
{
	int item;
	struct node *pointer;

	if (temp == NULL)
	{
		printf("Stack Underflow\n");
	}
	else
	{
		item = temp -> data;
		pointer = temp;
		temp = temp -> next;
		free(pointer);
		printf("The deleted item is %d\n", item);
	}
}
void display()
{
	int i;
	struct node *pointer;
	pointer = temp;

	if (pointer == NULL)
	{
		printf("Stack underflow\n");
	}
	else
	{
		printf("The elements of the stack are:\n");

		while (pointer != NULL)
		{
			printf("%d\n", pointer -> data);
			pointer = pointer -> next;
		}
	}
}