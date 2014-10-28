#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

void test_hash_function_same()
{
	//test hash function returns the same value for identical
	//strings at different addresses
	char* one = "test";
	char* two = "test";

	assert(&one != &two);
	assert(default_hash(&one, 20) == default_hash(&two, 20));
	assert(default_hash(one, 20) == default_hash("test", 20));
}

void test_hash_function_different()
{
	char* one = "one";
	char* two = "two";

	assert(default_hash(&one, 20) != default_hash(&two, 20));
}

void test_hash_function_long_compare()
{
	//test hash function looks at more than the first 4 bytes
	char* one = "test";
	char* two = "testlong";
	assert(default_hash(one, 20) != default_hash(two, 20));
}

void test_hashtable_insert_and_find_simple()
{
	hashtable *ht = hashtable_init(20, default_hash);

	hashtable_insert(ht, "foo", "bar");
	hashtable_insert(ht, "hello", "world");

	assert(hashtable_find(ht, "hello") == "world");
	assert(hashtable_find(ht, "foo") == "bar");

	hashtable_insert(ht, "hello", "world2");
	hashtable_find(ht, "hello");
	assert(strcmp(hashtable_find(ht, "hello"), "world2") == 0);
}

void test_hashtable_insert_and_find_many()
{
	hashtable *ht = hashtable_init(20, default_hash);

	char** strings = malloc(sizeof(char*)*40);
	int print_result;

	for (int i = 0; i < 40; i++) {
		strings[i] = malloc(sizeof(char[10]));
		print_result = asprintf(&strings[i], "test%d", i);
		assert(print_result != -1);
		hashtable_insert(ht, strings[i], strings[i]);
	}

	for (int i = 0; i < 40; i++) {
		assert(hashtable_find(ht, strings[i]) == strings[i]);
	}
}

void test_hashtable_insert_find_identical()
{
	//test inserting and retrieving with identical strings
	//at different addresses works
	//
	char* one = "test";
	char* two = "test";
	hashtable *ht = hashtable_init(20, default_hash);

	char* data = "somedata";
	hashtable_insert(ht, one, data);
	char *out = hashtable_find(ht, two);

	assert(0 != out);
	assert(out == data);
	assert(0 == strcmp(out, data));
}

int main()
{
	test_hash_function_same();
	test_hash_function_different();
	test_hash_function_long_compare();

	test_hashtable_insert_and_find_simple();
	test_hashtable_insert_and_find_many();
	test_hashtable_insert_find_identical();
}
