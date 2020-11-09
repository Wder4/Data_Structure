#ifndef _BST_
#define _BST_

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} tree_ele_t;

typedef struct {
    int size;
    struct node *root;
} tree_t;

tree_t *tree_new();

void tree_free (tree_t *t);

bool tree_isempty(const tree_t *t);

int tree_h(tree_ele_t *curr);

void tree_traversal(tree_t *t, que_t *q, int ch, int h);

bool tree_sch(const tree_t *t, int key);

bool tree_ins(tree_t *t, int key);

bool tree_del(tree_t *t, int key);


#endif