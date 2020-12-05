#ifndef _AVL_
#define _AVL_

typedef struct node {
    char *str;
    char *data;
    struct node *par; // parent
    struct node *left;
    struct node *right;
} avl_ele_t;

typedef struct {
    int size;
    struct node *root;
} avl_t;

avl_t *avl_new();

void avl_free(avl_t *avl);

int avl_h(avl_ele_t *curr);

void avl_traversal(avl_t *avl, int ch);
// 0: level, 1: inorder, 2: preorder, 3: postorder
avl_ele_t *avl_nnode(char *s, char *key);

void avl_ins(avl_t *avl, char *s, char *key);

void avl_sch(avl_t *avl, char *s);


#endif