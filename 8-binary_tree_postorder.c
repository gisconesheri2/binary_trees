#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a binary tree in postorder format
 *
 * @tree: pointer to root of the tree
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (func == NULL)
		return;

	lc = tree->left;
	rc = tree->right;
	binary_tree_postorder(lc, func);
	binary_tree_postorder(rc, func);
	func(tree->n);
}
