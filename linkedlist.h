#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct ll
{
   int val, index;
   struct ll *prev,*next;
};

typedef struct ll ll;
struct ht
{
    ll* head;
};

struct sll
{
    int val, index;
    struct sll *next;
};

typedef struct sll sll;
typedef struct ht ht;

void display_ht(ht *,int);
void insert_ht(ht *,int val,int index);
ll* sorted_ll(ll *head,int val,int index);
void display_ll(ll *head);
int find_ll_len(ll *head);
int return_index(ll *head, int val);
ll* delete_node(ll *head,int index);


void print_rev(ll* head);

sll* create_sorted_sl(sll* head,int val, int index);
sll* reverse_sll(sll* head);
void display_sll(sll *head);


#endif // LINKEDLIST_H_INCLUDED
