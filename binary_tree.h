#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

#include "stack.h"

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
 * O(log(N)) average complexity
 */
void insert_tree_node(tree_node *root, tree_node *new)
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

/*
 * Given a binary tree node, print it and its children using an inorder traversal.
 * Does not use recursive function calls
 * All items are printed on a single line with no newline at the end
 */
void print_tree_inorder(tree_node *node)
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
void print_tree_preorder(tree_node *node)
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
void print_tree_postorder(tree_node *node)
{
	stack *stack = init_stack();
	push_stack(stack, node);
	tree_node *prev = 0;

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

#endif // BINARY_TREE_H
