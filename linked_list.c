#include <stdio.h>

#include "linked_list.h"

int main()
{
	int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//initialize the linked list struct
	singly_linked_list *list = init_singly_linked_list();

	//insert the data into the list
	int i;
	for (i = 0; i < 10; i++) {
		singly_linked_list_node *new_item = init_singly_linked_list_node(&data[i]);
		insert_tail_singly_linked_list(list, new_item);
	}

	print_singly_linked_list_node(list->head);

	printf("\nReversing the list!\n");
	reverse_singly_linked_list(list);

	print_singly_linked_list_node(list->head);

	printf("\nRemoving the first element\n");
	delete_head_singly_linked_list(list);
	print_singly_linked_list_node(list->head);

	printf("\nRemoving the last element\n");
	delete_tail_singly_linked_list(list);
	print_singly_linked_list_node(list->head);
}
