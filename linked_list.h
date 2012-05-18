#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

struct singly_linked_list;

typedef struct singly_linked_list
{
	void *data;
	struct singly_linked_list *next;
} singly_linked_list;

/*
 * Create a new singly_linked_list and initialize it with some data
 */
singly_linked_list *init_singly_linked_list(void *data)
{
	singly_linked_list *list = malloc(sizeof(singly_linked_list));

	list->data = data;
	list->next = 0;

	return list;
}

/*
 * Given a pointer to an item in a linked list (presumably the head), and a new list entry
 * insert the new entry at the end of the list
 * O(N) complexity!
 */
void insert_singly_linked_list(singly_linked_list *head, singly_linked_list *new_item)
{
	singly_linked_list *list = head;

	//traverse the length of the list
	while (list->next != 0) {
		list = list->next;
	}

	//insert the new item into the list
	list->next = new_item;
	new_item->next = 0; //just in case
}

/*
 * Given a pointer to an entry in a linked list and a new list entry,
 * insert the new entry immediately after the existing one
 * O(1) complexity
 */
void insert_after_singly_linked_list(singly_linked_list *entry, singly_linked_list *new)
{
	singly_linked_list *next = entry->next;

	entry->next = new;
	new->next = next;
}

/*
 * Given a pointer to an item in a linked list (presumably the head),
 * Print that entry and all following entries
 */
void print_singly_linked_list(singly_linked_list *head) {
	if (head == 0) {
		return;
	}

	singly_linked_list *list = head;
	int i = 0;

	do {
		printf("%d: address: %p data: %d\n", i, list, *(int *)(list->data));
		i++;
	} while (list = list->next); // loop continues if list is not 0
}

/*
 * Given a pointer to the head entry, reverse the order of items in a linked list
 * Does not use recursion
 */
singly_linked_list *reverse_singly_linked_list(singly_linked_list *head)
{
	singly_linked_list *entry = head;
	singly_linked_list *temp;
	singly_linked_list *previous = 0;

	while (entry != 0) {
		temp = entry->next;
		entry->next = previous;
		previous = entry;
		entry = temp;
	}

	return previous;
}

#endif // LINKED_LIST_H
