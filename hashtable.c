#include <assert.h>

#include "hashtable.h"

int main()
{
	hashtable *ht = hashtable_init(20, default_hash);

	hashtable_insert(ht, "foo", "bar");

	assert(hashtable_find(ht, "foo") == "bar");
}
