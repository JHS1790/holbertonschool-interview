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
		// printf("Bad Input\n");
		return (0);
	}

	if (direction == SLIDE_LEFT)
	{
		// printf("Slide to the left!\n");
		farthest_slid = 0;
		for(i = 0; i < size; i++)
		{
			// printf("Looking at index %u\n", i);
			if (line[i] != 0)
			{
				// printf("Index is not 0\n");
				success_slides += slide_left(line, i, size, &farthest_slid);
			}
		}
	}
	if (direction == SLIDE_RIGHT)
	{
		// printf("Slide to the Right!\n");
		farthest_slid = size - 1;
		for(i = size - 1; i > 0; i--)
		{
			// printf("Looking at index %u\n", i);
			if (line[i] != 0)
			{
				// printf("Index is not 0\n");
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
				// printf("farthest_slid: %u\n", *farthest_slid);
				line[i] += line[starting_index];
				line[starting_index] = 0;
				*farthest_slid = i;
				// printf("farthest_slid: %u\n", *farthest_slid);
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
	// printf("=====INSIDE SLIDE_RIGHT=====\n");
	// print_array(line, size);
	// printf("Starting Index: %u | Size: %zu | Farthest Combined Index: %u\n", starting_index, size, *farthest_slid);
	while (i < *farthest_slid)
	{
		i++;
		// printf("Looking at index %u\n", i);
		if (line[i] == 0 && !(i >= size))
		{
			// printf("Index is 0 and not out of bounds\n");
			continue;
		}
		else if (line[i] == line[starting_index])
		{
			// printf("Index content is equal to starting index content\n");
			if(*farthest_slid > i || *farthest_slid == size - 1)
			{
				// printf("Farthest slid is at a higher index or at the last index\n");
				line[i] += line[starting_index];
				line[starting_index] = 0;
				*farthest_slid = i;
				// printf("Moving line[%u] to line[%u] | Farthest Slid is now %u\n", starting_index, i, *farthest_slid);
				// print_array(line, size);
				// printf("=====END SLIDE_RIGHT=====\n");
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
	// print_array(line, size);
	// printf("=====END SLIDE_RIGHT=====\n");
	return (0);
}

/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}
