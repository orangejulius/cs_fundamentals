#include <assert.h>
#include <string.h>

#include "shuffle.h"

int main()
{
	int small_array[] = {1, 2, 3};
	char *small_array_string = array_to_string(small_array, 3);
	assert(0 == strcmp("123", small_array_string));
}
