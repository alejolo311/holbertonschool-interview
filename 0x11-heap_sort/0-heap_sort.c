#include "sort.h"
/**
 * heap_sort - sort using heap sort algorithm
 * @array: array
 * @size: size
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		aux(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0], array[0] = array[i],  array[i] = temp;
		print_array(array, size);
		aux(array, i, 0, size);
	}
}

/**
 * aux - aux funtion to heap sort
 * @array: the array to sort
 * @n: variable size
 * @i: head
 * @size: real size
 */
void aux(int *array, int n, int i, int size)
{
	int l, le, ri, temp;

	le = (2 * i) + 1;
	ri = (2 * i) + 2;
	l = i;
	le < n && array[le] > array[l] ? l = le : 0;
	ri < n && array[ri] > array[l] ? l = ri : 0;
	if (l != i)
	{
		temp = array[i], array[i] = array[l], array[l] = temp;
		print_array(array, size);
		aux(array, n, l, size);
	}
}
