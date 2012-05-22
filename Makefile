CFLAGS=-ggdb
APPS=binary_tree linked_list
all: ${APPS}
binary_tree: binary_tree.c binary_tree.h
	gcc ${CFLAGS} binary_tree.c -o binary_tree
linked_list: linked_list.c linked_list.h
	gcc ${CFLAGS} linked_list.c -o linked_list
clean:
	rm ${APPS}
