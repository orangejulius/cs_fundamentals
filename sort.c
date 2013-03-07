#include <assert.h>

#include "shuffle.h"
#include "sort.h"

void test_sort(void (*sort_fn)(int[], int), int size)
{
	int *data = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		data[i] = i;
	}

	shuffle(data, size);
	sort_fn(data, size);

	for(int i = 0; i < size; i++) {
		assert(i == data[i]);
	}
}

int main()
{
	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);
}
