CC = gcc -std=c11

p1: p1.o BST.o Que_LL.o
	$(CC) -o p1 p1.o BST.o Que_LL.o

BST: BST.o Que_LL.o  
	$(CC) -o BST BST.o Que_LL.o 

p1.o: p1.c BST.h 
	$(CC) -c p1.c
BST.o: BST.c BST.h
	$(CC) -c BST.c
Que_LL.o: Que_LL.c Que_LL.h
	$(CC) -c Que_LL.c

all: p1 BST

clean:
	rm -f *.o