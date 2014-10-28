#include "sort_test.h"

int main()
{
	sort_fn_info sort_fns[] = { { "bubble", bubble_sort },
		{ "naive bubble", naive_bubble_sort },
		{ "insertion", insertion_sort} };
	int sort_fn_count = sizeof(sort_fns) / sizeof(sort_fns[0]);

	int sort_upto = 1000;
	int step = 100;
	int iterations = 1000;

	printf("benchmarking sort algorithms with %d iterations\n\n", iterations);
	printf("count\t");
	for (int i = 0; i < sort_fn_count; i++) {
		printf("%s\t", sort_fns[i].name);
	}
	printf("\n");
	for (int i = 0; i < sort_upto; i+=step) {
		printf("%d\t", i);
		for (int j = 0; j < 3; j++) {
			double time = benchmark_sort(sort_fns[j].sort_fn, i, iterations);
			printf("%f\t", time);
		}
		printf("\n");
	}
}
