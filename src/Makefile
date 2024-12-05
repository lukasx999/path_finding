CC=gcc
CFLAGS=-Wall -Wextra -ggdb -std=c99 -pedantic
LIBS=-lraylib
DEPS=path_finding.h


all: main.o path_finding.o renderer.o $(DEPS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o out

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o out

.PHONY: clean
