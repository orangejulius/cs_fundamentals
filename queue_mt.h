#ifndef QUEUE_MT_H
#define QUEUE_MT_H

#include "linked_list.h"

//a queue can just be implemented as a singly linked list
//so the existing datastructure will be reused, and most operations
//for fine-grained locks, linked list functions won't be resued
typedef singly_linked_list queue_mt;

queue_mt *init_queue_mt()
{
	queue_mt *queue = malloc(sizeof(queue_mt));

	queue->head = 0;
	queue->tail = 0;

	return queue;
}

void enqueue(queue_mt *queue, void* data)
{
	singly_linked_list_node *node = init_singly_linked_list_node(data);

	if (queue->head && queue->tail) {
		queue->tail->next = node;
		queue->tail = node;
	} else {
		queue->head = queue->tail = node;
	}
}

void* dequeue(queue_mt *queue)
{
	void* data = queue->head->data;

	if (queue->head != queue->tail) {
		queue->head = queue->head->next;
	} else {
		queue->head = queue->tail = 0;
	}

	return data;
}
#endif // QUEUE_MT_H
