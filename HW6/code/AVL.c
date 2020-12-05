#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "AVL.h"
#include "Stack_LL.h"
#include "Que_LL.h"

avl_t *avl_new() {
    avl_t *avl = malloc(sizeof(avl_t));
    if(!avl)
        return NULL;
    avl->size = 0;
    avl->root = NULL;
}

void avl_ele_free(avl_ele_t *root) {
    avl_ele_free(root->left);
    avl_ele_free(root->right);
    free(root->str);
    free(root->data);
    free(root);

}

void avl_free(avl_t *avl) {
    avl_ele_free(avl->root);
    free(avl);
}

int avl_h(avl_ele_t *curr) {
    if(curr != NULL) {
        int ltree = avl_h(curr->left);
        int rtree = avl_h(curr->right);
        if(ltree > rtree)
            return ltree + 1;
        else 
            return rtree + 1;
    }
}

/********** traversal **********/
void avl_level(avl_ele_t *curr) {    
    if(curr == NULL)
        return;
    avl_ele_t *tmp = NULL;
    que_t *q = q_new();
    q_enq(q, curr);
    while(!q_isempty(q)) {
        tmp = q_deq(q);
        printf("%s", tmp->str);
        if(tmp->left)
            q_enq(q, tmp->left);
        if(tmp->right)
            q_enq(q, tmp->right);
    }
    q_free(q);
}
void avl_inorder(const avl_ele_t *curr) {
    if (curr) {
        avl_inorder(curr->left);
        printf("%s ", curr->str);
        avl_inorder(curr->right);
    }
}
void avl_preorder(avl_ele_t *curr, que_t *q) {
    if (curr) {
        q_enq(q, curr);
        avl_preorder(curr->left, q);
        avl_preorder(curr->right, q);
    }
}
void avl_postorder(const avl_ele_t *curr) {
    if (curr) {
        avl_postorder(curr->left);
        avl_postorder(curr->right);
        printf("%s ", curr->str);
    }
}

void avl_traversal(avl_t *avl, int ch) {
    que_t *q = q_new();
    avl_ele_t *tmp = NULL;
    int size;
    switch(ch) {
        case 0:
            avl_level(avl->root);
            break;
        case 1:
            avl_inorder(avl->root);
            break;
        case 2:
            avl_preorder(avl->root, q);
            size = q->size;
            for(int i = 0; i < size; ++i) {
                if(i>0)
                    printf(" ");
                tmp = q_deq(q);
                printf("%s", tmp->str);    
            }
            q_free(q);
            break;
        case 3:
            avl_postorder(avl->root);
            break;
        default:
            // error(stderr);
            // again(stderr);
            break;
    }
}

avl_ele_t *avl_nnode(char *s, char *key) {
    avl_ele_t *node = (avl_ele_t*) malloc(sizeof(avl_ele_t));
    int dlen = strlen(key) + 1;
    char *data = (char*) malloc(sizeof(int) * dlen);
    int slen = strlen(s) + 1;
    char *str = (char*) malloc(sizeof(char) * slen);
    if(!node || !data || !str) {
        free(node);
        free(data);
        free(str);
        return NULL;
    }

    strncpy(data, key, dlen);
    strncpy(str, s, slen);

    node->data  = data;
    node->str   = str;
    node->par   = NULL;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

int cf_str(char *s1, char *s2) {   
    // -1: s1 < s2
    //  0: s1 = s2
    //  1: s1 > s2
    int s1len = strlen(s1);
    int s2len = strlen(s2);
    int times = s1len < s2len ?  s1len : s2len;
    int i = 0;
    int res;
    while(i < times) {
        if(*(s1 + i) < *(s2 + i))
            return -1;

        else if(*(s1 + i) > *(s2 + i))
            return 1;
  
        else 
            i++;
    }

    if(s1len == s2len) 
        res = 0;
    else
        res = s1len > s2len ? 1 : 0;   
    return res;
}

/********** rotation **********/
avl_ele_t *ll(avl_ele_t *node) {
    avl_ele_t *curr = node->left;
    node->left  = curr->right;
    curr->right = node;
    return curr;
}
avl_ele_t *rr(avl_ele_t *node) {
    avl_ele_t *curr = node->right;
    node->right = curr->left;
    curr->left  = node;
    // node->h = avl_h(node);
    // curr->h = avl_h(curr);
    return curr;
}
avl_ele_t *lr(avl_ele_t *node) {
    node->left = rr(node->left);
    node = ll(node);
    return node;
}
avl_ele_t *rl(avl_ele_t *node) {
    node->right = ll(node->right);
    node = rr(node);
    return node;
}

int avl_ele_balance(avl_ele_t *curr) {
    if(curr == NULL)
        return 0;
    int ltree, rtree;
    curr->left == NULL ? ltree = 0 : (ltree = avl_h(curr->left));
    curr->right == NULL ? rtree = 0 : (rtree = avl_h(curr->right));
    return (ltree - rtree);
}

avl_ele_t *rebalance(avl_ele_t *curr, int bal_factor) {
    if(bal_factor > 1) {
        if(avl_ele_balance(curr->left) >= 0)
            curr = ll(curr);
        else 
            curr = lr(curr);
    }
    else if(bal_factor < -1) {
        if(avl_ele_balance(curr->right) <= 0)
            curr = rr(curr);
        else 
            curr = rl(curr);
    }
    return curr;
}

void avl_ins(avl_t *avl, char *s, char *key) {
    avl->size++;
    if(avl->root == NULL) {
        avl->root = avl_nnode(s, key);
        return;
    }
    avl_ele_t *prev = NULL;
    avl_ele_t *curr = NULL;
    curr = avl->root;
    int res;
    stack_t *st = s_new();  

    while(1) {
        if(curr == NULL) {
            curr = avl_nnode(s, key);
            curr->par = prev;
            break;
        }
        prev = curr;   
        s_push(st, curr);
        res = cf_str(curr->str, s); 
        if(res > 0) {
            curr = curr->left;
        }
        else
            curr = curr->right;
    }
    if(res > 0) 
        prev->left = curr;
    else
        prev->right = curr;

    avl_ele_t *tmp  = NULL;

    int bal_factor;
    int num = st->size;
    for (int i = 0; i < num; i++){
        tmp = s_pop(st);
        bal_factor = avl_ele_balance(tmp);
        if(bal_factor == 2 || bal_factor == -2) {
            prev = tmp->par;
            tmp = rebalance(tmp, bal_factor);
            if(prev == NULL)
                avl->root = tmp;       
            else if(res)
                prev->left = tmp;
            else
                prev->right = tmp;
        }       
    }
    // s_free(st);   
}

void avl_sch(avl_t *avl, char *s) {
    if(avl->root == NULL)
        return;
    avl_ele_t *curr = avl->root;
    int same = cf_str(curr->str, s);
    if(same == 0) {
        printf("%s", curr->data);
        return;
    }
    while(1) {
        if(same == 0) {
            printf("%s %s", s, curr->data);
            return;
        }
        else if(same > 0) 
            curr = curr->left;
        else 
            curr = curr->right;
        if(curr == NULL)
            break;
        else 
            same = cf_str(curr->str, s);
    }
    if(same != 0)
        printf("%s null", s);
}

/*
int main() 
{
    avl_t *avl = avl_new();
    char *aa = "0912345678";
    char *ac = "0987654321";
    char *b = "B", *a = "A", *p = "P", *d = "D", *r = "R", *c = "C";

    avl_ins(avl, b, aa);
    avl_traversal(avl, 0); puts("");
    avl_ins(avl, a, aa);
    avl_traversal(avl, 0); puts("");
    avl_ins(avl, p, aa);
    // avl_traversal(avl, 0); puts("");
    avl_traversal(avl, 2); puts(""); 
    // avl_ins(avl, d, aa);
    // avl_traversal(avl, 0); puts(""); 
    // avl_ins(avl, r, aa);
    // avl_traversal(avl, 0); puts(""); 
    // avl_ins(avl, c, ac);
    // avl_traversal(avl, 0); puts(""); 

    // avl_traversal(avl, 2); puts(""); 
    // avl_inorder(avl->root); puts(""); 
    // avl_postorder(avl->root); puts("");    

    avl_sch(avl, "Ac");
    printf("%s", avl->root->data);
    return 0;
}
*/