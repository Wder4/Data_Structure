#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVL.h"

int main()
{
    char *str = malloc(sizeof(char) * 30);
    char name[20];
    char phone[11];
    char token;
    int mode;
    int space = 0;
    avl_t *avl = avl_new();

    while(gets(str)){
        if(!strcmp(str, "D"))
            mode = 0;
        else if(!strcmp(str, "S"))
            mode = 1;
        else if(!strcmp(str, "E"))
            break;
        else {
            switch(mode) {
                case 0:
                    sscanf(str, "%s %s", name, phone);
                    avl_ins(avl, name, phone);
                    break;
                case 1: 
                    avl_traversal(avl, 2);
                    puts("");
                    mode = 2;
                case 2:
                    if(space)
                        puts("");
                    avl_sch(avl, str);
                    space++;
                    
                default:
                    break;
            }
        }
    }
    fflush(stdin);

    return 0;
}