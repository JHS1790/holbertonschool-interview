#include "holberton.h"

/**
 * wildcmp -  a function that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: returns 1 if the strings can be considered identical,
 *         otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	int comp1, comp2;

	if (!*s1)
	{
		if (*s2 == '*')
		{
			comp1 = wildcmp(s1, s2 + 1);
			return (comp1);
		}
		if (*s2 == 0)
		{
			comp2 = 1;
		}
		else
		{
			comp2 = 0;
		}
		return (comp2);
	}
	if (*s2 == '*')
	{
		comp1 = wildcmp(s1, s2 + 1);
		comp2 = wildcmp(s1 + 1, s2);
		return (comp1 || comp2);
	}
	if (*s1 == *s2)
	{
		comp1 = wildcmp(s1 + 1, s2 + 1);
		return (comp1);
	}
	return (0);
}
