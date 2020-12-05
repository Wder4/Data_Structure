# AVL tree implementation

## Goal
Develop a program to construct an AVL search tree for fast searching.

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
![](https://i.imgur.com/tyTLEMp.png)

## Architecture
![](https://i.imgur.com/d2rYc86.png)

## Code
```cpp
code
├── p1.c        // main code
├── AVL.c       // function of AVL
├── AVL.h       // definition of AVL
├── Que_LL.c    // function of queue with link list
├── Que_LL.h    // definition of queue
├── Stack_LL.c  // function of stack with link list
└── Stack_LL.h  // definition of stack
```    

## AVL
```cpp
avl_t *avl_new();                              // create an empty tree
void avl_free (tree_t *t);                     // free tree
int avl_h(avl_ele_t *curr);                    // the height of tree
int tree_h(tree_ele_t *curr);                  // the height of tree
void avl_traversal(avl_t *avl, int ch);        // 0: level, 1: in, 2: pre, 3: post
avl_ele_t *avl_nnode(char *s, char *key);
void avl_sch(avl_t *avl, char *s);             // search the key in the tree
void avl_ins(avl_t *avl, char *s, char *key);  // insert the key 
```

## Build and Run
To bulild the p1.exe, run `make` inside the directory where you have the source.
```
$ make p1
```
To run p1.exe with input.txt and prepare output.txt for result.
```
$ make test
```
Return file "output.txt" and print.
```
$ cat output.txt
David Bob Alice Charlie Paul Ruby
Paul 0900000002
Amy null
Ruby 0900000004
```