c11 = gcc -std=c11

p1.out: p1.o sstring.o Stack_LL.o Que_LL.o
	$(c11) -o p1 p1.o sstring.o Stack_LL.o Que_LL.o
p1.o: p1.c sstring.h Stack_LL.h Que_LL.h
	$(c11) -c p1.c

p2.out: p2.o sstring.o Que_LL.o
	$(c11) -o p2 p2.o sstring.o Que_LL.o
p2.o: p2.c sstring.h Que_LL.h
	$(c11) -c p2.c

sstring.o: sstring.c sstring.h
	$(c11) -c sstring.c
Stack_LL.o: Stack_LL.c Stack_LL.h
	$(c11) -c Stack_LL.c
Que_LL.o: Que_LL.c Que_LL.h
	$(c11) -c Que_LL.c

all: p1.out p2.out


clean:
	rm -f *.o