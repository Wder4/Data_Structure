#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Que_LL.h"

void showCards(que_t *q) {
    q_ele_t *tmp;
    tmp = q->head;
    for (int i = 0; i < q->size - 1; ++i) {
        printf("%s ", tmp->data);
        tmp = tmp->next;
    }
    printf("%s", tmp->data);
}

int card2num(char *s) {
    int dec;
    char c = s[0];
    if (c == 'A')
        dec = 1;
    else if (c == 'J' || c == 'j')
        dec = 11;
    else if (c == 'Q' || c == 'q')
        dec = 12;
    else if (c == 'K' || c == 'k')
        dec = 13;
    else if (c == '1')
        dec = 10;
    else
        dec = c - '0';

    return dec;
}

int main(int argc, char **argv) {
    char *iput;
    char *val;
    que_t *q = q_new();

    while (fscanf(stdin, "%s", &iput) != EOF) {  
        q_enq(q, iput);
        free(iput);
    }  
    

    int i = 13;
    int dec;

    while (i > 1){
        showCards(q);
        puts("");
        val = q_deq(q);
        dec = card2num(val);
        if (dec == i)        
            i--;
        else
            q_enq(q, val);
    }
    showCards(q);
    return 0;
}