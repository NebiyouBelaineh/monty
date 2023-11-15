#include "monty.h"
l_token_t t_inf = {NULL, NULL, 0, NULL, {NULL}, NULL};

/**
 * main - handles instructions from Monty byte code files
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 for success, 1 for failure
 */
int main(int ac, char *av[])
{
	int index = 0, l_count = 1, index2 = 0, *idx_ptr = &index2;
	ssize_t bytesRead;
	size_t len = 0;
	FILE *fd;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	t_inf.f = fd;
	t_inf.line_num = l_count;
	while ((bytesRead = getline(&t_inf.str, &len, fd)) != -1)
	{
		t_inf.str[strcspn(t_inf.str, "\n")] = 0;
		tokenize_input_line(t_inf.str, t_inf.arr, idx_ptr, "  \t\n");
		t_inf.token_str = t_inf.arr[0];
		t_inf.token_arg = t_inf.arr[1];
		if (t_inf.arr[0] != NULL && *t_inf.arr[0] != '#')/*Call opcode_link()*/
			opcode_link(&head, t_inf.arr);
		for (index = 0; t_inf.arr[index] != NULL; index++)
			free(t_inf.arr[index]);
		l_count++;
		t_inf.line_num = l_count;
	}
	free(t_inf.str);
	fclose(fd);
	free_stack(head);
	return (EXIT_SUCCESS);
}
