#include "monty.h"

/**
* add_node_end - adds a new node at the end of a stack_t list
* @head: address of the head of the list
* @n: data to be stored in the new node
*
* Return: address of the new node or NULL if it failed
*/
void add_node_end(stack_t **head, int n)
{
		stack_t *new_node, *current = *head;

		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_helper(*head, t_inf.arr, t_inf.str);
			fclose(t_inf.f);
			exit(EXIT_FAILURE);
		}
		new_node->n = n;

	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;
		return;
	}

	while (current->next != NULL)
		current = current->next;
	new_node->next = NULL;
	current->next = new_node;
	new_node->prev = current;
}
