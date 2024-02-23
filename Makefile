CC = gcc
CFLAGS = -Wall -Wextra

all: Swallow

Swallow: terminal.o commands.o detect.o tests.o
	$(CC) $(CFLAGS) -o Swallow terminal.o commands.o detect.o tests.o

terminal.o: Terminal/terminal.c Terminal/commands.h Terminal/detect.h
	$(CC) $(CFLAGS) -c Terminal/terminal.c

commands.o: Terminal/commands.c Terminal/commands.h Terminal/detect.c Terminal/detect.h
	$(CC) $(CFLAGS) -c Terminal/commands.c Terminal/detect.c

tests.o: Arduino/tests.c Arduino/tests.h
	$(CC) $(CFLAGS) -c Arduino/tests.c

clean:
	rm -f Swallow *.o
