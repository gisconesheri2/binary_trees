#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds lowest common ancestor for two nodes
 * @first: the firsr node
 * @second: the second node
 * Return: pointer to the common node, NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *fpa[20], *spa[20];
	binary_tree_t *temp_node, *current_node;
	int i, j, pos;

	for (i = 0; i < 20; i++)
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
