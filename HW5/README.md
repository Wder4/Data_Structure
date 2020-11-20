# Double Hashing Mechanism

## Goal
Implement a double hash mechanism to store inputs.

(hash1(key) + i*hash2(key)) % TABLE_SIZE

hash1(key) = key % TABLE_SIZE

hash2(key) = PRIME – (key % PRIME)

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
![](https://i.imgur.com/ri8Sm0v.png)

## Architecture
![](https://i.imgur.com/sGBv12u.png)

## Code
```cpp
code
├── p1.c         // main function
├── Hash.c       // function of Hash
├── Hash.h       // definition of Hash
└── output.txt
```
## Hash
```cpp
hash_t *h();                  // create a new hash table
h_hash(hash_t *h, int key);   // add key into the hash table
```

## Build and Run
Bulild the p1.exe, run `make` inside the directory where you have the source.
```cpp
$ make 
```
Test
```cpp
$ make test
```
Check the output.txt
```
$ cat output.txt
0->77
1->98
2->2
3->37
4->56
5->31
6->45
7->85
8->8
9->70
10->10
11->24
12->64
```