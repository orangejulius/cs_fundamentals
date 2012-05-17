#include <stdio.h>

#include "linked_list.h"

int main()
{
	int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//initialize the first entry in the list
	singly_linked_list *head = init_singly_linked_list(&data[0]);
	printf("initialized singly_linked_list at %p with data %d\n", head, *(int *)(head->data));
}
