#include "binary_trees.h"
/**
 * sorted_array_to_avl - transform a sorted array to a avl tree
 * @array: the input array (sorted)
 * @size: the size of the input array
 * Return: a head of a tree or null if is the case
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (array == NULL || size == 0)
		return (NULL);

	head = insertAVL(array, 0, size - 1, NULL);
	return (head);
}
/**
 * insertAVL - insert in avl
 * @array: the input array (sorted)
 * @begin: the begin
 * @ending: the size - 1
 * @parent: the parent node
 * Return: a new node or null if is the case
 */
avl_t *insertAVL(int *array, size_t begin, size_t ending, avl_t *parent)
{
	size_t middle;
	avl_t *new;

	if (begin > ending)
		return (NULL);

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	middle = (begin + ending) / 2;

	new->left = NULL, new->right = NULL;
	new->n = array[middle], new->parent = parent;

	if (new == NULL)
		return (NULL);

	if (middle != begin)
		new->left = insertAVL(array, begin, middle - 1, new);

	if (middle != ending)
		new->right = insertAVL(array, middle + 1, ending, new);

	return (new);
}
