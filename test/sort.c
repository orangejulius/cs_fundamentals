#include "sort_test.h"

int main()
{
	test_sort(bubble_sort, 10);
	test_sort(naive_bubble_sort, 10);
	test_sort(bogo_sort, 10);
}
