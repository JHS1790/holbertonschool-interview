#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/* Our own functions */
void _binary_tree_delete(binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int value;

	root = NULL;

	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);

	_binary_tree_delete(root);
	return (0);
}
