c11 = gcc -std=c11
Cafeteria.out: Cafeteria.o sstring.o Stack_Arr.o CQue_Arr.o
	$(c11) -o Cafeteria Cafeteria.o sstring.o Stack_Arr.o CQue_Arr.o
Cafeteria.o: Cafeteria.c sstring.h Stack_Arr.h CQue_Arr.h
	$(c11) -c Cafeteria.c
sstring.o: sstring.c sstring.h
	$(c11) -c sstring.c
Stack_Arr.o: Stack_Arr.c Stack_Arr.h
	$(c11) -c Stack_Arr.c
CQue_Arr.o: CQue_Arr.c CQue_Arr.h
	$(c11) -c CQue_Arr.c

clean:
	rm -f *.o
	