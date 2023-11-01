#include "binary_trees.h"

/**
 * binary_tree_height - measures balance factor of a tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: balance factor of the tree or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left;
	int height_right;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
	return (height_left - height_right);

}
