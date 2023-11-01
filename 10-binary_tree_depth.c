#include "binary_trees.h"

/**
 * binary_tree_depth - returns the depth of @tree
 *
 * @tree: pointer to the root of the tree
 *
 * Return: depth of the tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	binary_tree_t *temp_node;

	if (tree == NULL)
		return (0);
	temp_node = tree->parent;
	depth = 0;
	while (temp_node != NULL)
	{
		depth++;
		temp_node = temp_node->parent;
	}
	return (depth);
}
