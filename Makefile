all: linked_list
linked_list: linked_list.c linked_list.h
	gcc linked_list.c -o linked_list
