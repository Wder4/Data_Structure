// stack in array (LIFO)

#include <stdio.h>
#include "Stack_Arr.h"

void SInit (stack *st) {
    st->size = 0;
    st->top = -1;
}

int isSEmpty(stack *st) {
    if (st->top < 0)
        return 1;
    else
        return 0;
}

int isSFull(stack *st) {
    if (st->top >= MAXSTACK)
        return 1;
    else
        return 0;
}

void push(stack *st, int value) {
    if (sLib.isFull(st)) 
        return;
    st->data[++st->top] = value;
    ++st->size;
}

int pop(stack *st) {
    if (sLib.isEmpty(st)) 
        return 0;
    int out = st->data[st->top];
    --st->top;
    --st->size;
    return out;
}

void SShow(stack *st) {
    if (isSEmpty(st))
		printf("stack is empty");
    for (int i = 0; i < st->size; ++i)
        printf("%d ", st->data[i]);
    puts(" ");
}

const stackLib sLib = {
    .Init = SInit,
	.isEmpty = isSEmpty,
    .isFull = isSFull,
    .push = push,
    .pop = pop,
    .show = SShow,
};