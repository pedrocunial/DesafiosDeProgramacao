CC = c++
CFLAGS = -Wall

all: charstack.o main.o
	$(CC) $(CFLAGS) -o charstack charstack.o main.o

main.o: main.cxx charstack.hxx
	$(CC) $(CFLAGS) -c main.cxx

charstack.o: charstack.cxx charstack.hxx
	$(CC) $(CFLAGS) -c charstack.cxx

clean:
	rm *.o charstack
