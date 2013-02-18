#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

struct singly_linked_list_node;
struct singly_linked_list;

/*
 * A single node in a singly linked list.
 * Can be used independently for flexibility or as part of a singly_linked_list struct.
 */
typedef struct singly_linked_list_node
{
	void *data;
	struct singly_linked_list_node *next;
} singly_linked_list_node;

/*
 * Struct representing an entire list.
 * Can be passed to helper functions to make certain actions easier.
 */
typedef struct singly_linked_list
{
	singly_linked_list_node *head;
	singly_linked_list_node *tail;
} singly_linked_list;

/*
 * Create a new singly_linked_list_node and initialize it with some data
 */
singly_linked_list_node *init_singly_linked_list_node(void *data)
{
	singly_linked_list_node *node = malloc(sizeof(singly_linked_list_node));

	node->data = data;
	node->next = 0;

	return node;
}

/*
 * Create and initialize a new, empty singly linked list struct
 */
singly_linked_list *init_singly_linked_list()
{
	singly_linked_list *list = malloc(sizeof(singly_linked_list));

	list->head = 0;
	list->tail = 0;

	return list;

}

/*
 * Given a pointer to an item in a linked list (presumably the head) and a new list entry
 * insert the new entry at the end of the list
 * O(N) complexity!
 */
void insert_singly_linked_list_node(singly_linked_list_node *head, singly_linked_list_node *new_item)
{
	singly_linked_list_node *node = head;

	//traverse the length of the list
	while (node->next != 0) {
		node = node->next;
	}

	//insert the new item into the list
	node->next = new_item;
	new_item->next = 0; //just in case
}

/*
 * Given a pointer to an entry in a linked list and a new list entry,
 * insert the new entry immediately after the existing one
 * O(1) complexity
 */
void insert_after_singly_linked_list_node(singly_linked_list_node *entry, singly_linked_list_node *new)
{
	singly_linked_list_node *next = entry->next;

	entry->next = new;
	new->next = next;
}

/*
 * Add a new linked list node to the beginning of a given linked list
 */
void insert_head_singly_linked_list(singly_linked_list *list, singly_linked_list_node *new)
{
	new->next = list->head;

	list->head = new;

	if (list->tail == 0) {
		list->tail = list->head;
	}
}

/*
 * Add a new linked list node to the end of a given linked list
 */
void insert_tail_singly_linked_list(singly_linked_list *list, singly_linked_list_node *new)
{
	if (list->tail) {
		list->tail->next = new;
	}

	list->tail = new;

	if (list->head == 0) {
		list->head = list->tail;
	}
}

/*
 * Return the current head node and update the list pointers to remove the current head
 * from the list.
 * Does not touch the next pointer of the returned node.
 * Does not handle memory, caller should decide whether or not to call free()
 * O(1) complexity.
 */
singly_linked_list_node *delete_head_singly_linked_list(singly_linked_list *list)
{
	singly_linked_list_node *node = 0;
	if (list->head) {
		node = list->head;
		//if the node about to be removed is also the tail node
		//the list will now be empty, so update the tail node accordingly
		if (list->head == list->tail) {
			list->tail = 0;
		}
		list->head = list->head->next;
	}

	return node;
}

/*
 * Return the current tail node and update the list to remove the current tail.
 * Does not handle memory, caller should decide whether or not to call free()
 * O(N) complexity! If this has to be used a doubly linked list is probably a better choice.
 */
singly_linked_list_node *delete_tail_singly_linked_list(singly_linked_list *list)
{
	//check if list is empty
	if (list->head == 0) {
		return 0;
	}
	singly_linked_list_node *node = list->head;

	//move through the list to the second to last element
	while (node->next != list->tail) {
		node = node->next;
	}

	//once done update the second to last element to point to nothing (it is now the last)
	node->next = 0;

	//store the element to be returned in a temporary variable, update the tail pointer
	singly_linked_list_node *tmp = list->tail;
	list->tail = node;
	return tmp;
}

/*
 * Given a pointer to a linked list node,
 * Print that node and all children node's data
 * Assumes the data can be casted to an integer
 * O(N) complexity
 */
void print_singly_linked_list_node(singly_linked_list_node *head) {
	if (head == 0) {
		return;
	}

	singly_linked_list_node *node = head;
	int i = 0;

	do {
		printf("%d: address: %p data: %d\n", i, (void*)node, *(int *)(node->data));
		i++;
	} while (node = node->next); // loop continues if list is not 0
}

/*
 * Given a pointer to the head entry, reverse the order of items in a linked list
 * Does not use recursion
 * Use reverse_singly_linked_list if using a singly_linked_list struct,
 * otherwise the list->tail pointer will be invalid after calling this function
 * O(N) complexity
 */
singly_linked_list_node *reverse_singly_linked_list_nodes(singly_linked_list_node *head)
{
	singly_linked_list_node *entry = head;
	singly_linked_list_node *temp;
	singly_linked_list_node *previous = 0;

	while (entry != 0) {
		temp = entry->next;
		entry->next = previous;
		previous = entry;
		entry = temp;
	}

	return previous;
}

/*
 * Reverse the order of elements in a list pointed to by a singly_linked_list struct
 * O(N) complexity
 */
void reverse_singly_linked_list(singly_linked_list *list)
{
	list->tail = list->head;
	list->head = reverse_singly_linked_list_nodes(list->head);
}

#endif // LINKED_LIST_H
