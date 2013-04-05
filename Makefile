CFLAGS=-std=c99 -g
SRCS=$(wildcard *.c)
APPS=$(patsubst %.c,%,$(SRCS))

all: ${APPS}

clean:
	rm ${APPS} *.o

depend:
	$(CC) $(CFLAGS) -MM $(SRCS) > .depend

test:
	@$(MAKE)
	for exe in $(APPS) ; do \
		./$$exe ; \
		if [ $$? -ne 0 ]; then \
			echo "$$exe did not return 0" ; \
			exit 1 ; \
		fi \
	done

include .depend
