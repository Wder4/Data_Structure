// circular queue in array (FIFO)

#ifndef _CQUEARR_
#define _CQUEARR_
#define MAXQUE 100

typedef struct {
	int data[MAXQUE];
	int front;
	int rear;
} queue;

typedef struct {
	void (*Init)(queue*);
	int (*isEmpty)(queue*);
	int (*isFull)(queue*);	
	void (*enque)(queue*, int);
	int (*deque)(queue*);
	void (*show)(queue*);
} queLib;
extern const queLib qLib;

#endif