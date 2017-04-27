CC = c++
CFLAGS = -Wall

all: main.o
	$(CC) $(CFLAGS) -o stack main.o

main.o: main.cxx stack.hxx
	$(CC) $(CFLAGS) -c main.cxx

clean:
	rm *.o stack
