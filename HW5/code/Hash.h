#ifndef _HASH_
#define _HASH_

typedef struct {
    int size;
    int *data;
    int nums;
} hash_t;

hash_t *h_new();

void f_hash(hash_t *h, int key);

#endif
