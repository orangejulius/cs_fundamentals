#include <assert.h>

#include "linked_list.h"

int main()
{
	int data[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	singly_linked_list *l1 = init_singly_linked_list();
	singly_linked_list *l2 = init_singly_linked_list();

	insert_singly_linked_list(l1, &data[0]);
	insert_singly_linked_list(l1, &data[1]);
	insert_singly_linked_list(l2, &data[2]);
	insert_singly_linked_list(l2, &data[3]);

	singly_linked_list *l3 = singly_linked_list_join(l1, l2);
	singly_linked_list_node *node = l3->head;

	int i;
	for (i = 0; node != 0; i++) {
		//check correct values are contained
		assert(*(int*)(node->data) == data[i]);
		node = node->next;
	}
	assert(i == 4);//check size

	//ensure nodes in original lists are not modified
	assert(l1->tail->next == 0);
}
