#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Que_LL.h"
#include "BST.h"

tree_t *tree_new() {
    tree_t  *tree = malloc(sizeof(tree_t));
    if (!tree)
        return NULL;
    tree->root = NULL;
    tree->size = 0; 
}

void tree_ele_free(tree_ele_t *root) {
    if (root != NULL) {
        tree_ele_free(root->left);
        tree_ele_free(root->right);
        free(root);
    }
}

void tree_free(tree_t *t) {
    tree_ele_free(t->root);
    free(t);
}

bool tree_isempty(const tree_t *t) {
    return (t->root == NULL) ? true : false;
}

int tree_h(tree_ele_t *curr) {
    int max = 0;
    if (curr != NULL) {
        int leftsubtree = tree_h(curr->left);
        int rightsubtree = tree_h(curr->right);
        if (leftsubtree > rightsubtree) {
            max = leftsubtree + 1;
            return max;
        }
        else {
            max = rightsubtree + 1;
            return max;
        }
    }
}

void currlevel(const tree_ele_t *curr, que_t *q, int h) {
    if(curr) {
        if (h == 1)
            q_enq(q, curr->data);
        else if (h > 1) {
            currlevel(curr->left, q, h - 1);
            currlevel(curr->right, q, h - 1);
        }
    }
}

void tree_level(const tree_ele_t *curr, que_t *q, int h) {
    for (int i = 1; i <= h; i++) {
        currlevel(curr, q, i);
    } 
}

void tree_inorder(const tree_ele_t *curr) {
    if (curr) {
        tree_inorder(curr->left);
        printf("%d ", curr->data);
        tree_inorder(curr->right);
    }
}

void tree_preorder(const tree_ele_t *curr, que_t *q) {
    if (curr) {
        if (curr->data) {

            q_enq(q, curr->data);
        }
        tree_preorder(curr->left, q);
        tree_preorder(curr->right, q);
    }

}

void tree_postorder(const tree_ele_t *curr) {
    if (curr) {
        tree_postorder(curr->left);
        tree_postorder(curr->right);
        printf("%d ", curr->data);
    }

}

void tree_traversal(tree_t *t, que_t *q, int ch, int h) {
    switch(ch) {
        case 0:
            tree_level(t->root, q, h);
            break;
        case 1:
            tree_inorder(t->root);
            break;
        case 2:
            tree_preorder(t->root, q);
            break;
        case 3:
            tree_postorder(t->root);
            break;
        default:
            // error(stderr);
            // again(stderr);
            break;
    }
}

bool tree_sch(const tree_t *t, int key) {
    if (tree_isempty(t))
        return false;
    tree_ele_t *curr = t->root;
    if (key == curr->data)
        return true;
    while (curr != NULL && curr->data != key) {
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;        
    }
    if (curr == NULL)
        return false;
    return true;
}

bool tree_ins(tree_t *t, int key) {
    tree_ele_t *node = (tree_ele_t*) malloc(sizeof(tree_ele_t));
    node->data = key;
    if (node == NULL) {
        free(node);
        return false;
    }
    node->left = NULL;
    node->right = NULL;
    if (tree_isempty(t)) {
        t->root = node;
        t->size++;
        return true;
    }

    tree_ele_t *curr = t->root;
    tree_ele_t *prev = NULL;
    int chklr = 0;
    while (curr != NULL) {
        prev = curr;
        if (key < curr->data) {
            chklr = 0;
            curr = curr->left;
        }
        else {
            chklr = 1;
            curr = curr->right;
        }          
    }
    if (!chklr)
        prev->left = node;
    else
        prev->right = node; 
    
    t->size++;
    return true;
}

tree_ele_t *tree_ele_del(tree_ele_t *root, int key) {
    if (!root)
        return NULL;   
    if (root->data > key) 
        root->left = tree_ele_del(root->left, key);
    else if (root->data < key)
        root->right = tree_ele_del(root->right, key);
    else {
        if (!root->left || !root->right)
            root = (root->right) ? root->right : root->left;
        else {
            tree_ele_t *curr = root->right;
            while (curr->left)
                curr = curr->left;
            root->data = curr->data;
            root->right = tree_ele_del(root->right, curr->data);
        }
    }
    return root;
}

bool tree_del(tree_t *t, int key) {
    tree_ele_t *tmp = tree_ele_del(t->root, key);
    if (tmp) { 
        t->size--;
        return true;
    }
    else
        return false;
    free(tmp);
}

/*
int main()
{
    tree_t *t = tree_new();
    que_t *q = q_new();
    int a[6] = {1, 3, 7, 5, 2, 4};
    for (int i = 0; i < sizeof(a) / sizeof(int); ++i) 
        tree_ins(t, a[i]);

    printf("%d", tree_h(t->root));
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
    tree_free(t);

    return 0;
}
*/