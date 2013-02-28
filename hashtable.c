#include <assert.h>
#include <string.h>

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

	hashtable_insert(ht, "hello", "world2");
	hashtable_find(ht, "hello");
	assert(strcmp(hashtable_find(ht, "hello"), "world2") == 0);

	char *one, *two, *data;
	asprintf(&one, "test");
	asprintf(&two, "test");
	asprintf(&data, "data");
	assert(one != two);

	//test hash function returns the same value for identical
	//strings at different addresses
	assert(default_hash(one, 20) == default_hash(two, 20));
	assert(default_hash(one, 20) == default_hash("test", 20));

	//test hash function looks at more than the first 4 bytes
	char *three;
	asprintf(&three, "testb");
	assert(default_hash(one, 20) != default_hash(three, 20));
}
