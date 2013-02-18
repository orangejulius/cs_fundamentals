CFLAGS=-std=c99 -g
SRCS=$(wildcard *.c)
APPS=$(patsubst %.c,%,$(SRCS))

all: ${APPS}

clean:
	rm ${APPS}
