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

int main()
{
	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);
	test_sort(bogo_sort, 10);

	double time;
	for (int i = 0; i < 10; i++) {
		time = benchmark_sort(bubble_sort, i, 100000);
		printf("bubble sorted %d entries in %f seconds\n", i, time);
		time = benchmark_sort(naive_bubble_sort, i, 100000);
		printf("naievely bubble sorted %d entries in %f seconds\n", i, time);
		time = benchmark_sort(insertion_sort, i, 100000);
		printf("insertion sorted %d entries in %f seconds\n", i, time);
		time = benchmark_sort(bogo_sort, i, 100000);
		printf("bogo sorted %d entries in %f seconds\n", i, time);
		printf("\n");
	}
}
