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

typedef struct sort_fn_info
{
	char* name;
	void (*sort_fn)(int[], int);
} sort_fn_info;

int main()
{
	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);
	test_sort(bogo_sort, 10);

	sort_fn_info sort_fns[] = { { "bubble", bubble_sort },
		{ "naieve bubble", naive_bubble_sort },
		{ "insertion", insertion_sort} };
	int sort_fn_count = 3;

	int sort_upto = 10;

	printf("\t");
	for (int i = 0; i < sort_fn_count; i++) {
		printf("%s\t", sort_fns[i].name);
	}
	printf("\n");
	for (int i = 0; i < sort_upto; i++) {
		printf("%d\t", i);
		for (int j = 0; j < 3; j++) {
			double time = benchmark_sort(sort_fns[j].sort_fn, i, 100000);
			printf("%f\t", time);
		}
		printf("\n");
	}
}
