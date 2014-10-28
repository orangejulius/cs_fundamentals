#include <assert.h>
#include <sys/time.h>

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

double benchmark_sort(void (*sort_fn)(int[], int), int size, int iterations)
{
	struct timeval start;
	gettimeofday(&start, 0);

	for (int i = 0; i < iterations; i++) {
		test_sort(sort_fn, size);
	}

	struct timeval end;
	gettimeofday(&end, 0);

	return end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1e6;
}

typedef struct sort_fn_info
{
	char* name;
	void (*sort_fn)(int[], int);
} sort_fn_info;

