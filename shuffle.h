#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <stdlib.h>

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

#endif // SHUFFLE_H
