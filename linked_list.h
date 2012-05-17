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
#endif // LINKED_LIST_H
