#include <stdio.h>

#include "binary_tree.h"

int main()
{
	//some nice test data, randomized so it works ok with a non-self-balancing tree
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };

	tree_node *root = init_tree_node(data[0]);

	//insert the rest of the data
	int i;
	for (i = 1; i < 10; i++) {
		tree_node *new = init_tree_node(data[i]);
		insert_tree_node_recursive(root, new);
	}

	print_tree_inorder_recursive(root);
	printf("\n");
}