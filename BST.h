#ifndef BST_H
#define BST_H

#include "linkedlist.h"

struct BST
{
    int val,index;
    struct BST *right,*left;
};

typedef struct BST BST;

typedef struct
{
  BST* head[100];
  int front,end;
}Q;

typedef struct
{
    BST head[100];
    int top;
}St;

void bst_insert(BST **,int,int);

void bst_search(BST *, BST**, BST**,int );

int bst_delete(BST **root, int val);

int bst_height(BST *root);

BST* mirror(BST* root);

void BST_BFS(BST* root);
#endif
