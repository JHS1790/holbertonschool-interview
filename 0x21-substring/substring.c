#include "substring.h"

/**
 * find_substring - a function that finds all the possible substrings
 *                  containing a list of words, within a given string
 * @s: the string to scan
 * @words: the array of words all substrings must be a concatenation
 *         arrangement of
 * @nb_words: the number of elements in the array words
 * @n: holds the address at which to store the number of elements in
 *     the returned array
 * Return: an allocated array, storing each index in s, at which a
 *         substring was found. If no solution is found, NULL can be returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *ret, strLen = 0, wordLen = 0, i;

	if (s == NULL || words == NULL || *words == NULL || nb_words == 0)
		return (NULL);

	*n = 0;

	for (i = 0; s[i] != '\0'; i++)
		strLen++;
	for (i = 0; words[0][i] != '\0'; i++)
		wordLen++;

	ret = malloc(sizeof(int) * strLen);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (match(s + i, words, nb_words, wordLen))
		{
			ret[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

/**
 * match - find if a substring match occurs at a single location
 * @s: see find_substring
 * @words: see find_substring
 * @nb_words: see find_substring
 * @wordLen: the length the elements in words
 * Return: True if full match, false if not
 */
bool match(char const *s, char const **words, int nb_words, int wordLen)
{
	int *checked, checkedLen = 0, i, j, in_array;
	bool match = true, found;

	checked = malloc(sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++)
		checked[i] = -1;

	for (i = 0; i < nb_words; i++)
	{
		found = false;
		for (j = 0; j < nb_words; j++)
		{
			in_array = check_array(checked, checkedLen, j);
			if (in_array && check_word((s + (i * wordLen)), words[j]))
			{
				checked[checkedLen] = j;
				checkedLen++;
				found = true;
				break;
			}
		}
		if (found == false)
		{
			match = false;
			break;
		}
	}
	free(checked);
	return (match);
}

/**
 * check_word - checks word against string
 * @str: a string
 * @word: an array of words
 * Return: true if match, false if not
 */
bool check_word(char const *str, char const *word)
{
	int i = 0;

	for (i = 0; *(word + i) != '\0'; i++)
	{
		if (*(str + i) != *(word + i))
			return (false);
	}
	return (true);
}

/**
 * check_array - returns true if ans is not in arr
 * @arr: an array of integers
 * @len: arr length
 * @ans: the value to check for
 * Return: true if false, false if true (just don't think about it too hard)
 */
bool check_array(int *arr, int len, int ans)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == ans)
			return (false);
	}
	return (true);
}
