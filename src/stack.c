#include "stack.h"

int main()
{
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	stack *stack = init_stack();

	for (int i = 0; i < 10; i++) {
		push_stack(stack, data+i);
	}

	while (1) {
		int *popped = pop_stack(stack);
		if (popped) {
			printf("popped %d\n", *popped);
		} else {
			break;
		}
	}
}
