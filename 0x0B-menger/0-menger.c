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
			while (c && r)
				c % 3 == 1 && r % 3 == 1 ? putchar(' ') : 0, c /= 3, r /= 3;
			putchar('#');
		putchar(10);
	}
}
