CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: tinygrep

tinygrep: tinygrep.c
	$(CC) $(CFLAGS) -o tinygrep tinygrep.c

run: tinygrep
	./tinygrep life bible.txt

clean:
	rm -f tinygrep


