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
