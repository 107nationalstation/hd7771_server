CC=gcc

all: main.c treap.c
	$(CC) -o hd7771_server main.c treap.c

clean:
	rm -f *.o hd7771_server
