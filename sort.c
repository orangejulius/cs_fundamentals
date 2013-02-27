#include <assert.h>

#include "sort.h"

int main()
{
	int data[] = {3, 5, 7, 2, 1, 9, 0, 8, 6, 4};

	bubble_sort(data, 10);

	for(int i = 0; i < 10; i++) {
		assert(i == data[i]);
	}
}
