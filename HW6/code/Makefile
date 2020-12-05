CC = gcc -std=c11

p1: p1.o AVL.o Stack_LL.o Que_LL.o
	$(CC) -o p1 p1.o AVL.o Stack_LL.o Que_LL.o
AVL: AVL.o Stack_LL.o Que_LL.o
	$(CC) -o AVL AVL.o Stack_LL.o Que_LL.o

p1.o: p1.c AVL.h
	$(CC) -c p1.c
AVL.o: AVL.c AVL.h Stack_LL.h Que_LL.h
	$(CC) -c AVL.c
Stack_LL.o: Stack_LL.c Stack_LL.h
	$(CC) -c Stack_LL.c
Que_LL.o: Que_LL.c Que_LL.h
	$(CC) -c Que_LL.c

test: 
	./p1 < ../input0_windows.txt  > output.txt

clean:
	rm -f *.o
clexe:
	rm -f *.exe


