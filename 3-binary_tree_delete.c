#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree and frees memory
 *
 * @tree: root node of the tree
 *
 * Return: none
 */

void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *right_child;
	binary_tree_t *left_child;

	if (tree == NULL)
		return;

	right_child = tree->right;
	left_child = tree->left;
	free(tree);
	binary_tree_delete(right_child);
	binary_tree_delete(left_child);
}
