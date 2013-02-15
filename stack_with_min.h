#ifndef STACK_WITH_MIN_H
#define STACK_WITH_MIN_H

#include "stack.h"

//use two stacks to keep track of all elements
//as well as the current minimum element
typedef struct stack_with_min {
	stack* main;
	stack* min;
} stack_with_min;

stack_with_min *init_stack_with_min()
{
	stack_with_min* s = malloc(sizeof(stack_with_min));
	s->main = init_stack();
	s->min = init_stack();
	return s;
}

void push_stack_with_min(stack_with_min *stack, void* data)
{
	void* min = peek_stack(stack->min);
	if (min == 0 || *(int*)data <= *(int*)min)
		push_stack(stack->min, data);
	push_stack(stack->main, data);
}

void* min_stack(stack_with_min *stack)
{
	return peek_stack(stack->min);
}

void* peek_stack_with_min(stack_with_min *stack)
{
	return peek_stack(stack->main);
}

void* pop_stack_with_min(stack_with_min *stack)
{
	void* min = peek_stack(stack->min);
	void* top = peek_stack(stack->main);
	if (min && *(int*)top == *(int*)top)
		pop_stack(stack->min);
	pop_stack(stack->main);
	return top;
}

#endif // STACK_WITH_MIN_H
