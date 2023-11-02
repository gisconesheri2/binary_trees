#include "binary_trees.h"
/**
 * hleft - measures height to left of tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: height of tree to left of tree
 */
int hleft(const binary_tree_t *tree)
{
	int hleft2;
	int hright2;

	if (tree == NULL)
		return (-1);
	hleft2 = tree->left ? 1 + hleft(tree->left) : 0;
	hright2 = tree->right ? 1 + hleft(tree->right) : 0;
	return (hleft2 > hright2 ? hleft2 : hright2);
}

/**
 * hright - measures height to right of tree
 *
 * @tree: pointer to the root node of the binary tree
 * Return: height of tree to right of tree
 */
int hright(const binary_tree_t *tree)
{
	int hleft2;
	int hright2;

	if (tree == NULL)
		return (-1);
	hleft2 = tree->left ? 1 + hright(tree->left) : 0;
	hright2 = tree->right ? 1 + hright(tree->right) : 0;
	return (hleft2 > hright2 ? hleft2 : hright2);
}

/**
 * binary_tree_is_perfect - measures if a binary tree is perfect
 *
 * @tree: pointer to the root node of the binary tree
 * Return: 1 if tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left = hleft(tree->left);
	int height_right = hright(tree->right);

	if (tree == NULL)
		return (0);

	if (height_left != height_right)
		return (0);
	return (1);
}
