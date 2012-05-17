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
#endif // LINKED_LIST_H
