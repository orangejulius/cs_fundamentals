CFLAGS=-std=c99 -g
SRCS=$(wildcard *.c)
APPS=$(patsubst %.c,%,$(SRCS))

all: ${APPS}

clean:
	rm ${APPS} *.o

depend:
	$(CC) $(CFLAGS) -MM $(SRCS) > .depend

include .depend
