#include "monty.h"
l_token_t t_inf = {NULL, NULL, 0, NULL};

void free_stack(stack_t *head);
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
	char *line = NULL, *line_tok[1000];
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
	while ((bytesRead = getline(&line, &len, fd)) != -1)
	{
		line[strcspn(line, "\n")] = 0;
		tokenize_input_line(line, line_tok, idx_ptr, " \t\n");
		{
			/*Call opcode_link()*/
			t_inf.token_str = line_tok[0];
			t_inf.token_arg = line_tok[1];
			opcode_link(&head, line_tok);
			for (index = 0; line_tok[index] != NULL; index++)
			{
				free(line_tok[index]);
			}
		}
		l_count++;
		t_inf.line_num = l_count;
	}
	free(line);
	fclose(fd);
	free_stack(head);
	return (EXIT_SUCCESS);
}
