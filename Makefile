CC=c99
CFLAGS=-g
SRC=$(wildcard *.c)
APPS=$(patsubst %.c,%,$(SRC))

all: ${APPS}

clean:
	rm ${APPS}
