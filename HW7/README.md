# Activity On Edge Network

## Goal
Write a program that allows a user to find all critical paths from a given AOE network.

## Input
<$a_0$, $v_s$, $v_e$, $w$>
* $a_0$ : the activity
* $v_s$ : the starting vertex
* $v_e$ : the ending vertex
* $w$ : the weight of the activity

## Output
<$a_0$, $e_t$, $l_t$>
* $a_0$ : the activity
* $e_t$ : early time
* $l_t$ : late time

the last line : $critical\;\;path$

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

## Screenshot (output.txt)
![](https://i.imgur.com/8zZJq4m.png)

## Architecture
![](https://i.imgur.com/qjcgGA2.png)

## Code
```cpp
code/
├── Makefile 
├── AOE.c       // main code
├── Que_LL.c    // function of queue with link list
├── Que_LL.h    // definition of queue
├── Stack_LL.c  // function of stack with link list
└── Stack_LL.h  // definition of stack
```

## Function
```cpp
act_ele_t *act_new(int edge, int strt, int end, int wt)  // create a new node
int get_vnum(int *arr, int col)  // get the number of the vertices
```

## Build and Run
To build the p1.exe, run `make` inside the directory where you have the source.
```
$ make 
```
To run AOE.exe with input.txt and generate output.txt for result.
```
$ make test
```
To check the correctness of the result
```
$ make chk
```
To print the output.txt
```
$ make cat
```