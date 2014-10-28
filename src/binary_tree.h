#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

struct binary_tree_node;

/*
 * Tree node definition
 * To focus on algorithms and not handling comparisons of abitrary data types,
 * each node just contains an integer as data
 */
typedef struct binary_tree_node {
	int data;
	struct binary_tree_node *left;
	struct binary_tree_node *right;
} binary_tree_node;

/*
 * Given some data return a newly allocated and initialized tree_node
 */
binary_tree_node *binary_tree_node_init(int data)
{
	binary_tree_node *new = malloc(sizeof(binary_tree_node));
	new->data = data;
	new->left = 0;
	new->right = 0;

	return new;
}

/*
 * Given a root node and a new node, insert the new node into the correct
 * place in the tree pointed to by root node
 * O(log(N)) average complexity
 */
void binary_tree_insert(binary_tree_node *root, binary_tree_node *new)
{
	while(1) {
		if (new->data > root->data) {
			if (root->right) {
				root = root->right;
			} else {
				root->right = new;
				return;
			}
		} else {
			if (root->left) {
				root = root->left;
			} else {
				root->left = new;
				return;
			}
		}
	}
}
/*
 * Given a root node and a new node, insert the new node into the correct
 * place in the tree pointed to by root node
 * Uses recursive function calls
 * O(log(N)) average complexity
 */
void binary_tree_insert_recursive(binary_tree_node *root, binary_tree_node *new)
{
	if (new->data > root->data) {
		if (root->right) {
			binary_tree_insert_recursive(root->right, new);
		} else {
			root->right = new;
		}
	} else {
		if (root->left) {
			binary_tree_insert_recursive(root->left, new);
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
void binary_tree_inorder_print_recursive(binary_tree_node *root)
{
	if (!root) {
		return;
	}
	binary_tree_inorder_print_recursive(root->left);
	printf("%d, ", root->data);
	binary_tree_inorder_print_recursive(root->right);
}

/*
 * Given a root node, print all items in the tree using a preorder traversal.
 * Uses recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void binary_tree_preorder_print_recursive(binary_tree_node *root)
{
	if (!root) {
		return;
	}
	printf("%d, ", root->data);
	binary_tree_preorder_print_recursive(root->left);
	binary_tree_preorder_print_recursive(root->right);
}

/*
 * Given a root node, print all items in the tree using a postorder traversal.
 * Uses recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void binary_tree_postorder_print_recursive(binary_tree_node *root)
{
	if (!root) {
		return;
	}
	binary_tree_postorder_print_recursive(root->left);
	binary_tree_postorder_print_recursive(root->right);
	printf("%d, ", root->data);
}

/*
 * Given a binary tree node, print it and its children using an inorder traversal.
 * Does not use recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void binary_tree_inorder_print(binary_tree_node *node)
{
	stack *stack = init_stack();
	while (node != 0 || peek_stack(stack)) {
		if (node != 0) {
			push_stack(stack, node);
			node = node->left;
		} else {
			node = pop_stack(stack);
			printf("%d, ", node->data);
			node = node->right;
		}
	}
}

/*
 * Given a binary tree node, print it and its children using a preorder traversal.
 * Does not use recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void binary_tree_preorder_print(binary_tree_node *node)
{
	stack *stack = init_stack();
	push_stack(stack, node);
	while (peek_stack(stack)) {
		node = pop_stack(stack);
		printf("%d, ", node->data);
		if (node->right) {
			push_stack(stack, node->right);
		}
		if (node->left) {
			push_stack(stack, node->left);
		}
	}
}

/*
 * Given a binary tree node, print it and its children using a postorder traversal.
 * Does not use recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void binary_tree_postorder_print(binary_tree_node *node)
{
	stack *stack = init_stack();
	push_stack(stack, node);
	binary_tree_node *prev = 0;

	while (node = peek_stack(stack)) {
		if (!prev || prev->left == node || prev->right == node) {
			if (node->left) {
				push_stack(stack, node->left);
			} else if (node->right) {
				push_stack(stack, node->right);
			}
		} else if (node->left == prev) {
			if (node->right) {
				push_stack(stack, node->right);
			}
		} else {
			printf("%d, ", node->data);
			pop_stack(stack);
		}
		prev = node;
	}
}

/*
 * Given a pointer to a binary tree node (which will be modified),
 * perform a right rotation of the binary tree.
 */
void binary_tree_rotate_left(binary_tree_node** root_pointer)
{
	binary_tree_node* root = *root_pointer;

	binary_tree_node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root = temp;

	*root_pointer = root;
}

void binary_tree_rotate_right(binary_tree_node** root_pointer)
{
	binary_tree_node* root = *root_pointer;

	binary_tree_node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root = temp;

	*root_pointer = root;
}

/*
 * Recursively check the basic property of a binary tree:
 * the left child's value is less than the parent value,
 * and the right childs value is greater than or equal to the parent value
 */
bool binary_tree_test_correctness(binary_tree_node *node)
{
	if (node->left) {
		if (node->left->data >= node->data) {
			return false;
		}
		if (!binary_tree_test_correctness(node->left)) {
			return false;
		}
	}

	if (node->right) {
		if (node->right->data < node->data) {
			return false;
		}

		if(!binary_tree_test_correctness(node->right)) {
			return false;
		}
	}
	return true;
}

#endif // BINARY_TREE_H
