#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

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

/**
 * struct token_s - token and line_num info struct
 * @token_str: opcode token
 * @token_arg: argument for opcode str
 * @line_num: line number the token originates from
 * @f: FILE descriptor for opened monty file
 * @arr: contains array of tokens read from a line
 * @str: contains a string read from a single line
 *
 * Description: track monty file info along with their line number
 */
typedef struct token_s
{
	char *token_str;
	char *token_arg;
	int line_num;
	FILE *f;
	char *arr[1000];
	char *str;
	char *mode;
} l_token_t;

extern l_token_t t_inf;

int tokenize_input_line(char *line, char *arr_token[], int *index_ptr,
char *delim);
int count_lines(char *str);
char *_strdup(char *str);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **head, unsigned int line_num);
void pop(stack_t **head, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **head, unsigned int line_num);
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number);
void sub(stack_t **head, unsigned int line_num);
void divide(stack_t **head, unsigned int line_num);
void mul(stack_t **head, unsigned int line_num);
void mod(stack_t **head, unsigned int line_num);
void pchar(stack_t **head, unsigned int line_num);
void pstr(stack_t **head, unsigned int line_num);
void rotl(__attribute__((unused)) stack_t **head, __attribute__((unused))
unsigned int line_num);
void rotr(__attribute__((unused)) stack_t **head, __attribute__((unused))
unsigned int line_num);
void is_stack(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number);
void is_queue(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number);


int is_integer(const char *str);

char *strdup(const char *s);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void opcode_link(stack_t **head, char *op[]);

stack_t *add_dnodeint(stack_t **head, const int n);
void print_stack(stack_t *h);
void pop_tos(stack_t **head);
void add_node_end(stack_t **head, int n);

void free_stack(stack_t *head);
void free_mem(char *arr[]);
void free_helper(stack_t *head, char *arr[], char *str);

#endif/*MONTY_H*/
