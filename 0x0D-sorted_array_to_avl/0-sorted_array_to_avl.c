#include "binary_trees.h"
/**
 * sorted_array_to_avl - transform the
 * @array: the input array (sorted)
 * @size: the size of the input array
 * Return: a new node or null if is the case
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node;
	size_t mNode;


	if (array == NULL || size < 1)
		return (NULL);

	node = malloc(1 * sizeof(avl_t));

	if (node == NULL)
		return (NULL);
	mNode = size / 2;

	node->n = array[mNode];

	node->right = sorted_array_to_avl(array + mNode + 1, size - mNode - 1);

	node->left = sorted_array_to_avl(array, mNode);


	if (node->right != NULL)
		node->right->parent = node;

	if (node->left != NULL)
		node->left->parent = node;

	return (node);
}
