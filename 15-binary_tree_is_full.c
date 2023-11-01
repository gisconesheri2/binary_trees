#include "binary_trees.h"

/**
 * node_full - checks if a node is full
 * (ie has no children or both children have values)
 *
 * @node: pointer to the node to check
 * @parent_full: tracks if parent of node is full
 * Return: 1 if node is a full, 0 otherwise
 */

int node_full(const binary_tree_t *node, int *parent_full)
{
	if (node == NULL)
		return (0);

	if (node->right != NULL && node->left != NULL)
	{
		*parent_full = 1;
		return (1);
	}
	if (node->right == NULL && node->left == NULL && *parent_full == 1)
		return (1);

	*parent_full = 0;
	return (0);
}

/**
 * btp4 - traverse a binary tree in preorder format
 *
 * @tree: pointer to root of the tree
 * @tree_full: pointer to the boolean tracker for a full node
 * @parent_full: tracks if parent of node is full
 *
 * Return: nothing
 */

void btp4(const binary_tree_t *tree, int *tree_full, int *parent_full)
{
	binary_tree_t *rc;
	binary_tree_t *lc;

	if (tree == NULL)
		return;

	if (node_full(tree, parent_full))
		*tree_full = 1;
	else
		*tree_full = 0;
	rc = tree->right;
	lc = tree->left;
	btp4(lc, tree_full, parent_full);
	btp4(rc, tree_full, parent_full);
}

/**
 * binary_tree_is_full - returns if the binary tree is full
 * @tree: pointer to the root of the tree
 * Return: 1 if tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int tree_full = 0;
	int parent_full = 0;

	if (tree == NULL)
		return (0);

	btp4(tree, &tree_full, &parent_full);
	return (tree_full);
}
