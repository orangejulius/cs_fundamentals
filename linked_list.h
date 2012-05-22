#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

struct singly_linked_list_node;
struct singly_linked_list;

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
		printf("%d: address: %p data: %d\n", i, node, *(int *)(node->data));
		i++;
	} while (node = node->next); // loop continues if list is not 0
}

/*
 * Given a pointer to the head entry, reverse the order of items in a linked list
 * Does not use recursion
 * O(N) complexity
 */
singly_linked_list_node *reverse_singly_linked_list(singly_linked_list_node *head)
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

#endif // LINKED_LIST_H
