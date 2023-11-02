#include "binary_trees.h"

/**
 * btd - returns the depth of @tree
 *
 * @tree: pointer to the root of the tree
 *
 * Return: depth of the tree
 */

int btd(const binary_tree_t *tree)
{
	int depth;
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
	return (depth + 1);
}
/**
 * binary_trees_ancestor - finds lowest common ancestor for two nodes
 * @first: the firsr node
 * @second: the second node
 * Return: pointer to the common node, NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *fpa[100], *spa[100];
	binary_tree_t *temp_node, *current_node;
	int i, j, pos;

	for (i = 0; i < 100; i++)
	{
		fpa[i] = NULL;
		spa[i] = NULL;
	}

	temp_node = first->parent;
	fpa[0] = temp_node->right == first ? temp_node->right : temp_node->left;
	temp_node = second->parent;
	spa[0] = temp_node->right == second ? temp_node->right : temp_node->left;
	for (temp_node = first->parent, pos = 1; temp_node; pos++)
	{
		fpa[pos] = temp_node;
		temp_node = temp_node->parent;
	}
	for (temp_node = second->parent, pos = 1; temp_node; pos++)
	{
		spa[pos] = temp_node;
		temp_node = temp_node->parent;
	}
	temp_node = fpa[0];
	for (i = 0; temp_node != NULL; i++)
	{
		temp_node = fpa[i];
		current_node = spa[0];
		for (j = 0; current_node; j++)
		{
			current_node = spa[j];
			if (temp_node == current_node)
				return (current_node);
		}
	}
	return (NULL);
}
