CC=c99
CFLAGS=-g
APPS=binary_tree grid linked_list stack stack_with_min
all: ${APPS}
binary_tree: binary_tree.c binary_tree.h
	${CC} ${CFLAGS} binary_tree.c -o binary_tree
grid: grid.c grid.h
	${CC} ${CFLAGS} grid.c -o grid
linked_list: linked_list.c linked_list.h
	${CC} ${CFLAGS} linked_list.c -o linked_list
stack: stack.c stack.h linked_list.h
	${CC} ${CFLAGS} stack.c -o stack
stack_with_min: stack_with_min.c stack_with_min.h stack.h linked_list.h
	${CC} ${CFLAGS} stack_with_min.c -o stack_with_min
clean:
	rm ${APPS}
