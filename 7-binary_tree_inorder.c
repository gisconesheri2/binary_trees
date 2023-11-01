#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a binary tree in inorder format
 *
 * @tree: pointer to root of the tree
 * @func: pointer to a function to call for each node
 *
 * Return: nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (func == NULL)
		return;

	lc = tree->left;
	rc = tree->right;
	binary_tree_inorder(lc, func);
	func(tree->n);
	binary_tree_inorder(rc, func);
}
