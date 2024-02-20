CC = gcc
CFLAGS = -Wall -Wextra

all: Swallow

Swallow: terminal.o commands.o detect.o tests.o
	$(CC) $(CFLAGS) -o Swallow terminal.o commands.o detect.o tests.o

terminal.o: terminal.c commands.h detect.h
	$(CC) $(CFLAGS) -c terminal.c

commands.o: commands.c commands.h detect.c detect.h
	$(CC) $(CFLAGS) -c commands.c detect.c

tests.o: Arduino/tests.c Arduino/tests.h
	$(CC) $(CFLAGS) -c Arduino/tests.c

clean:
	rm -f Swallow *.o
