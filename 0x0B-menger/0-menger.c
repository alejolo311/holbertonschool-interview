#include "menger.h"

/**
 * menger - draws a 2D menger sponge
 * @level: number of levels to draw
 * Return: nothing
 */
void menger(int level)
{
	int c, r, size;

	if (level < 0)
		return;
	size = pow(3, level);
	for (c = 0; c < size; c++)
	{
		for (r = 0; r < size; r++)
			putchar(calculate(c, r));
		putchar(10);
	}
}

/**
 * calculate - calcualte next char
 * @col: column
 * @row: row
 * Return: char
 */
char calculate(int col, int row)
{
	while (col && row)
	{
		if (col % 3 == 1 && row % 3 == 1)
			return (' ');
		col /= 3, row /= 3;
	}
	return ('#');
}
