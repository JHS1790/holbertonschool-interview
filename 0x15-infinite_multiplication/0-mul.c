#include "holberton.h"

/**
 * main - does the thing
 * @argc: argument count
 * @argv: argument vector
 * Return: program exit
 */
int main(int argc, char *argv[])
{
	int i, j , length = 1;
	char *result = (char *) malloc(length*sizeof(char));

	if (argc != 3)
	{
		_puts_recursion("Error");
		exit (98);
	}
	if (!(check_if_str_is_int(argv[1])))
	{
		_puts_recursion("Error");
		exit (98);
	}
	if (!(check_if_str_is_int(argv[2])))
	{
		_puts_recursion("Error");
		exit (98);
	}

	for(i = _len(argv[2]) - 1 ; i >= 0 ; i--)
	{
		for(j = _len(argv[1]) - j ; j >= 0 ; j--)
		{
			
		}
	}

	free(result);

	return (atoi(argv[1]) * atoi(argv[2]));
}

/**
 * _len - returns length of string
 * @s: string to lengthenify
 * Retunr: length found
 */
int _len(char *s)
{
	UNUSED(*s);
	return(0);
}

/**
 * _puts_recursion - puts a string
 * @s: input string
 */
void _puts_recursion(char *s)
{
	if (*s == 0)
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	s++;
	_puts_recursion(s);
}

/**
 * check_if_str_is_int - checks if the string is an int or not
 * @s: string to check
 * Return: 0 if no, 1 if yes
 */
int check_if_str_is_int(char *s)
{
	if (*s == 0)
	{
		return (1);
	}
	else if (*s < 48 || *s > 57)
	{
		return (0);
	}
	else
	{
		s++;
		return(check_if_str_is_int(s));
	}
}