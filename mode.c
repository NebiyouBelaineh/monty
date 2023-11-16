#include "monty.h"
/**
* is_stack - sets operation mode to stack
* @stack: address to the top of the stack
* @line_number: line number for opcode
*/
void is_stack(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	t_inf.mode = "stack";
}
/**
* is_queue - sets operation mode to queue
* @stack: address to the top of the stack/queue
* @line_number: line number for opcode
*/
void is_queue(__attribute__((unused)) stack_t **stack, __attribute__((unused))
unsigned int line_number)
{
	t_inf.mode = "queue";
}
