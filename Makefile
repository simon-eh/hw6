CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic

all: sort

sort: sort.c
	$(CC) $(CFLAGS) sort.c -o sort

clean:
	rm -f sort
