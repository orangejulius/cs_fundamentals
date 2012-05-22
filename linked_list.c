#include <stdio.h>

#include "linked_list.h"

int main()
{
	int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//initialize the first entry in the list
	singly_linked_list_node *head = init_singly_linked_list_node(&data[0]);
	printf("initialized singly_linked_list_node at %p with data %d\n", head, *(int *)(head->data));

	//insert the rest of the data into the list
	int i;
	singly_linked_list_node *entry = head; //keep track of the last entry so insert_after can be used
	for (i = 1; i < 10; i++) {
		singly_linked_list_node *new_item = init_singly_linked_list_node(&data[i]);
		insert_after_singly_linked_list_node(entry, new_item);
		entry = new_item;
	}

	print_singly_linked_list_node(head);

	head = reverse_singly_linked_list(head);

	printf("\nReversing the list!\n");

	print_singly_linked_list_node(head);
}
