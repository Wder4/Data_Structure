#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack_LL.h"
#include "Que_LL.h"

typedef struct node {
    int edge;
    int strt;
    int end;
    int wt;
    struct node *next;
} act_ele_t;

typedef struct {
     int cnt; 
     int vtx;
     act_ele_t *head;
} graph;

act_ele_t *act_new(int edge, int strt, int end, int wt) {
    act_ele_t *act = (act_ele_t *) malloc(sizeof(act_ele_t));
    if(act == NULL)
        return NULL;
    act->edge = edge;
    act->strt = strt;
    act->end  = end;
    act->wt   = wt;
    act->next = NULL;
};

int get_vnum(int *arr, int col) {
    int tmp = arr[0];
    for(int i = 1; i < col; i++)
        if(tmp < arr[i])
            tmp = arr[i];
    return tmp;
}

void gp_init(graph *gp, int num) {
    for(int i = 0; i < num; ++i) {
        gp[i].head = NULL;
        gp[i].cnt  = 0;
        gp[i].vtx  = i;
    }
}



int main()
{   
    int **arr;
    int iput;
    char token;

    int col;
    int ocnt = 0, icnt = 0;

    while(scanf("%d%c", &iput, &token) != EOF) {
        if(ocnt == 0) {
            col = iput;
            arr = (int **)malloc(3 * sizeof(void *));
            for (int i = 0; i < 3; i++)  // row
               arr[i]=(int *) calloc(iput, sizeof(int *));  // col
        }
        else { 
            if(icnt != 0)
                arr[icnt - 1][ocnt - 1] = iput;
        }
        icnt++;
        if(token == '\n') {
            icnt = 0;
            ocnt++;
        }
    }
  

    /* ----- CREATE AOE ----- */
    int vnum = arr[1][col - 1] + 1;
    graph aoe[vnum];
    gp_init(aoe, vnum);
    for(int i = 0; i < col; ++i) {
        int strt = arr[0][i];
        int end  = arr[1][i];
        int wt   = arr[2][i];
        act_ele_t *act = act_new(i, strt, end, wt);
        aoe[end].cnt++;
        if(aoe[strt].head == NULL) 
            aoe[strt].head = act;
        else {
            act_ele_t *curr = NULL;
            curr = aoe[strt].head;
            while(1) {
                if(curr->next == NULL)
                    break;
                curr = curr->next;
            }
            curr->next = act;
        }
    }

    /* ----- PRINT AOE ----- */
    for(int i = 0; i < vnum; i++) {
        act_ele_t *curr = aoe[i].head;
        while(curr != NULL) 
            curr = curr->next;
    }

    
    stack_t *st =s_new();
    que_t *qu = q_new();
    int *ev = calloc(vnum, sizeof(int)); 
    int *lv = calloc(vnum, sizeof(int));


    for(int i = 0; i < vnum; ++i)
        if(aoe[i].cnt == 0)
            q_enq(qu, i);
  
    /* ---------- TOPSORT ---------- */
    /* ----- EARLY ----- */
    while(!q_isempty(qu)) {
        int vtx = q_deq(qu);
        s_push(st, vtx);
        act_ele_t *curr = aoe[vtx].head;
        while(curr != NULL) {
            int next_vtx = curr->end;
            aoe[next_vtx].cnt--;
            if((ev[vtx] + curr->wt) > ev[next_vtx])
                ev[next_vtx] = ev[vtx] + curr->wt;
            if(aoe[next_vtx].cnt == 0)
                q_enq(qu, next_vtx);
            curr = curr->next;
        }
    }

    /* ----- LATE ----- */
    for(int i = 0; i < vnum; ++i)
        lv[i] = ev[vnum - 1];
    while(!s_isempty(st)) {
        int vtx = s_pop(st);
        act_ele_t *curr = aoe[vtx].head;
        while(curr != NULL) {
            int next_vtx = curr->end;
            if((lv[next_vtx] - curr->wt) < lv[vtx])
                lv[vtx] = lv[next_vtx] - curr->wt;
            curr = curr->next;
        }
    }


    int ee, le;
    int cnt = 0, idx = 0;
    int *ary_ee = calloc(col, sizeof(int));
    int *ary_le = calloc(col, sizeof(int));
    for(int i = 0; i < vnum; ++i) {
        act_ele_t *curr = aoe[i].head;
        idx = cnt;
        while(curr != NULL) {
            int vtx = curr->end;
            ee = ev[i];
            le = lv[vtx] - curr->wt;
            printf("%d %d %d\n", cnt, ee, le);
            curr = curr->next;      
            ary_ee[cnt] = ee;
            ary_le[cnt] = le;
            cnt++;

        }  
        
    }
    

    int space = 1;
    que_t *q_pt = q_new();
    for(int i = 0; i < col; ++i) 
        if(ary_ee[i] == ary_le[i])
            q_enq(q_pt, i);
    

    int n = q_pt->size;
    for(int i = 0; i < n; ++i) {
        printf("%d", q_deq(q_pt));
        if(space < n) {
            printf(" ");
            space++;
        }
    }


    return 0;
}














