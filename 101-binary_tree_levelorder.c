#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse a binary tree in levelorder format
 *
 * @tree: pointer to root of the tree
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (tree->left == NULL)
		return;

	if (tree->right == NULL)
		return;

	if (func == NULL)
		return;

	if (tree->parent == NULL)
		func(tree->n);

	lc = tree->left;
	func(lc->n);
	rc = tree->right;
	func(rc->n);
	binary_tree_levelorder(lc, func);
	binary_tree_levelorder(rc, func);
}
