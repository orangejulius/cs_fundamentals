#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdlib.h>

#include "linked_list.h"

typedef struct hashtable {
	int num_buckets;
	int (*hash_fn)(void*, int);
	singly_linked_list **buckets;
} hashtable;

typedef struct hashtable_item {
	char* key;
	void* data;
} hashtable_item;

int default_hash(void* data, int num_buckets) {
	int h = 0, a = 127;
	for (char* v = data; *v != 0; v++)
		h = (a * h + *v) % num_buckets;

	return h;
}

hashtable_item *init_hashtable_item(char* key, void* data)
{
	hashtable_item *item = malloc(sizeof(hashtable_item));

	item->key = key;
	item->data = data;

	return item;
}

hashtable *hashtable_init(int num_buckets, int (*hash_fn)(void*, int))
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

// internal helper functgion to find hashtable_item with given key
hashtable_item* hashtable_find_item(hashtable* ht, char *key)
{
	int bucket = ht->hash_fn(key, ht->num_buckets);

	singly_linked_list_node *node = ht->buckets[bucket]->head;
	if (!node) return 0;

	do {
		hashtable_item *item = node->data;
		if (item->key == key)
			return item;
	} while (node = node->next);

	return 0;
}

//will update value if it already exists
void hashtable_insert(hashtable *ht, char *key, void *data)
{
	int bucket = ht->hash_fn(key, ht->num_buckets);

	hashtable_item *item;
	item = hashtable_find_item(ht, key);
	if (item) {
		item->data = data;
	} else {
		item = init_hashtable_item(key, data);
		insert_singly_linked_list(ht->buckets[bucket], item);
	}
}

void* hashtable_find(hashtable* ht, char *key)
{
	hashtable_item *item = hashtable_find_item(ht, key);
	return item ? item->data : 0;
}
#endif // HASHTABLE_H
