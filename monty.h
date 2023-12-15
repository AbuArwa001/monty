#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
extern int data;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
void (*get_op_func(char *s))(stack_t **stack, unsigned int);
/**
 * remove_emptyspaces - remove white spaces
 * @str: string to remove white spaces
 *
*/
void remove_emptyspaces(char *str);
/**
 * tokenize - tokenize the string and save them in an arrray
 * @arr: array to be modifieda and save tokens
 * @strn: string to be tokenized
 * @delim: delimeter used to tokenize a string
 * Return: returns size of the string array
*/
int tokenize(char ***arr, char *strn, char *delim);
/**
 * push - inserts in an doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
*/
void push(stack_t **temp, unsigned int line_number);
/**
 * push - inserts in an doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
*/
void pall(stack_t **temp, unsigned int line_number);
/**
 * free_arr - frees an array for tokenization
 * @arr: array to be freed
 * @tokens: number of tokens to be freed
*/
void free_arr(char ***arr, int tokens);
/**
 * free_dlistint - free list
 * @head: head of the list
*/
void free_dlistint(stack_t *head);
/**
 * _strdup - duplicates the string and returns a pointer to new string
 * @str: string to be duplicated
 * Return: returns the duplicates the of the string
 *         returns NULL if ERROR
 */
char *_strdup(char *str);
#endif
