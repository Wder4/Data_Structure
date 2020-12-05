#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "Que_LL.h"

que_t *q_new() {
    que_t *q = malloc(sizeof(que_t));
    if (!q)
        return NULL;
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void q_free(que_t *q) {
    if (!q)
        return;
    while (q->head) {
        q_ele_t *tmp = q->head;
        q->head = q->head->next;
        free(tmp);
    }
    free(q);
}

bool q_isempty(const que_t *q) {
    return !(q->size) ? true : false;
}

bool q_enq(que_t *q, void *addr) {
    if (!q || q->size == INT_MAX)
        return false;

    q_ele_t *node = (q_ele_t*) malloc(sizeof(q_ele_t)); 
    if (node == NULL) {
        free(node);
        return false;
    }
    
    node->addr = addr;
    node->next = NULL;

    if (q->size == 0)  // empty queue
        q->head = node;
    else
        q->tail->next = node;

    q->tail = node;
    q->size++;

    return true;
}

void *q_deq(que_t *q) {  // rm head
    if (q_isempty(q) || !q)
        return false;

    q_ele_t *rmnode = q->head;
    void *addr = rmnode->addr;

    q->head = q->head->next;
    q->size--;
    
    free(rmnode);

    return addr;
}

// int main()
// {
//     que_t *q = q_new();
//     char s[] = "abc";
//     char *str;
//     // char *str;
//     q_enq(q, s);
//     q_enq(q, "1230");
//     q_enq(q, "55555555555555555555555555555555555555555555555555555");
//     q_enq(q, "545");
//     str = q_deq(q);
//     puts(str);
//     free(str);
//     str = q_deq(q);
//     puts(str);
//     free(str);
//     str = q_deq(q);
//     puts(str);
//     free(str);


//     return 0;

// }