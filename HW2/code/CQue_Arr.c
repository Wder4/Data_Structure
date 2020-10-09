// circular queue in array (FIFO)

#include <stdio.h>
#include "CQue_Arr.h"

void QInit (queue *q) {
	q->front = 0;
	q->rear = 0;
}

int isQEmpty(queue *q) {
	if(q->front == q->rear)
		return 1;
	return 0;
}

int isQFull(queue *q) {
	if(q->front == (q->rear + 1) % MAXQUE)
		return 1;
	return 0;
}

void enque(queue *q, int value) {
	if (isQFull(q))
		return;
	q->rear = (q->rear + 1) % MAXQUE;
	q->data[q->rear] = value;
}

int deque(queue *q) {
	if(isQEmpty(q)) {
		printf("queue is empty\n");
		return 0;
	}
	q->front = (q->front + 1) % MAXQUE;
	return q->data[q->front];
}

void QShow(queue *q) {
	if (isQEmpty(q))
		printf("queue is empty");
	int i = q->front;
	while(i != q->rear) {
		i = (i + 1) % MAXQUE;
		printf("%d ", q->data[i]);
	}
	puts(" ");
}

const queLib qLib = {
    .Init = QInit,
	.isEmpty = isQEmpty,
    .isFull = isQFull,
	.enque = enque,
	.deque = deque,
	.show = QShow,
};

