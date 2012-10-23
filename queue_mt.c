#include <assert.h>
#include <stdlib.h>

#include "queue_mt.h"

int main()
{
	//creating a queue should give an empty queue
	queue_mt *queue = init_queue_mt();

	assert(queue->head == 0);
	assert(queue->tail == 0);
}
