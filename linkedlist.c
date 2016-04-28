#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void display_ht(ht *hash,int len)
{
    int i;
    ll* head;
    for(i=0;i<len;i++)
    {
        printf("\n %d:\t", i);
        head = hash[i].head;
        while(head != NULL)
        {
            printf("(%d  %d)",head->val,head->index);
            head = head->next;
        }
    }
}

void display_ll(ll *head)
{

        while(head != NULL)
        {
            printf("(%d  %d)->",head->val,head->index);
            head = head->next;
        }
}

void display_sll(sll *head)
{

        while(head != NULL)
        {
            printf("(%d  %d)->",head->val,head->index);
            head = head->next;
        }
}

void insert_ht(ht *hash,int val,int index)
{

    int key = val%8;
    ll* head,*node,*head_prev=NULL;
    node = (ll *)malloc(sizeof(ll));
    node->next=NULL;
    node->prev=NULL;
    node->val = val;
    node->index = index;
    head = hash[key].head;
    if(head == NULL)
        hash[key].head = node;
    else
    {
        while(head!=NULL)
        {
            head_prev=head;
            head=head->next;
        }
        head_prev->next = node;
        node->prev = head_prev;
    }
}


ll* sorted_ll(ll *head,int val,int index)
{
    ll* node = (ll*)malloc(sizeof(ll)),*t1,*t2;
    node ->val =val; node->index  = index;node -> prev = NULL; node->next = NULL;
    if(head == NULL)
    {
        head = node;
        return head;
    }
    t1 = head;
    t2 = NULL;
    while(t1 != NULL)
    {
        if(t1->val > val)
        {
            if(t2 != NULL)
            {
                t2->next = node;
                node->prev = t2;
                node->next = t1;
                t1->prev = node;
            }
            else
            {
                node->prev = NULL;
                node->next = t1;
                t1->prev = node;
                head = node;
            }
            return head;
        }
        t2 = t1;
        t1=t1->next;
    }
    t2->next = node; node->prev = t2; node->next = NULL;
    return head;
}

int find_ll_len(ll *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int return_index(ll *head, int val)
{
    while(head != NULL)
    {
        if(head->val ==  val)
        {
            return head->index;
        }
        head = head -> next;
    }
    return -1;
}

ll* delete_node(ll *head,int i)
{
    ll *t1,*t2;
    if(head->index == i)
    {
        t1 = head;
        head = head->next;
        head->prev = NULL;
        t1->next = NULL; t1->prev=NULL;
        free(t1);
        return head;
    }
    else
    {
        t1 = &(head->next);
        t2 = &(*head);
        while(t1 != NULL)
        {
            if(t1->index == i)
            {
                   (t2)->next =  (t1)->next;
                   (t1)->next->prev = (t2);
                   (t1)->next = NULL; (t1)->prev=NULL;
                   free(t1);
            }
            t2 = t1;
            t1 = (t1)->next;
        }
    }
}


sll* create_sorted_sl(sll* head,int val, int index)
{
    sll* node = (sll*)malloc(sizeof(sll));
    sll* t1,*t2;
    node->val = val;node->index=index;node->next=NULL;
    if(head == NULL)
    {
        head = node;
        return head;
    }
    if(val < head->val)
    {
        node->next= head;
        head = node;
        return head;
    }
    t1 = head;
    t2 = head ->next;
    while(t2 != NULL)
    {
        if(val < t2->val)
        {
            t1->next = node;
            node->next = t2;
            return head;
        }
        t1 = t2;
        t2 = t2->next;
    }
    t1->next = node;
    return head;
}


sll* reverse_sll(sll* head)
{
    sll* t1,*t2,*t3;

    if(head == NULL)
        return head;

    t1 = head;
    t2 = head->next;
    t1->next = NULL;
    while(t2 != NULL)
    {
        t3 = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t3;
    }
    return t1;
}
