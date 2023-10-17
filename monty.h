#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

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
 * struct globals - global structure to use in the functions
 * @s_or_q: stack or queue.
 * @curr: current line.
 * @arg: arg inside the current line.
 * @h: head of doubly linked list.
 * @filed: file descriptor.
 * @buf: buffer.
 */
typedef struct glob 
{
	int s_or_q;
	unsigned int curr;
	char  *arg;
	stack_t *h;
	FILE *filed;
	char *buf;
} glob_t;

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

extern glob_t gvar; 

void (*opcodes_select(char *opcodes))(stack_t **stack, unsigned int line_number);

void add_to_stack(stack_t **h, unsigned int ln);
void print_all(stack_t **head, unsigned int ln);
void print_at_top(stack_t **head, unsigned int ln);
void remove_top(stack_t **head, unsigned int ln);
void swap_to_top(stack_t **head, unsigned int ln);
void set_to_queue(stack_t **head, unsigned int ln);
void set_to_stack(stack_t **head, unsigned int ln);
void add_top_stack(stack_t **head, unsigned int ln);
void nothing(stack_t **head, unsigned int ln);
void subtracts(stack_t **head, unsigned int ln);
void divides(stack_t **head, unsigned int ln);
void multiplies(stack_t **head, unsigned int ln);
void computes(stack_t **head, unsigned int ln);
void print_char(stack_t **head, unsigned int ln);
void print_str(stack_t **head, unsigned int ln);
void rotates_left(stack_t **head, unsigned int ln);
void reverse(stack_t **head, unsigned int ln);

int find_char(char *s, char c);
char *str_token(char *s, char *d);
int _strcmp(char *s1, char *s2);

stack_t *add_node_end(stack_t **h, const int data);
stack_t *add_node(stack_t **h, const int data);
void dlist_free(stack_t *head);

void gvar_free(void);
void gvar_init(FILE *filed);
FILE *_check(int argc, char *argv[]); 

#endif
