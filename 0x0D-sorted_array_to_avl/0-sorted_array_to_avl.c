#include "binary_trees.h"

/**
 * sorted_array_to_avl - takes a sorted array and makes it an AVL tree
 * @array: the array data to use
 * @size: size of the array in # of members
 * Return: the new balanced avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int left = 0;
	int right = size - 1;

	root = construct_tree(root, array, left, right);

	return (root);
}

/**
 * construct_tree - constructor for the tree, used recursevly
 * @parent: root node for tree or subtree contruction
 * @array: data array as previously, passed whole
 * @left: leftmost index for tree or subtree construction
 * @right: rightmost index for tree or subtree construction
 * Return: Root node for tree or subtree
 */
avl_t *construct_tree(avl_t *parent, int *array, int left, int right)
{
	avl_t *new = NULL;
	int i = (right - left) / 2 + left;

	if (left > right)
		return (NULL);

	new = create_node(array[i], parent);

	if (!new)
		return (NULL);

	new->left = construct_tree(new, array, left, i - 1);
	new->right = construct_tree(new, array, i + 1, right);

	return (new);
}

/**
 * create_node - creates individual node
 * @n: data n for node n slot
 * @parent: parent node
 * Return: new node pointer
 */
avl_t *create_node(int n, avl_t *parent)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;
	return (new);
}
