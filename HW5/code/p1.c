#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main(int argc, char **argv) 
{
    int iput;
    char token;
    hash_t *h = h_new();
    while(scanf("%d%c", &iput, &token) != EOF) {
        // printf("%d, %c,", iput, token);
        f_hash(h, iput);
    }
    for(int i = 0; i < h->nums; i++) {
        printf("%d->%d", i, h->data[i]);
        if(i + 1 < h->nums)
            puts("");
    }
    
    return 0;    
}