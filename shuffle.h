#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <stdio.h>
#include <stdlib.h>

#include "swap.h"

//only works for single digit integers for now
char* array_to_string(int array[], int size)
{
	char *string = malloc(sizeof(char)*size+1);
	for(int i = 0; i < size; i++) {
		snprintf(&string[i], 2, "%d", array[i]);
	}
	string[size] = 0;
	return string;
}

void shuffle(int array[], int size)
{
	for (int i = size - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(array, i, j);
	}
}

void incorrect_shuffle(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		swap(array, i, j);
	}
}

#endif // SHUFFLE_H
