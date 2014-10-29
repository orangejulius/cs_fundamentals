#include <assert.h>

#include "sort_test.h"

void test_partition()
{
	int data[] = { 5, 9, 7, 2, 4, 8, 3, 1, 0, 6 };
	int data_size = sizeof(data)/sizeof(data[0]);

	int last = data[data_size - 1];
	int retval = partition(data, 0, data_size - 1);

	int partition_element = 6;
	assert(retval == partition_element);
	for (int i = 0; i < data_size; i++) {
		if (i < partition_element) {
			assert(data[i] < partition_element);
		} else if (i > partition_element) {
			assert(data[i] > partition_element);
		} else {
			assert(data[i] == partition_element);
		}
	}
}
int main()
{
	test_partition();

	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);
	test_sort(insertion_sort, 10);
	test_sort(bogo_sort, 10);
}
