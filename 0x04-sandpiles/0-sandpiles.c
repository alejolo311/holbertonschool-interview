#include "stddef.h"
#include "stdio.h"

#include "sandpiles.h"
/**
 * print - print
 * @grid: grid1
 * Return: void
 */
void print(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * sandpiles_sum - entry point
 * @grid1: grid1
 * @grid2: grid2
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add(grid1, grid2);
	while (!check_if_is_unstable(grid1))
	{
		print(grid1);
		stabilize(grid1, grid2);
	}
}
/**
 * add - add the pile
 * @grid1: grid1
 * @grid2: grid2
 * Return: void
 */
void add(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j], grid2[i][j] = 0;
}
/**
 * stabilize - stabilize the pile
 * @grid1: grid1
 * @grid2: grid2
 * Return: void
 */
void stabilize(int grid1[3][3], int grid2[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				(i < 2) ? grid2[i + 1][j] += 1 : 0,
				(j < 2) ? grid2[i][j + 1] += 1 : 0,
				(i > 0) ? grid2[i - 1][j] += 1 : 0,
				(j > 0) ? grid2[i][j - 1] += 1 : 0,
				grid1[i][j] -= 4;
	add(grid1, grid2);
}
/**
 * check_if_is_unstable - check if is necessary stabilize
 * @grid: the input
 * Return: 1 is stable 0 is unstable
 */
int check_if_is_unstable(int grid[3][3])
{
	size_t i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}
