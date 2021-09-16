
#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s heap_t;

int getSize(heap_t *root);
heap_t *swap(heap_t *a, heap_t *b);
heap_t *getLast(heap_t *root, int size);
void heapify(heap_t *root);
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */