CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -pedantic

sort: sort.c
	$(CC) $(CFLAGS) sort.c -o sort

run: sort.exe
	./sort.exe -n -r < test_file.txt

clean:
	rm -f sort
