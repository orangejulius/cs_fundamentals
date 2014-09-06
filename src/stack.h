#ifndef STACK_H
#define STACK_H

#include "linked_list.h"

//a stack can just be implemented as a singly linked list
//so the existing datastructure will be reused, and most operations
//will just be calling the linked list functions
typedef singly_linked_list stack;

stack *init_stack()
{
	return init_singly_linked_list();
}

void push_stack(stack *stack, void* data)
{
	singly_linked_list_node *node = init_singly_linked_list_node(data);
	insert_head_singly_linked_list(stack, node);
}

void *peek_stack(stack *stack)
{
	if (stack->head) {
		return stack->head->data;
	} else {
		return 0;
	}
}

void *pop_stack(stack *stack)
{
	singly_linked_list_node *node = delete_head_singly_linked_list(stack);
	if (node) {
		return node->data;
	} else {
		return 0;
	}
}
#endif // STACK_H
