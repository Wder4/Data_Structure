#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "Stack_LL.h"


stack_t *s_new() {
    stack_t *s = malloc(sizeof(stack_t));
    if(!s)
        return NULL;
    s->top = NULL;
    s->size = 0;
    return s;
}

void s_free(stack_t *s) {
    if (!s)
        return;
    while (s->top) {
        st_ele_t *tmp = s->top;   
        s->top = s->top->next;
        free(tmp);
    }
    free(s);
}

bool s_isempty(const stack_t *s) {
    return (s->top) ? false : true; 
}

bool s_push(stack_t *s, int key) {
    if (!s || s->size == INT_MAX)
        return false;
    st_ele_t *node = malloc(sizeof(st_ele_t));
    if (node == NULL) { 
        free(node);
        return false;
    }
    node->data = key;
    node->next = s->top;
    s->top = node;
    s->size++;
    return true;
}

int s_pop(stack_t *s) {
    if(s_isempty(s))
        printf("empty\n");
    assert(!s_isempty(s));
    st_ele_t *rmnode = s->top;
    int res = rmnode->data;
    s->top = rmnode->next;
    s->size--;

    free(rmnode);
    return res;
}





