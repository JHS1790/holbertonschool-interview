#include "slide_line.h"

/**
 * slide_line - slide da lyne mon
 * @line: line to slide
 * @size: size of line
 * @direction: Macro SLIDE_LEFT (0) or SLIDE_RIGHT (1)
 * Return: 0 on failure, 1 on success
 */
int slide_line(int *line, size_t size, int direction)
{
	unsigned int i, success_slides = 0, farthest_slid;

	if (line == NULL || size == 0 || direction > 1)
	{
		return (0);
	}
	if (size == 1)
	{
		return (1);
	}

	if (direction == SLIDE_LEFT)
	{
		farthest_slid = 0;
		for(i = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				success_slides += slide_left(line, i, size, &farthest_slid);
			}
		}
	}
	if (direction == SLIDE_RIGHT)
	{
		farthest_slid = size - 1;
		for(i = size - 1; i > 0; i--)
		{
			if (line[i] != 0)
			{
				success_slides += slide_right(line, i, size, &farthest_slid);
			}
		}
		if (line[i] != 0)
		{
			success_slides += slide_right(line, i, size, &farthest_slid);
		}
	}
	return (1);
}

/**
 * slide_left - slide number on line to the left
 * @line: line to slide
 * @starting_index: index to start slide.
 * Return: 0 on failure, 1 on success
 */
int slide_left(int *line, unsigned int starting_index, size_t size, unsigned int *farthest_slid)
{
	unsigned int i = starting_index;
	size = size;
	while (i > *farthest_slid)
	{
		i--;
		if (line[i] == 0 && !(i <= 0))
		{
			continue;
		}
		else if (line[i] == line[starting_index])
		{
			if(*farthest_slid < i || *farthest_slid == 0)
			{
				line[i] += line[starting_index];
				line[starting_index] = 0;
				*farthest_slid = i;
				return (1);
			}
			break;
		}
		else
		{
			break;
		}
	}
	if (line[i] == 0 && i != starting_index)
	{
		line[i] += line[starting_index];
		line[starting_index] = 0;
	}
	else if (i + 1 != starting_index && line[i + 1] == 0)
	{
		line[i + 1] += line[starting_index];
		line[starting_index] = 0;
	}
	return (0);
}

/**
 * slide_right - slide number on line to the right
 * @line: line to slide
 * @starting_index: index to start slide.
 * @size: size of line
 * Return: 0 on failure, 1 on success
 */
int slide_right(int *line, unsigned int starting_index, size_t size, unsigned int *farthest_slid)
{
	unsigned int i = starting_index;
	while (i < *farthest_slid)
	{
		i++;
		if (line[i] == 0 && !(i >= size))
		{
			continue;
		}
		else if (line[i] == line[starting_index])
		{
			if(*farthest_slid > i || *farthest_slid == size - 1)
			{
				line[i] += line[starting_index];
				line[starting_index] = 0;
				*farthest_slid = i;
				return (1);
			}
			break;
		}
		else
		{
			break;
		}
	}
	if (line[i] == 0 && i != starting_index)
	{
		line[i] += line[starting_index];
		line[starting_index] = 0;
	}
	else if (i - 1 != starting_index && line[i - 1] == 0)
	{
		line[i - 1] += line[starting_index];
		line[starting_index] = 0;
	}
	return (0);
}
