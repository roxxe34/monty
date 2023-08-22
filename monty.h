#ifndef MONTY_H
#define MONTY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define DELIMS " \n\t\a\b"
#define MAX_LINE_LENGTH 100
#define _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t instructions[];



void run_interpreter(FILE *file);
int is_empty(stack_t *stack);
int pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int value);
void opcode_pall(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void opcode_push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void opcode_pint(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void opcode_pop(stack_t **stack, unsigned int line_number);
void opcode_swap(stack_t **stack, unsigned int line_number);
size_t stack_size(stack_t *stack);
void opcode_add(stack_t **stack, unsigned int line_number);
void opcode_nop(stack_t **stack, unsigned int line_number);
void opcode_sub(stack_t **stack, unsigned int line_number);
void opcode_div(stack_t **stack, unsigned int line_number);
void opcode_mul(stack_t **stack, unsigned int line_number);
void opcode_mod(stack_t **stack, unsigned int line_number);












#endif /* MONTY_H */