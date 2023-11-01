#include "binary_trees.h"

/**
 * binary_tree_uncle - returns pointer to sibling of @node
 * @node: pointer to the node to check the sibling
 * Return: pointer to the sibling of node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent_node;

	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL);

	if (node->parent->parent == NULL)
		return (NULL);

	parent_node = node->parent->parent;

	if (parent_node->right == NULL || parent_node->left == NULL)
		return (NULL);

	if (parent_node->right == node->parent)
		return (parent_node->left);

	return (parent_node->right);
}
