#include <assert.h>

#include "hashtable.h"

int main()
{
	hashtable *ht = hashtable_init(20, default_hash);

	hashtable_insert(ht, "foo", "bar");
	hashtable_insert(ht, "hello", "world");

	char** strings = malloc(sizeof(char*)*40);

	for (int i = 0; i < 40; i++) {
		strings[i] = malloc(sizeof(char[10]));
		asprintf(&strings[i], "test%d", i);
		hashtable_insert(ht, strings[i], strings[i]);
	}

	for (int i = 0; i < 40; i++) {
		assert(hashtable_find(ht, strings[i]) == strings[i]);
	}

	assert(hashtable_find(ht, "hello") == "world");
	assert(hashtable_find(ht, "foo") == "bar");
}
