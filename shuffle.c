#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "factorial.h"
#include "hashtable.h"
#include "shuffle.h"

#define ITERATIONS 1000000

void test_shuffle(int size, void (*shuffle_fn)(int[], int), float allowed_variation)
{
	int *array = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++ ) {
		array[i] = i;
	}
	char *array_string = array_to_string(array, size);

	hashtable* ht = hashtable_init(100, default_hash);
	singly_linked_list *list = init_singly_linked_list();

	for (int i = 0; i < ITERATIONS; i++) {
		int *shuffled_array = malloc(sizeof(int) * size);
		memcpy(shuffled_array, array, sizeof(int) *  size);

		shuffle_fn(shuffled_array, size);
		char *stringified = array_to_string(shuffled_array, size);
		int *count = hashtable_find(ht, stringified);
		if (count == 0) {
			count = malloc(sizeof(int));
			*count = 1;
			insert_singly_linked_list(list, stringified);
		} else {
			(*count)++;
		}
		hashtable_insert(ht, stringified, count);
	}

	int expected = ITERATIONS / factorial(size);
	printf("array size: %d\n", size);
	printf("iteration size %d\n", ITERATIONS);
	printf("expected value for each combination %d\n", expected);
	printf("value\tcount\n");
	singly_linked_list_node *node = list->head;
	while (node) {
		int actual = *(int*)hashtable_find(ht, node->data);
		double variation = abs(actual - expected) / (float)expected;
		printf("%s\t%d\t%f\n", (char*)node->data, actual, variation);
		assert(variation < allowed_variation);
		node = node->next;
	}
}

int main()
{
	srand(time(NULL));

	test_shuffle(3, shuffle, 0.02);
	test_shuffle(3, incorrect_shuffle, 1);

	test_shuffle(5, shuffle, 0.1);
}
