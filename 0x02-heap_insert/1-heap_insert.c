#include "binary_trees.h"
/**
 * heap_insert - main to inser
 * @root: the rootr
 * @value:the value
 * Return: a new pointer
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *current;
	int insert_node, mask;

	insert_node = count(*root) + 1;
	mask = 0;
	current = *root;
	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);

	new->parent = *root;
	new->n = value;
	new->left = NULL, new->right = NULL;
	if (!root || !(*root))
		return (*root = new);
	for (; 1 << (mask + 1) <= insert_node; mask++)
		;
	mask--;
	for (; mask > 0; mask--)
	{
		if (insert_node & (1 << mask))
			current = current->right;
		else
			current = current->left;
	}
	if (insert_node & 1)
		current->right = new;
	else
		current->left = new;
	new->parent = current;
	return (sortMax(new));
}

/**
 * sortMax - sort
 * @new: new node
 * Return: new node
 */
heap_t *sortMax(heap_t *new)
{
	int tmp;

	tmp = new->n;
	while (new->parent != NULL && new->parent->n < tmp)
	{
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}
/**
 * count - count nodes
 * @root: Pointer
 * Return: number of nodes
 */
int count(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count(root->left) + count(root->right));
}
