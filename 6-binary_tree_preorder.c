#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a binary tree in preorder format
 *
 * @tree: pointer to root of the tree
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (func == NULL)
		return;

	func(tree->n);
	rc = tree->right;
	lc = tree->left;
	binary_tree_preorder(lc, func);
	binary_tree_preorder(rc, func);
}
