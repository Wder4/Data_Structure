CC = gcc -std=c11

p1: p1.o Hash.o
	$(CC) -o p1 p1.o Hash.o
p1.o: p1.c Hash.h 
	$(CC) -c p1.c
Hash.o: Hash.c Hash.h 
	$(CC) -c Hash.c 

test: 
	./p1 < ../input0_windows.txt > output.txt

clean:
	rm -f *.o

clexe:
	rm -f *.exe