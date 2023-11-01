#include "binary_trees.h"

/**
 * btl1 - checks if a node is a leaf (ie has no children)
 *
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, 0 otherwise
 */

int btl1(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * btp3 - traverse a binary tree in preorder format
 *
 * @tree: pointer to root of the tree
 * @size_node: pointer to the counter for the no of leaves in the binary tree
 *
 * Return: nothing
 */

void btp3(const binary_tree_t *tree, size_t *size_node)
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (!btl1(tree))
		*size_node = *size_node + 1;
	rc = tree->right;
	lc = tree->left;
	btp3(lc, size_node);
	btp3(rc, size_node);
}

/**
 * binary_tree_nodes - returns the size of the binary tree
 * @tree: pointer to the root of the tree
 * Return: size of the tre(number of nodes/elements)
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size_nodes = 0;

	if (tree == NULL)
		return (0);

	btp3(tree, &size_nodes);
	return (size_nodes);
}
