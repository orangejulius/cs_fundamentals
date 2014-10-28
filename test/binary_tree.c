#include "binary_tree.h"

int main()
{
	//some nice test data, randomized so it works ok with a non-self-balancing tree
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };

	tree_node *root = init_tree_node(data[0]);

	//insert the data
	for (int i = 1; i < 10; i++) {
		tree_node *new = init_tree_node(data[i]);
		insert_tree_node(root, new);
	}

	if(!test_tree_correctness(root)) {
		return 1;
	}
}
