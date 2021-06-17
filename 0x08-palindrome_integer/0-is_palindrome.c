#include "palindrome.h"

/**
 *  is_palindrome - starts the recursive loop
 *  @n: number to check
 *  Return: True (expands to 1), or False (expands to 0)
 */
int is_palindrome(unsigned long n)
{
	unsigned long dupen = n;
	unsigned long *dupenp = &dupen;

	return (is_palindrome_recursion(n, dupenp));
}

/**
 *  is_palindrome_recursion - conducts the recursive loop
 *  @n: number to check
 *  @dupen: a pointer to a duplicate of n for checking
 *  Return: True (expands to 1), or False (expands to 0)
 */
int is_palindrome_recursion(unsigned long n, unsigned long *dupen)
{
	if (n < 10)
	{
		return (n == (*dupen) % 10);
	}

	if (!is_palindrome_recursion(n / 10, dupen))
	{
		return (false);
	}

	(*dupen) /= 10;

	return (n % 10 == (*dupen) % 10);
}
