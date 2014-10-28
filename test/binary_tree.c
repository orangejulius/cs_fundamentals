#include "binary_tree.h"

int main()
{
	//some nice test data, randomized so it works ok with a non-self-balancing tree
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };

	binary_tree_node *root = binary_tree_node_init(data[0]);

	//insert the data
	for (int i = 1; i < 10; i++) {
		binary_tree_node *new = binary_tree_node_init(data[i]);
		binary_tree_insert(root, new);
	}

	if(!binary_tree_test_correctness(root)) {
		return 1;
	}
}
