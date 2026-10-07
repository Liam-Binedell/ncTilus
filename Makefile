CC = gcc
CFLAGS = -Wall -lncurses

main: main.c
	$(CC) $(CFLAGS) main.c $(wildcard impl/*.c) -o nls

run: main.c
	$(CC) $(CFLAGS) main.c $(wildcard impl/*.c) -o bin/nls && ./bin/nls

clean:
	rm nls
