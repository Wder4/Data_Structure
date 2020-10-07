// stack in array (LIFO)

#ifndef _STACKARR_
#define _STACKARR_
#define MAXSTACK 100

typedef struct {
    int data[MAXSTACK];
    int size;
    int top;
} stack;

typedef struct {
	void (*Init)(stack*);
	int (*isEmpty)(stack*);
	int (*isFull)(stack*);	
    void (*push)(stack*, int);
    int (*pop)(stack*);
    void (*show)(stack*);
} stackLib;
extern const stackLib sLib;

#endif