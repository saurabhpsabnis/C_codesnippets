#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "linkedlist.h"

void bst_insert(BST **root,int val,int index)
{

    if(*root == NULL)
    {
        BST* node = (BST *)malloc(sizeof(BST));

        node->val=val;
        node->index = index;
        node->right=NULL;
        node->left=NULL;

       *root = node;
    }
    else if((*root)->val > val)
    {
        bst_insert(&((*root)->left),val,index);
    }
    else
    {
        bst_insert(&((*root)->right),val,index);
    }
}

void bst_search(BST *root, BST** item, BST** parent,int val)
{
     BST* temp = root, *parent_temp=NULL;
     while(temp != NULL)
     {
         if(temp->val == val)
         {
             *parent = parent_temp;
             *item = temp;
             return;
         }
         parent_temp = temp;
         if(val < temp->val)
         {
             temp = temp->left;
         }
         else
         {
             temp = temp->right;
         }
     }
     *item = NULL;
     *parent = NULL;
}

int bst_delete(BST **root, int val)
{
    BST *temp,*node,*parent_node,*parent_temp;

    bst_search(*root,&node,&parent_node,val);

    if(node == NULL)
    {
        return -1;
    }
    else
    {
        if((node->left == NULL) && (node->right == NULL))
        {
            if(node->val < parent_node->val)
                parent_node->left = NULL;
            else
                parent_node->right = NULL;
        }
        else if(node->left == NULL)
        {
            if(node->val < parent_node->val)
                parent_node->left = node->right;
            else
                parent_node->right = node->right;
        }
        else if(node->right == NULL)
        {
             if(node->val < parent_node->val)
                parent_node->left = node->left;
            else
                parent_node->right = node->left;
        }
        else
        {
            temp = node->right;
            parent_temp = NULL;
            while(temp->left != NULL)
            {
                parent_temp = temp;
                temp = temp->left;
            }
            if(parent_temp == NULL)
            {
                temp->left = node->left;
            }
            else
            {
                parent_temp->left = temp->right;
                temp->right = node->right;
                temp->left = node-> left;
            }

            if(node->val < parent_node->val)
                parent_node->left = temp;
            else
                parent_node->right = temp;
        }
        free(node);
    }
    return 0;

}


int bst_height(BST *root)
{
    if(root == NULL)
        return 0;

    int hleft,hright;

    hleft = bst_height(root->left);
    hright = bst_height(root->right);

    if(hleft > hright)
        return (hleft + 1);
    else
        return (hright + 1);

}

void init_q(Q* q)
{
    q->front=0;
    q->end=0;
}

void insert_q(Q* q,BST* node)
{
    q->head[q->end] = node;
    q->end++;
}

BST* delete_q(Q* q)
{
    if(q->front == q->end)
        return NULL;
    BST* temp = q->head[q->front];
    q->front++;
    return temp;
}

BST* mirror(BST* root)
{
    if(root== NULL)
        return NULL;

    BST* newnode = (BST*)malloc(sizeof(BST));
    newnode->val = root->val;newnode->index = root->index;
    newnode->left = mirror(root->right);
    newnode->right = mirror(root->left);

    return newnode;
}

void BST_BFS(BST* root)
{
    Q q;
    BST *temp;
    init_q(&q);
    insert_q(&q,root);
    do
    {
        temp = delete_q(&q);
        if(temp == NULL)
            break;
        printf("(%d %d)", temp->index,temp->val);
        if(temp->left)
            insert_q(&q,temp->left);
        if(temp->right)
            insert_q(&q,temp->right);
    }while(1);
}


