#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sstring.h"
#include "Stack_LL.h"
#include "Que_LL.h"
#define SIZE 20



int get_val(char *str) {
    int base = 1;
    int sum = 0;
    int len = strlen(str);
    for (int i = len - 1; i >= 0; --i) {
        int num = str[i] - '0';
        if (num >= 0 && num <= 9) {   // for stack
            sum += num * base;
            base *= 10;
        }
        else  // for queue
            return str[i];
    }
    return sum;
}

int main(int argc, char **argv) {

    char str[SIZE]; 
    char val[SIZE];

    // create stack, queue
    stack_t *st = s_new();
    que_t *q = q_new();
    que_t *plq = q_new();
    int cnter = 0;

    while (fscanf(stdin, "%s%[^\n]%*c", &str, &val) != EOF) {
        
        if (strstr(str, "^Z"))
           break;

        stupr(str, strlen(str));

        ltrim(val);
        if (strstr(str, "PUSH"))
            s_push(st, val);

        else if (strstr(str, "POP")) {
            q_enq(plq, s_pop(st));
            cnter++;
        }

        else if (strstr(str, "ENQ"))
            q_enq(q, val);

        else if (strstr(str, "DEQ")){
            char *customer =  q_deq(q);
            char *plate = q_deq(plq);
            rtrim(plate);
            printf("%s", plate);
            cnter--;
            if (cnter > 0)
                puts("");
        }         
    }

    return 0;
}