#include <assert.h>
#include <sys/time.h>

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

void benchmark_sort(void (*sort_fn)(int[], int), int size, int iterations)
{
	struct timeval start;
	gettimeofday(&start, 0);

	for (int i = 0; i < iterations; i++) {
		test_sort(sort_fn, size);
	}

	struct timeval end;
	gettimeofday(&end, 0);

	double elapsed_time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)/1e6;
	printf("ran %d iterations in %f seconds\n", iterations, elapsed_time);
}

int main()
{
	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);

	benchmark_sort(bubble_sort, 100, 100000);
	benchmark_sort(naive_bubble_sort, 100, 100000);
	benchmark_sort(insertion_sort, 100, 100000);
}
