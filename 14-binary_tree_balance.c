#include "binary_trees.h"
/**
 * hl - measures height to left of tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: height of tree to left of tree
 */
int hl(const binary_tree_t *tree)
{
	int hl2;
	int hr2;

	if (tree == NULL)
		return (-1);
	hl2 = tree->left ? 1 + hl(tree->left) : 0;
	hr2 = tree->right ? 1 + hl(tree->right) : 0;
	return (hl2 > hr2 ? hl2 : hr2);
}

/**
 * hr - measures height to right of tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: height of tree to right of tree
 */
int hr(const binary_tree_t *tree)
{
	int hl2;
	int hr2;

	if (tree == NULL)
		return (-1);
	hl2 = tree->left ? 1 + hr(tree->left) : 0;
	hr2 = tree->right ? 1 + hr(tree->right) : 0;
	return (hl2 > hr2 ? hl2 : hr2);
}

/**
 * binary_tree_balance - measures balance factor of a tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: balance factor of the tree or 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = hl(tree->left);
	int height_right = hr(tree->right);

	if (tree == NULL)
		return (0);

	return (height_left - height_right);

}
