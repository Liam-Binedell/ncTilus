CC = gcc
CFLAGS = -Iinclude -Wall -lncurses

main: main.c
	$(CC) $(CFLAGS) main.c $(wildcard impl/*.c) -o bin/nls

run: main.c
	$(CC) $(CFLAGS) main.c $(wildcard impl/*.c) -o bin/nls && ./bin/nls

clean:
	rm bin/nls
