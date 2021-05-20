#include "sandpiles.h"

/**
 * sandpiles_sum - a function that computes the sum of two sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	tumble(grid1);
}


/**
 * check_stable - checks if a grid is stable
 * @grid: grid to check
 * Return: bool true if stable, false if not
 */
bool check_stable(int grid[3][3])
{
	bool is_stable = true;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				is_stable = false;
				break;
			}
		}
	}

	return (is_stable);
}

/**
 * print_gridC - Print 3x3 grid
 * @grid: 3x3 grid
 */
void print_gridC(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * tumble - tumbles a sandpile grid
 * @grid: grid to tumble
 */
void tumble(int grid[3][3])
{
	int i, j;

	while (!check_stable(grid))
	{
		printf("=\n");
		print_gridC(grid);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid[i][j] > 3)
				{
					grid[i][j] -= 4;
					if (i != 0)
					{
						grid[i - 1][j] += 1;
					}
					if (i != 2)
					{
						grid[i + 1][j] += 1;
					}
					if (j != 0)
					{
						grid[i][j - 1] += 1;
					}
					if (j != 2)
					{
						grid[i][j + 1] += 1;
					}
				}
			}
		}
	}
}
