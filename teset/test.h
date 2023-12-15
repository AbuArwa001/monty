#ifndef TEST
#define TEST
#include <stdio.h>
#include <stdlib.h>

void push();
void pop(); 
void display(); 
struct node
{
	int data;
	struct node *next;
};
extern struct node *temp;

#endif