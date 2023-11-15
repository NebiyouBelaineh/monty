#include "monty.h"

/**
 * is_integer - checks if an string is an integer or not
 * @str: string to be checked
 * Return: 1 if it is an integer, 0 otherwise
 */
int is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0); /*Not integer*/

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0); /*Not Integer*/
		str++;
	}
	return (1); /*Is integer*/
}
