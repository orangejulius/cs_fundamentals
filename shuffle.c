#include <assert.h>
#include <string.h>

#include "hashtable.h"
#include "shuffle.h"

#define ITERATIONS 100000
#define ALLOWED_VARIATON 0.02

int main()
{
	srand(time(NULL));
	int small_array[] = {1, 2, 3};
	char *small_array_string = array_to_string(small_array, 3);
	assert(0 == strcmp("123", small_array_string));

	hashtable* ht = hashtable_init(100, default_hash);
	singly_linked_list *list = init_singly_linked_list();

	for (int i = 0; i < ITERATIONS; i++) {
		int *shuffled_array = malloc(sizeof(int) * 3);
		memcpy(shuffled_array, small_array, sizeof(int) *  3);

		shuffle(shuffled_array, 3);
		char *stringified = array_to_string(shuffled_array, 3);
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

	int expected = ITERATIONS / 6;
	printf("iteration size %d, expected value for each shuffled output %d\n", ITERATIONS, expected);
	printf("value\tcount\n");
	singly_linked_list_node *node = list->head;
	while (node) {
		int actual = *(int*)hashtable_find(ht, node->data);
		double variation = abs(actual - expected) / (float)expected;
		printf("%s\t%d\t%f\n", (char*)node->data, actual, variation);
		assert(variation < ALLOWED_VARIATON);
		node = node->next;
	}
}
