CC = gcc -std=c11

AOE: AOE.o Stack_LL.o Que_LL.o
	$(CC) -o AOE AOE.o Stack_LL.o Que_LL.o

AOE.o: AOE.c Stack_LL.h Que_LL.h
	$(CC) -c AOE.c
Stack_LL.o: Stack_LL.c Stack_LL.h
	$(CC) -c Stack_LL.c
Que_LL.o: Que_LL.c Que_LL.h
	$(CC) -c Que_LL.c

test: 
	./AOE < ../input0_windows.txt > output.txt
chk:
	diff output.txt ../output0_windows.txt
cat:
	cat output.txt

clean:
	rm -f *.o
clexe:
	rm -f *.exe
