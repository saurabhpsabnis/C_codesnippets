#include <stdio.h>
#include <string.h>
#include "sorting.h"
#include "BST.h"
#include "linkedlist.h"
#include "sample.h"
#include "searching.h"
#include "graph.h"


#define codecollab(a)   a##00
#define code(x)     codecollab(x)
#define stringify(x)     #x
#define stringy(x)  stringify(x)

void printarr(char* s,int *arr,int len)
{
	int i;
	printf("\n%s :",s);
	for(i=0; i<len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void copy(int *arr,int *temp,int len)
{
	memcpy(temp,arr,len*sizeof(int));
}


void printtree(BST *root)
{
    if(root == NULL)
    {
        printf("root is NULL");
        return;
    }
    else
    {
   printf ( " \n node : %d ", root->val);
        if(root->left != NULL)
        {
            printf("   left : %d", root->left->val);
        }
        if(root->right != NULL)
        {
            printf("   right : %d", root->right->val);
        }
        if(root->left != NULL)
        {
            printtree(root->left);
        }
        if(root->right != NULL)
        {
            printtree(root->right);
        }
    }
}
void sortalgos(void)
{

	int arr[50]={5,86,69,73,11,17,1,74,34,3},temp[50];
	int i=10;

	copy(arr, temp,i);
	printarr("unsorted array",arr,i);
	printarr("temp array",temp,i);

	bubblesort(temp,i);

	printarr("\t\tbubble sort\t" , temp, i);

	copy(arr, temp,i);
	printarr("temp array", temp, i);

	insertionsort(temp,i);
	printarr("\t\tinsertion sort\t", temp, i);

	copy(arr, temp,i);
	printarr("temp array", temp, i);

	selectionsort(temp,i);
	printarr("\t\tSelection sort\t", temp, i);

	copy(arr, temp,i);
	printarr("temp array", temp, i);

	meargesort(temp,0,i-1);
	printarr("\t\tMearge Sort\t", temp, i);
	copy(arr, temp,i);
	printarr("temp array", temp, i);

    quicksort(temp,0,i-1);
	printarr("\t\tQuick Sort\t", temp, i);
	copy(arr, temp,i);
	printarr("temp array", temp, i);

	heapsort(temp,i);
	printarr("\t\tHeap Sort\t", temp, i);
	copy(arr, temp,i);
	printarr("temp array", temp, i);
}

void BSToperations(void)
{
    int arr[50]={55,86,69,94,73,11,0,17,1,5,74,42,34,3,99,65,61,63,62,90,92};
    int len=21,i;
    BST *root=NULL,*find_item, *parent_find_item,*mirror_tree;

    for(i=0;i<len;i++)
    {
        bst_insert(&root,arr[i],i);
    }

    printtree(root);

    bst_search(root,&find_item,&parent_find_item,3);

    if(find_item == NULL)
    {
        printf("\n\n\t *** Item not find ***");
    }
    else
    {
        printf("\n\n\t *** Item found %d (index: %d) Parent: %d(index %d) ***",
               find_item->val,find_item->index,parent_find_item->val,parent_find_item->index);
    }

    printf("\n\n\t *** Mirror image of the tree ***");

    mirror_tree = mirror(root);

    printtree(mirror_tree);

        printf("\n\n\t *** Breadth First Search ***\n\n***");

    BST_BFS(root);

    printf("\n\n\t *** Height of the Tree %d ***", bst_height(root));

   bst_delete(&root,17);

    printf("\n\n\t *** Tree after deletion ***");

    printtree(root);



}

void linkedlistops(void)
{
    int arr[50]={55,86,69,94,73,11,0,17,1,5,74,42,34,3,99,65,61,63,62,90,92};
    int i,len=21;
    ht hash_table[8] = {{0}};
    ll *l = NULL;

    for(i=0;i<len;i++)
    {
        insert_ht(hash_table,arr[i],i);
    }

    display_ht(hash_table,8);

    for(i=0;i<len;i++)
    {
        l = sorted_ll(l,arr[i],i);
    }

      printf("\n\nSorted Linked List \n");
    display_ll(l);

 //   l = sorted_ll(l,34,56);

    i = 5;
    if(return_index(l,5) != -1)
    {

        printf("\n\n index for %d is %d", i,return_index(l,5));
    }
    printf("\n\nLinked List after deletion %d\n",arr[6]);
    l=delete_node(l,6);
    display_ll(l);
    len = find_ll_len(l);
    printf("\n\nLength of the linke list %d\n",len);
}

void singlyllops(void)
{
    int arr[50]={55,86,69,94,73,11,0,17,1,5,74,42,34,3,99,65,61,63,62,90,92};
    int i,len=21;

    sll* head = NULL;

    for(i=0;i<len;i++)
    {
        head = create_sorted_sl(head,arr[i],i);
    }

    display_sll(head);

    head = reverse_sll(head);

    printf("\n\n\n");

    display_sll(head);

}

struct trie_node* master;

void sample_ops(void)
{

        int max_subarr[7] = {67,-34,41,-165,56,-11,-2};
        int arr[50]={55,86,69,94,73,11,0,17,1,5,74,42,34,3,99,65,61,63,62,90,92,28};
        unsigned int len =7,num_str=4,i;
        sub_array max_seq;
        char *str[15] = {"acpt","pcat","tacp","aptc","dil"};
        char str_per[10] = "abcd";
        char  word_str[50] = "Saurabh Pradeeprao Sabnis Vrushali Date";
        trie_data data[6] = {{"saurabh",12},{"vrushali",34},{"saurdhr",56},{"vrdfg",88},{"freaser",444},{"freestyle", 898}};

        char prefix[100] = "saur",blanck[100];

        char cur_dir[200] = "a/b/c/dsas/d",string[100] = "./x/../y/../cd/abc";

        int coin_arr[10] = {1,5,4,7},val = 12;
        //Palindrome
        printf(" \n\n Ourput of pallidrome %d", detect_palindrome("SaurruaS"));

        //maximum sub sequence problem
        maximum_subsequence(&max_seq, max_subarr,len);

        printf(" \n\n Max subseq %d ( %d, %d)",max_seq.val,max_seq.i,max_seq.j);

        //reverse a number
        printf(" \n\n Reverse of the number %u", rev_int(561234));

        //Anagrams of n strings
        printf("\n\n anagram : %d",anagrams(str,4));

        //reverse words in the string
        reverse_word_string(word_str);
        printf("\n\n Reverse word string : %s", word_str);

        //permute string
       // permute_str(str_per,0,4);

        construct_trie();
        print_trei(master);
        for(i=0;i<6;i++)
        {
            add_trie_word(&(data[i]));
          printf("\n\n ============== Prefix tree =================");
            print_trei(master);
        }
        printf("\n\n \t node val for %s is %d","freaser",get_node_val("freaser"));

        printf("\n\n \t whole trie");
        get_strings(blanck,master);
        printf("\n\n \n with prefix");
        get_strings_with_prefix(prefix);

//       printf("\n\n\t number of pairs = %d",search_distinct_pairs(arr,22,28));

        printf("\n\n \t String combination \n ");
       // all_combinations_str(prefix,3);

        printf("final directory : %s",final_dir(cur_dir,string ));


        min_coin(coin_arr,val,4);

        printf("\n Min coin problem coount %d",total_was_of_coins(coin_arr,val,4));
}

void searchops(void)
{
    int arr[50]={5,86,69,73,11,17,1,74,34,3},temp[50];
	int i=10;

	copy(arr, temp,i);
	printarr("unsorted array",arr,i);
	printarr("temp array",temp,i);

    quicksort(temp,0,i-1);
	printarr("\t\tQuick Sort\t", temp, i);

    printf("search result %d",binary_search(-1,temp,0,i-1));

}

void graphops(void)
{
        int arr[11] = {67,-34,41,-165,56,-11,-2,0,21,-67,99};
        unsigned int len = 11;
        graph g;

        create_graph(&g,len,arr);

        add_edge(&g,0,6);
        add_edge(&g,3,0);
        add_edge(&g,7,2);
        add_edge(&g,7,1);
        add_edge(&g,2,4);
        add_edge(&g,5,6);
        add_edge(&g,5,1);
        add_edge(&g,1,4);
        add_edge(&g,2,5);
        add_edge(&g,6,3);
        add_edge(&g,4,4);
        add_edge(&g,1,7);
        add_edge(&g,4,3);
        add_edge(&g,3,5);
        add_edge(&g,6,5);
        add_edge(&g,4,1);
        add_edge(&g,1,3);
        add_edge(&g,4,7);
        add_edge(&g,1,3);

        add_edge(&g,8,10);
        add_edge(&g,8,9);
        add_edge(&g,10,9);
        add_edge(&g,10,8);


        print_graph(&g);

        printf("\n\n\t DFS \n\n\t ");

        DFS(&g);

        printf("\n\n\t BFS");

        BFS(&g);

}

int main()
{
   // sortalgos();

   //BSToperations();

   //linkedlistops();

   //singlyllops();

   sample_ops();

   // searchops();

   // graphops();
    return 0;
}
