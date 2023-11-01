#include "binary_trees.h"

/**
 * btp - traverse a binary tree in preorder format
 *
 * @tree: pointer to root of the tree
 * @size: pointer to the counter for the size of the binary tree
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */

void btp(const binary_tree_t *tree, size_t *size, void (*func)(size_t *))
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (func == NULL)
		return;

	func(size);
	rc = tree->right;
	lc = tree->left;
	btp(lc, size, func);
	btp(rc, size, func);
}

/**
 * size_add - increment count
 * @count: pointer to value to increment
 */

void size_add(size_t *count)
{
	*count = *count + 1;
}

/**
 * binary_tree_size - returns the size of the binary tree
 * @tree: pointer to the root of the tree
 * Return: size of the tre(number of nodes/elements)
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	btp(tree, &size, &size_add);
	return (size);
}
