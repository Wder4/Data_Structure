#ifndef _QUELL_
#define _QUELL_

typedef struct qnode {
    int data;
    struct qnode *next;
} q_ele_t;

typedef struct {
    int size;
    q_ele_t *head;
    q_ele_t *tail;
} que_t;


que_t *q_new();

void q_free(que_t *q);

bool q_isempty(const que_t *q);

bool q_enq(que_t *q, int key);

int q_deq(que_t *q);

#endif