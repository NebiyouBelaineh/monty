#include "monty.h"

/**
 * tokenize_input - takes user input and breaks down the arguments into
 * tokens
 *
 * @line: string entered into the shell prompt
 * @line_tok: an array of strings to contain each token string
 * @index_ptr: pointer to the index used for line_tok
 * @delim: delimiter to break string into tokens
 * Return: 0 for success, 1 for error
 */

int tokenize_input_line(char *line, char *line_tok[], int *index_ptr,
char *delim)
{
	int index;
	char *token;

	token = strtok(line, delim);
	for (index = 0; token != NULL; index++)
	{
		line_tok[index] = malloc((strlen(token) * sizeof(char)) + 1);
		if (line_tok[index] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(line_tok[index], token);
		token = strtok(NULL, delim);
		*index_ptr = index;
	}
	*index_ptr = index;
	line_tok[index] = NULL;

	return (0);
}

/**
 * count_lines - counts the number of newline characters
 * @str: str to be counted for new lines
 * Return: number of new lines
 */
int count_lines(char *str)
{
	int count = 0, index;

	for (index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == '\n')
			count++;
	}
	if (count > 0 && str[-1] != '\n')
		count++;
	return (count);
}
