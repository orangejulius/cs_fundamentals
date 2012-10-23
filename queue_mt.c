#include <assert.h>
#include <stdlib.h>

#include "queue_mt.h"

int main()
{
	//creating a queue should give an empty queue
	queue_mt *queue = init_queue_mt();

	assert(queue->head == 0);
	assert(queue->tail == 0);

	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	//enqeuing the first item should modify head and tail, and point to the data
	enqueue(queue, &data[0]);

	assert(queue->head == queue->tail);
	assert(queue-> head != 0);
	assert(queue->head->data == &data[0]);

	//dequeueing the first item should reset everything back
	//while returning the data item
	int *returnedData = dequeue(queue);
	assert(returnedData == &data[0]);
	assert(queue->head == 0);
	assert(queue->tail == 0);
}
