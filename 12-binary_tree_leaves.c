#include "binary_trees.h"

/**
 * btp2 - traverse a binary tree in preorder format
 *
 * @tree: pointer to root of the tree
 * @size_leaves: pointer to the counter for the no of leaves in the binary tree
 *
 * Return: nothing
 */

void btp2(const binary_tree_t *tree, size_t *size_leaves)
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (binary_tree_is_leaf(tree))
		*size_leaves = *size_leaves + 1;
	rc = tree->right;
	lc = tree->left;
	btp2(lc, size_leaves);
	btp2(rc, size_leaves);
}

/**
 * binary_tree_leaves - returns the size of the binary tree
 * @tree: pointer to the root of the tree
 * Return: size of the tre(number of nodes/elements)
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size_leaves = 0;

	if (tree == NULL)
		return (0);

	btp2(tree, &size_leaves);
	return (size_leaves);
}
