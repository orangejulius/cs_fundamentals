#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

int main()
{
	hashtable *ht = hashtable_init(20, default_hash);

	hashtable_insert(ht, "foo", "bar");
	hashtable_insert(ht, "hello", "world");

	char** strings = malloc(sizeof(char*)*40);
	int print_result;

	for (int i = 0; i < 40; i++) {
		strings[i] = malloc(sizeof(char[10]));
		print_result = asprintf(&strings[i], "test%d", i);
		if (print_result == -1) {
			return -1;
		}
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
	print_result = asprintf(&one, "test");
	if (print_result == -1) {
			return -1;
	}
	print_result = asprintf(&two, "test");
	if (print_result == -1) {
			return -1;
	}
	print_result = asprintf(&data, "data");
	if (print_result == -1) {
			return -1;
	}
	assert(one != two);

	//test hash function returns the same value for identical
	//strings at different addresses
	assert(default_hash(one, 20) == default_hash(two, 20));
	assert(default_hash(one, 20) == default_hash("test", 20));

	//test hash function looks at more than the first 4 bytes
	char *three;
	print_result = asprintf(&three, "testb");
	if (print_result == -1) {
			return -1;
	}
	assert(default_hash(one, 20) != default_hash(three, 20));

	//test inserting and retrieving with indentical strings
	//at different addresses works
	hashtable_insert(ht, one, data);
	char *out = hashtable_find(ht, two);
	assert(0 != out);
	assert(out == data);
	assert(0 == strcmp(out, data));
}
