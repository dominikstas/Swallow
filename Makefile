CC = gcc
CFLAGS = -Wall -Wextra

all: Swallow

Swallow: terminal.o commands.o
	$(CC) $(CFLAGS) -o Swallow terminal.o commands.o

terminal.o: terminal.c commands.h
	$(CC) $(CFLAGS) -c terminal.c

commands.o: commands.c commands.h
	$(CC) $(CFLAGS) -c commands.c

clean:
	rm -f Swallow *.o