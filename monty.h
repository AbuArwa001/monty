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
/**
 * struct data_s - doubly linked list representation of a stack (or queue)
 * @data: integer
 * @mode: mode to put in the stack
 * @size: size of the array
 * @arr: tokinized line
 *
 * Description: doubly linked list node structure for stack, queues, LIFO, FIFO
 */
typedef struct data_s
{
	int data;
	int size;
	char *mode;
	char **arr;
} data_t;
extern data_t datas;
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
 * push_q - inserts in an doubly linked list
 * @temp: datastructure to be modified
 * @line_number: line number to be tracked
*/
void push_q(stack_t **temp, unsigned int line_number);
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
/**
 * _atoi - converts string to int
 * @str: string to be converted
 * Return: returns an integer
*/
unsigned int *_atoi(char *str);
/**
 * nop - does not do anything
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void nop(stack_t **temp, unsigned int line_number);
/**
 * swap - Print the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void swap(stack_t **temp, unsigned int line_number);
/**
 * pint - Print the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pint(stack_t **temp, unsigned int line_number);
/**
 * pop - Add node to the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 *
 * Return: No return
 */
void pop(stack_t **temp, unsigned int line_number);
/**
 * add - adds the top two elements of the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void add(stack_t **temp, unsigned int line_number);
/**
 * sub - subtracts the top e of stack from the 2nd top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */

void sub(stack_t **temp, unsigned int line_number);
/**
 * mul - Mul 2nd val from top of a stack_t by top value.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void mul(stack_t **temp, unsigned int line_number);
/**
 * pchar - Print char.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void pchar(stack_t **temp, unsigned int line_number);
/**
 * div_m - divs 2dn top node by the top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void div_m(stack_t **temp, unsigned int line_number);
/**
 * mod_m - mod 2dn top node by the top element of the stack.
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void mod_m(stack_t **temp, unsigned int line_number);
/**
 * pstr_t - prints the string starting at the top of the stack
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void pstr_t(stack_t **temp, unsigned int line_number);
/**
 * rotrl - rotate to left
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotrl(stack_t **temp, unsigned int line_number);
/**
 * rotr - rotate to left
 * @temp: head of linkedlist
 * @line_number: line number of the instruction
 */
void rotr(stack_t **temp, unsigned int line_number);
/**
 * op_err - math func error messagess.
 * @line_number: line number of the instruction.
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void op_err(unsigned int line_number, char *op);
/**
 * pchar_err - phar error msg for 0 stack & and non-char val.
 * @line_number: line number of the instruction
 * @msg: error message to print.
 * Return: EXIT_FAILURE.
 */
void pchar_err(unsigned int line_number, char *msg);
/**
 * div_err - error for div by 0.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void div_err(unsigned int line_number);
/**
 * pint_err - pint error message for empty stacks.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void pint_err(unsigned int line_number);
/**
 * pop_err - pop error message for empty stacks.
 * @line_number: line number of the instructions.
 * Return: EXIT_FAILURE.
 */
void pop_err(unsigned int line_number);
/**
 * stderr_usage - usage error.
 * Return: EXIT_FAILURE
 */
void stderr_usage(void);
/**
 * stderr_int - error of int.
 * @line_number: type pointer of line number
 * Return: EXIT_FAILURE
 */
void stderr_int(unsigned int line_number);
/**
 * stderr_malloc - Prints malloc error messages.
 * Return: EXIT_FAILURE
 */

void stderr_malloc(void);
/**
 * stderr_unknown - unknown error messagess.
 * @line_number: line number of the instruction.
 * @token: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */
void stderr_unknown(char *token, unsigned int line_number);
#endif
