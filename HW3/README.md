# P1. Queueing in campus cafeteria

## Goal
Use link list to implement stack and queue 

## Enviroment
```
$ uname -a
MSYS_NT-10.0-19041 DESKTOP-L3NKTB9 3.1.6-340.x86_64 2020-07-09 14:33 UTC x86_64    Msys
$ gcc --version
gcc (MinGW.org GCC-6.3.0-1) 6.3.0
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
## Screenshot (p1_output.txt)
![](https://i.imgur.com/BVllB8o.png)

## Architecture
![](https://i.imgur.com/8ILSk09.png)

## Programs
`p1.c`： main code

`sstring.h`： function for string

`Stack_LL.h`： use link list to implement stack

`CQue_LL.h`： use link list to implement queue


## stack
```cpp
stack_t *s_new()                    //create an empty stack
void s_free(stack_t *s)             //free stack
bool s_isEmpty(const stack *s)      //if stack is empty, return 1
bool s_push(stack_t *s, char *val)  //push value into stack
char *s_pop(stack_t *s)             //delete from a stack, and return value
```

## queue
```cpp
que_t *q_new()                     //create an empty queue
void q_free(que_t *q)              //free queue
bool que_isempty(que_t *q)         //if queue is empty, return 1
bool q_enq(que_t *q, char *s)      //push value into queue
char *q_deq(que_t *q)              //delete from a queue, and return value
```

## To create a stack or queue
```cpp
stack_t *st = s_new();
que_t *q = q_new();
```


## Build and Run
To bulild the p1.exe, run `make` inside the directory where you have the source.
```
$ make p1.out
```
To run p1.exe with input.txt and prepare output.txt for result.
```
$ ./p1 < input.txt > output.txt
```
Return file "output.txt" and print.
```
$ ./p1 < p1_input.txt > p1_output.txt
```
Print p1_output.txt
```
$ cat p1_output.txt
54
98
3
1
30
```

---
# P2. Solitaire

## Goal
Use queue with link list to draw out the cards in right order

## Enviroment
```
$ uname -a
MSYS_NT-10.0-19041 DESKTOP-L3NKTB9 3.1.6-340.x86_64 2020-07-09 14:33 UTC x86_64 Msys
$ gcc --version
gcc (MinGW.org GCC-6.3.0-1) 6.3.0
Copyright (C) 2016 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## Screenshot(p2_output.txt)
![](https://i.imgur.com/SvI0l1P.png)

## Architecture
![](https://i.imgur.com/5muIojD.png)

## Build and Run
To bulild the p2.exe, run `make` inside the directory where you have the source.
```
$ make p2.out
```
To run p2.exe with input.txt and prepare output.txt for result.
```
$ ./p2 < p2_input.txt > p2_output.txt
```
Print p2_output.txt.
```
$ cat p2_output.txt
K 3 5 9 A 10 2 8 4 Q 6 7 J 
3 5 9 A 10 2 8 4 Q 6 7 J
5 9 A 10 2 8 4 Q 6 7 J 3
9 A 10 2 8 4 Q 6 7 J 3 5
A 10 2 8 4 Q 6 7 J 3 5 9
10 2 8 4 Q 6 7 J 3 5 9 A
2 8 4 Q 6 7 J 3 5 9 A 10
8 4 Q 6 7 J 3 5 9 A 10 2
4 Q 6 7 J 3 5 9 A 10 2 8
Q 6 7 J 3 5 9 A 10 2 8 4
6 7 J 3 5 9 A 10 2 8 4
7 J 3 5 9 A 10 2 8 4 6
J 3 5 9 A 10 2 8 4 6 7
3 5 9 A 10 2 8 4 6 7
5 9 A 10 2 8 4 6 7 3
9 A 10 2 8 4 6 7 3 5
A 10 2 8 4 6 7 3 5 9
10 2 8 4 6 7 3 5 9 A
2 8 4 6 7 3 5 9 A
8 4 6 7 3 5 9 A 2
4 6 7 3 5 9 A 2 8
6 7 3 5 9 A 2 8 4
7 3 5 9 A 2 8 4 6
3 5 9 A 2 8 4 6 7
5 9 A 2 8 4 6 7 3
9 A 2 8 4 6 7 3 5
A 2 8 4 6 7 3 5
2 8 4 6 7 3 5 A
8 4 6 7 3 5 A 2
4 6 7 3 5 A 2
6 7 3 5 A 2 4
7 3 5 A 2 4 6
3 5 A 2 4 6
5 A 2 4 6 3
A 2 4 6 3 5
2 4 6 3 5 A
4 6 3 5 A 2
6 3 5 A 2 4
3 5 A 2 4
5 A 2 4 3
A 2 4 3
2 4 3 A
4 3 A 2
3 A 2
A 2
2 A
A
```
