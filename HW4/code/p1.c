#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Que_LL.h"
#include "BST.h"


int main(int argc, char **argv) 
{
    char token;
    int mode = 0;
    int num = 0;
    tree_t *t = tree_new();

    while (scanf("%d%c", &num, &token) != EOF) {
        switch(mode) {
            case 0:
                tree_ins(t, num);
                break;
            case 1:
                tree_del(t, num);
                break;
            default:
                break;      
        } 

        if (mode == 0 && token == '\n')
            mode = 1;
        else if (mode == 1 && token == '\n')
            mode = 0;

    }

    que_t *q = q_new();
    int h = tree_h(t->root);
    tree_traversal(t, q, 0, h);

    q_ele_t *tmp = q->head;
    for (int i = 0; i < q->size; i++) {
        printf("%d", tmp->data);
        tmp = tmp->next;
        if (i + 1 < q->size)
            puts("");
    }
    free(tmp);
    

    return 0;
}