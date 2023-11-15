#include "monty.h"

/**
 * free_mem - frees memory for monty interpreter
 * @arr: array of tokens to be free'd
 */
void free_mem(char *arr[])
{
	int index = 0;

	while (arr[index] != NULL)
		free(arr[index++]);
}

/**
 * free_helper - frees memory for the stack, tokens and getline
 * @head: head of the stack_t list
 * @arr: tokens array
 * @str: string from a single line of monty file
 */
void free_helper(stack_t *head, char *arr[], char *str)
{
	free_stack(head);
	free_mem(arr);
	free(str);
}
