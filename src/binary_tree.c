#include <stdio.h>

#include "binary_tree.h"

int main()
{
	//some nice test data, randomized so it works ok with a non-self-balancing tree
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };

	binary_tree_node *root = binary_tree_node_init(data[0]);

	//insert the rest of the data
	for (int i = 1; i < 10; i++) {
		binary_tree_node *new = binary_tree_node_init(data[i]);
		binary_tree_insert(root, new);
	}

	printf("in order:\n");
	binary_tree_inorder_print_recursive(root);
	printf("\n");
	binary_tree_inorder_print(root);
	printf("\n");

	printf("pre-order:\n");
	binary_tree_preorder_print_recursive(root);
	printf("\n");
	binary_tree_preorder_print(root);
	printf("\n");

	printf("post-order:\n");
	binary_tree_postorder_print_recursive(root);
	printf("\n");
	binary_tree_postorder_print(root);
	printf("\n");
}
