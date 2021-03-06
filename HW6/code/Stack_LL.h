#ifndef _STACKLL_
#define _STACKLL_


typedef struct snode{
    void *addr;
    struct snode *next;
} st_ele_t;

typedef struct {
    int size;
    st_ele_t *top;
} stack_t;

stack_t *s_new();

void s_free(stack_t *s);

bool s_isempty(const stack_t *s);

bool s_push(stack_t *s, void *addr);

void *s_pop(stack_t *s);

#endif