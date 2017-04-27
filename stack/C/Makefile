CC = gcc
CFLAGS = -Wall

all: charstack.o main.o
	$(CC) $(CFLAGS) -o charstack charstack.o main.o

main.o: main.c charstack.h
	$(CC) $(CFLAGS) -c main.c

charstack.o: charstack.c charstack.h
	$(CC) $(CFLAGS) -c charstack.c

clean:
	rm *.o charstack
