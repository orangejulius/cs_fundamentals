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

	enqueue(queue, &data[0]);

	assert(queue->head == queue->tail && queue-> head != 0);
}
