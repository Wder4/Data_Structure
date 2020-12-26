# Queueing in campus cafeteria

## Goal
Use stack to stimulate the plate stack and queue to record the customers. 

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

## Programs
`sstring.h`：   function for string

`Stack_Arr.h`： create with array

`CQue_Arr.h`：  circular queue with array

## To create a stack or queue
```cpp
stack *sptr, st;
sptr = &st;     
sLib.Init(sptr);  // create an empty stack
queue *qptr, q;
qptr = &q;      
qLib.Init(qptr);  // create an empty queue
```
## sLib(functions for stack)
```cpp
void Init(stack*)       //create an empty stack
int isEmpty(stack*)     //if stack is empty, return 1
int isFull(stack*)      //if stack is full, return 1 
void push(stack*, int)  //add to a stack
int pop(stack*)         //delete from a stack, and return value
void show(stack*)       //print the value in the stack
```

## qLib(functions for circular queue)
```cpp
void Init(queue*)        //create an empty queue
int isEmpty(queue*)      //if queue is empty, return 1
int isFull(queue*)       //if queue is full, return 1 
void enque(queue*, int)  //add to a queue
void deque(queue*)       //delete from a queue, and return value
void show(queue*)        //print the value in the queue
```
## Build and Run
To build the Cafeteria.exe, run `make` inside the directory where you have the source.
```
$ make
```
To run Cafeteria.exe with input.txt and prepare output.txt for result.
```
$ .\Cafeteria input.txt output.txt
```
Return file "output.txt" and print.
```
$ .\Cafeteria input.txt output.txt
customer: A, plate: 54
customer: B, plate: 98
customer: A, plate: 3
customer: B, plate: 1
customer: B, plate: 30
```
Print output.txt.
```
$ cat output.txt
54
98
3
1
30
```
