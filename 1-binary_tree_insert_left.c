#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 *
 * @parent: pointer to the node to insert the left child in
 * @value: value to store in the new node
 *
 * Return: pointer to the new node or NULL if on failure or parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *temp_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	if (parent->left == NULL)
	{
		parent->left = new_node;
		new_node->parent = parent;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->n = value;
	}
	else
	{
		temp_node = parent->left;
		parent->left = new_node;
		new_node->parent = parent;
		new_node->left = temp_node;
		new_node->right = NULL;
		new_node->n = value;
	}

	return (new_node);
}
