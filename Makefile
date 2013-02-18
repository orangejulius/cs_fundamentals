CC=c99
CFLAGS=-g
SRCS=$(wildcard *.c)
APPS=$(patsubst %.c,%,$(SRCS))

all: ${APPS}

clean:
	rm ${APPS}
