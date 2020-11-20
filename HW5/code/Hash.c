#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Hash.h"
#define PRIME 7
#define SIZE 13

hash_t *h_new() {
    hash_t *hash = malloc(sizeof(hash_t));
    if (!hash)
        return NULL;
    
    hash->size = SIZE;
    hash->data = (int *) calloc(SIZE, sizeof(int));
    hash->nums = 0;
}


void f_hash(hash_t *h, int key) {
    int i = 0;
    int hash1 = key % h->size;
    int hash2 = PRIME - (key % PRIME);
    int idx;
        
    while(1) {
        idx = (hash1 + i * hash2) % h->size;
        if (!h->data[idx]) {
            h->data[idx] = key;
            break;
        }
        else 
            i++;             
    } 
    h->nums++;
    // printf("%d->%d\n", idx, key);
    // return;
}

// int main()
// {
//     hash_t *h = h_new();
//     int a[13] = {24, 10, 31, 56, 45, 85, 64, 8, 77, 37, 2, 98, 70};
//     // int hash[SIZE] = {};


//     for( int i = 0; i < 13; i++) {
//         f_hash(h, a[i]);
//     }
//     printf("%d", h->nums);


//     return 0;
// }
