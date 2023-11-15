#include "monty.h"

/**
 * opcode_link - links the respective opcode and its argument to supported
 * opcode handler functions
 * @stack: address to the top of the stack
 * @op: an array of l_token_t struct containing opcode and line information
 * Return: void
*/
void opcode_link(stack_t **stack, char *op[])
{
	instruction_t op_handlers[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{NULL, NULL}
		};
	unsigned int i;

	for (i = 0; op_handlers[i].opcode != NULL; i++)
	{
		if (strcmp(op_handlers[i].opcode, op[0]) == 0)
		{
			op_handlers[i].f(stack, t_inf.line_num);
			return;
		}
	}
	if (op_handlers[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction <opcode>\n", t_inf.line_num);
		free_mem(t_inf.arr);
		free_stack(*stack);
		free(t_inf.str);
		fclose(t_inf.f);
		exit(EXIT_FAILURE);
	}


}
