#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 *  * print_num - Prints a number
 *   *
 *    * @n: Number to be printed
 *     */
void print_num(int n)
{
	    printf("%d\n", n);
}

/**
 *  * main - Entry point
 *   *
 *    * Return: Always 0 (Success)
 *     */
int main(void)
{
	    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
        root->left = binary_tree_node(root, 12);
	    root->right = binary_tree_node(root, 128);
	        root->left->right = binary_tree_node(root->left, 54);
		    root->right->right = binary_tree_node(root->right, 402);
		        root->left->left = binary_tree_node(root->left, 10);
			    root->right->left = binary_tree_node(root->right, 110);
			        root->right->right->left = binary_tree_node(root->right->right, 200);
				    root->right->right->right = binary_tree_node(root->right->right, 512);
					    binary_tree_print(root);
					        binary_tree_levelorder(root, &print_num);
						    binary_tree_delete(root);
						        return (0);
}
