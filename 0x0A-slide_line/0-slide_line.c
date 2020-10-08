#include "slide_line.h"
/**
 * slide_line - reproduce 2048
 * @line: Pointer to the linez
 * @size: Size
 * @direction: Direction of the mov
 * Return: 1 or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t pf = 0, pr = 0, i = 1, s = size;
	int f = -1;

	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);
	if (direction == SLIDE_RIGHT)
		pf = size - 1, pr = size - 1, i = -1, s = -1;
	while (pf != s)
	{
		if (*(line + pf) != 0)
		{
			if (f == *(line + pf))
				*(line + pf) += f, f = -1;
			else
			{
				f = *(line + pf);
				if ((direction == SLIDE_LEFT && pf != 0) ||
				   ((direction == SLIDE_RIGHT && pf != (size - 1))))
					if (*(line + pr) != 0)
						pr += i;
			}
			*(line + pr) = *(line + pf);
			if (pr != pf)
				*(line + pf) = 0;
		}
		pf += i;
	}
	return (1);
}
