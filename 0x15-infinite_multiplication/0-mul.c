#include "holberton.h"

/**
 * main - does the thing
 * @argc: argument count
 * @argv: argument vector
 * Return: program exit
 */
int main(int argc, char *argv[])
{
	int *ans, *a, *b, i, j, tmp, l1, l2;
	char *s1 = argv[1], *s2 = argv[2];

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

	l1 = array_len(argv[1]);
	l2 = array_len(argv[2]);
	ans = (int *) malloc((l1 + l2) * sizeof(int));
	a = (int *) malloc((l1) * sizeof(int));
	b = (int *) malloc((l2) * sizeof(int));

	memset(ans, 0, sizeof(int));

	for(i = l1-1, j=0; i>=0; i--, j++)
    {
        a[j] = s1[i]-'0';
    }
    for(i = l2-1, j=0; i>=0; i--, j++)
    {
        b[j] = s2[i]-'0';
    }
    for(i = 0; i < l2; i++)
    {
        for(j = 0; j < l1; j++)
        {
            ans[i + j] += b[i]*a[j];
        }
    }
    for(i = 0; i < l1 + l2; i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1 + l2; i >= 0; i--)
    {
        if(ans[i] > 0)
            break;
    }
    for(; i >= 0; i--)
    {
        _putchar(ans[i] + '0');
    }

	printf("\n");

	free(ans);
	free(a);
	free(b);

	return (0);
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
 * array_len - finds string length
 * @s: input string
 */
int array_len(char *s)
{
	if (!*s)
	{
		return(0);
	}
	else
	{
		s++;
		return(array_len(s) + 1);
	}
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
