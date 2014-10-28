#include <assert.h>

#include "binary_tree.h"

void test_binary_tree_insert()
{
	//some nice test data, randomized so it works ok with a non-self-balancing tree
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };

	binary_tree_node *root = binary_tree_node_init(data[0]);

	//insert the data
	for (int i = 1; i < 10; i++) {
		binary_tree_node *new = binary_tree_node_init(data[i]);
		binary_tree_insert(root, new);
	}

	assert(binary_tree_test_correctness(root));
}

void test_binary_tree_rotate_left()
{
	//test data to create the binary tree from Algorithms figure 12.13
	int data[] = { 'a', 'e', 'c', 's' };

	binary_tree_node *root = binary_tree_node_init(data[0]);

	for (int i = 1; i < 4; i++) {
		binary_tree_node *new = binary_tree_node_init(data[i]);
		binary_tree_insert(root, new);
	}

	binary_tree_rotate_left(&root);

	assert(root->data == 'e');
	assert(root->left->data == 'a');
	assert(root->right->data == 's');
	assert(root->left->right->data == 'c');
}

int main()
{
	test_binary_tree_insert();
	test_binary_tree_rotate_left();
}
