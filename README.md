# Monty Project

## Description

This project is a group project to implement a Monty language interpreter for handling stack and queue operations. It involves working with stacks and queues, implementing various operations, and understanding the Monty ByteCode files.

## Team Members

- Julien Barbier
- Khalfani Khalfan

## Project Timeline

- Start: December 13, 2023, 6:00 AM
- End: December 16, 2023, 6:00 AM
- Checker Release: December 14, 2023, 12:00 AM

## Learning Objectives

By the end of this project, you should be able to:

- Explain LIFO and FIFO concepts
- Understand what a stack is and when to use it
- Understand what a queue is and when to use it
- Identify common implementations of stacks and queues
- Recognize common use cases for stacks and queues
- Properly use global variables

## Resources

Read or watch:

- Google
- How to use extern to share variables between source files in C?
- Stacks and Queues in C
- Stack operations
- Queue operations

## Requirements

### General

- Allowed editors: vi, vim, emacs
- Compile on Ubuntu 20.04 LTS using `gcc` with options `-Wall -Werror -Wextra -pedantic -std=c89`
- All files should end with a new line
- Mandatory README.md file at the root of the project folder
- Code should use the Betty style, checked using `betty-style.pl` and `betty-doc.pl`
- Maximum of one global variable allowed
- No more than 5 functions per file
- C standard library is allowed
- Prototypes of all functions should be included in the header file `monty.h`
- Don't forget to push the header file
- Header files should be include guarded

## Monty ByteCode Files

- Files usually have the .m extension
- One instruction per line
- Any number of spaces before or after the opcode and its argument
- Blank lines are allowed
- Additional text after opcode or argument is ignored

## Monty Program

- Usage: `monty file` where `file` is the path to the file containing Monty ByteCode
- Error handling for various cases:
  - No file or more than one argument given: Print `USAGE: monty file` and exit with `EXIT_FAILURE`
  - Unable to open the file: Print `Error: Can't open file <file>` and exit with `EXIT_FAILURE`
  - Invalid instruction: Print `L<line_number>: unknown instruction <opcode>` and exit with `EXIT_FAILURE`
  - Malloc failure: Print `Error: malloc failed` and exit with `EXIT_FAILURE`

## Compilation & Output

- Compile with: `$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- Output on stdout, errors on stderr

## Tests

- Strongly encouraged to work together on a set of tests

## Data Structures

Use the following data structures:

```c
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
## Tasks

### 0. push, pall

Implement the push and pall opcodes.

#### The push opcode

- Usage: `push <int>` where `<int>` is an integer
- Error handling for non-integer or missing argument
- No need to handle overflows

#### The pall opcode

- Usage: `pall`
- Print all values on the stack, starting from the top

### 1. pint

Implement the pint opcode.

#### The pint opcode

- Usage: `pint`
- Print the value at the top of the stack

### 2. pop

Implement the pop opcode.

#### The pop opcode

- Usage: `pop`
- Remove the top element of the stack

### 3. swap

Implement the swap opcode.

#### The swap opcode

- Usage: `swap`
- Swap the top two elements of the stack

### 4. add

Implement the add opcode.

#### The add opcode

- Usage: `add`
- Add the top two elements of the stack

### 5. nop

Implement the nop opcode.

#### The nop opcode

- Usage: `nop`
- Does nothing
