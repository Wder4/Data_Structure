# Binary Search Tree - Deletion

## Goal
To build a binary search tree and delete nodes from tree.
Print out the rest of node in **level order**

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
![](https://i.imgur.com/giAgQJx.png)

## Architecture
![](https://i.imgur.com/ejjs0R1.png)

## Code
```cpp
code
├── p1.c        // main code
├── BST.c       // function of BST
├── BST.h       // definition of BST
├── Que_LL.c    // function of queue with link list
└── Que_LL.h    // definition of queue
```    

## BST
```cpp
tree_t *tree_new();                                       // create an empty tree
void tree_free (tree_t *t);                               // free tree
bool tree_isempty(const tree_t *t);                       // if tree is empty, return 1
int tree_h(tree_ele_t *curr);                             // the height of tree
void tree_traversal(tree_t *t, que_t *q, int ch, int h);  // 0: level, 1: in, 2: pre, 3: post
bool tree_sch(const tree_t *t, int key);                  // search the key in the tree
bool tree_ins(tree_t *t, int key);                        // insert the key 
bool tree_del(tree_t *t, int key);                        // delete the key
```

## Build and Run
To build the p1.exe, run `make` inside the directory where you have the source.
```
$ make 
```
To run p1.exe with input.txt and prepare output.txt for result.
```
$ ./p1 < input0_windows.txt > output.txt
```
Return file "output.txt" and print.
```
$ cat output.txt
1
3
2
4
```
