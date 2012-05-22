#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

struct tree_node;

/*
 * Tree node definition
 * To focus on algorithms and not handling comparisons of abitrary data types,
 * each node just contains an integer as data
 */
typedef struct tree_node {
	int data;
	struct tree_node *left;
	struct tree_node *right;
} tree_node;

/*
 * Given some data return a newly allocated and initialized tree_node
 */
tree_node *init_tree_node(int data)
{
	tree_node *new = malloc(sizeof(tree_node));
	new->data = data;
	new->left = 0;
	new->right = 0;

	return new;
}

/*
 * Given a root node and a new node, insert the new node into the correct
 * place in the tree pointed to by root node
 * Uses recursive function calls
 * O(log(N)) average complexity
 */
void insert_tree_node_recursive(tree_node *root, tree_node *new)
{
	if (new->data > root->data) {
		if (root->right) {
			insert_tree_node_recursive(root->right, new);
		} else {
			root->right = new;
		}
	} else {
		if (root->left) {
			insert_tree_node_recursive(root->left, new);
		} else {
			root->left = new;
		}
	}
}

/*
 * Given a root node, print all items in the tree using an inorder traversal.
 * Uses recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void print_tree_inorder_recursive(tree_node *root)
{
	if (!root) {
		return;
	}
	print_tree_inorder_recursive(root->left);
	printf("%d, ", root->data);
	print_tree_inorder_recursive(root->right);
}

/*
 * Given a root node, print all items in the tree using a preorder traversal.
 * Uses recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void print_tree_preorder_recursive(tree_node *root)
{
	if (!root) {
		return;
	}
	printf("%d, ", root->data);
	print_tree_preorder_recursive(root->left);
	print_tree_preorder_recursive(root->right);
}

/*
 * Given a root node, print all items in the tree using a postorder traversal.
 * Uses recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void print_tree_postorder_recursive(tree_node *root)
{
	if (!root) {
		return;
	}
	print_tree_postorder_recursive(root->left);
	print_tree_postorder_recursive(root->right);
	printf("%d, ", root->data);
}

#endif // BINARY_TREE_H
