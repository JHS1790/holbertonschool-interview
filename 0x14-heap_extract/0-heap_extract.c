#include "binary_trees.h"

/**
 * getSize - get the size of the tree
 * @root: root node
 * Return: size of the tree
 **/
int getSize(heap_t *root)
{
	int size = 0;

	if (root == NULL)
		return (0);
	size = 1 + getSize(root->left) + getSize(root->right);
	return (size);
}
/**
 * swap - swaps nodes values
 * @a: node to swap value of
 * @b: node to swap value of
 * Return: the first given node
 **/
heap_t *swap(heap_t *a, heap_t *b)
{
	int swapV = a->n;

	a->n = b->n;
	b->n = swapV;
	return (a);
}
/**
 * getLast - returns the last node of the tree
 * @root: pointer to the root of the tree
 * @size: size of the tree
 * Return: the last node
 **/
heap_t *getLast(heap_t *root, int size)
{
	int byteIndex;
	int mask  = 0;

	for (byteIndex = 0; 1 << (byteIndex + 1) <= size; byteIndex++)
		;
	for (byteIndex--; byteIndex >= 0; byteIndex--)
	{
		mask = 1 << byteIndex;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * heapify - converts the tree into a max heap tree
 * @root: pointer to the root node
 */
void heapify(heap_t *root)
{
	int tmp;
	heap_t *max = root;

	if (root->left != NULL && root->left->n > max->n)
	{
		max = root->left;
	}

	if (root->right != NULL && root->right->n > max->n)
	{
		max = root->right;
	}

	if (max != root)
	{
		tmp = root->n;
		root->n = max->n;
		max->n = tmp;
		heapify(max);
	}
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root:  is a double pointer to the root node of the heap
 * Return: the value stored in the root node, otherwise 0
 */
int heap_extract(heap_t **root)
{
	int removedV;
	heap_t *last_node;

	if ((*root) == NULL)
		return (0);

	removedV = (*root)->n;

	if ((*root)->left != NULL || (*root)->right != NULL)
	{
		last_node = getLast(*root, getSize(*root));
		swap(last_node, *root);
		if (last_node->parent->left == last_node)
			last_node->parent->left = NULL;
		else
			last_node->parent->right = NULL;
		free(last_node);
		heapify(*root);
	}
	else
	{
		free(*root);
		*root = NULL;
	}
	return (removedV);
}
