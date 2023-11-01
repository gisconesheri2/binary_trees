#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0 (Success)
 *     */
int main(void)
{
	    binary_tree_t *root;
	        int full;

root = binary_tree_node(NULL, 1);
  root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);

      root->left->left = binary_tree_node(root->left, 4);
        root->left->right = binary_tree_node(root->left, 5);
	  root->left->right->left = binary_tree_node(root->left->right, 6);
	    root->left->right->right = binary_tree_node(root->left->right, 7);
   binary_tree_print(root);

      full = binary_tree_is_full(root);
  printf("Is %d full: %d\n", root->n, full);
       full = binary_tree_is_full(root->left);
    printf("Is %d full: %d\n", root->left->n, full);
      full = binary_tree_is_full(root->right);
    printf("Is %d full: %d\n", root->right->n, full);
     return (0);
}
