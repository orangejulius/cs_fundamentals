#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

#include "linked_list.h"

typedef struct hashtable {
	int num_buckets;
	int (*hash_fn)(void*);
	singly_linked_list **buckets;
} hashtable;

typedef struct hashtable_item {
	char* key;
	void* data;
} hashtable_item;

int default_hash(void* data) {
	return *(int*)data;
}

hashtable_item *init_hashtable_item(char* key, void* data)
{
	hashtable_item *item = malloc(sizeof(hashtable_item));

	item->key = key;
	item->data = data;

	return item;
}

hashtable *hashtable_init(int num_buckets, int (*hash_fn)(void*))
{
	hashtable *ht = malloc(sizeof(hashtable));
	ht->num_buckets = num_buckets;
	ht->hash_fn = hash_fn;
	ht->buckets = malloc(sizeof(singly_linked_list*)*num_buckets);

	for (int i = 0; i < num_buckets; i++) {
		ht->buckets[i] = init_singly_linked_list();
	}

	return ht;
}

void hashtable_insert(hashtable *ht, char *key, void *data)
{
	int bucket = ht->hash_fn(key) % ht->num_buckets;

	hashtable_item *item = init_hashtable_item(key, data);

	insert_singly_linked_list(ht->buckets[bucket], item);

}

void* hashtable_find(hashtable* ht, char *key)
{
	int bucket = ht->hash_fn(key) % ht->num_buckets;

	singly_linked_list_node *node = ht->buckets[bucket]->head;

	do {
		hashtable_item *item = node->data;
		if (item->key == key)
			return item->data;
	} while (node = node->next);

	return 0;
}
#endif // HASHTABLE_H
