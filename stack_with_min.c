#include <assert.h>

#include "stack_with_min.h"

int main()
{
	int data[] = {5, 2, 7, 9, 1};
	stack_with_min *stack_with_min = init_stack_with_min();

	int i;
	for (i = 0; i < 5; i++) {
		push_stack_with_min(stack_with_min, data+i);
	}

	assert(*(int*)min_stack(stack_with_min) == 1);
	assert(*(int*)pop_stack_with_min(stack_with_min) == 1);

	assert(*(int*)min_stack(stack_with_min) == 2);
	assert(*(int*)peek_stack_with_min(stack_with_min) == 9);
}
