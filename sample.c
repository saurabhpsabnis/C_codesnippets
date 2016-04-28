
#include "sample.h"
#include "sorting.h"
#include "searching.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>


extern struct trie_node* master;

int detect_palindrome(const char* xx)
{
    int i = 0, j = strlen(xx)-1;

    while(i<j)
    {
        if(xx[i]==xx[j])
        {
            i++;j--;
        }
        else
            return E_FAILLURE;
    }
    return E_SUCCESS;
}

void maximum_subsequence(sub_array* max_seq, int *xx, unsigned int len )
{
    sub_array cur_max, max_till_now, *result;
    unsigned int i = 0;
    result = (sub_array*)malloc(len);

    cur_max.val  = INT_MIN;
    max_till_now.val = INT_MIN;
    printf("\n\n INT_MIN %d",INT_MIN);
    for(i=0;i<len;i++)
    {
        if(cur_max.val < 0)
        {
            cur_max.val = xx[i];
            cur_max.i = i;
            cur_max.j =i;
        }
        else
        {
            cur_max.val += xx[i];
            cur_max.j = i;
        }
        if(max_till_now.val < cur_max.val)
        {
            max_till_now.val = cur_max.val;
            max_till_now.i=cur_max.i;
            max_till_now.j=cur_max.j;
        }
        result[i].val = max_till_now.val;
        result[i].i= max_till_now.i;
        result[i].j=max_till_now.j;
    }
    max_seq->val = result[len-1].val;
    max_seq->i=result[len-1].i;
    max_seq->j=result[len-1].j;
}


unsigned int rev_int(unsigned int num)
{
    unsigned int rev_num = 0, max_size =10,len =1;
    unsigned int temp = num;
    while(max_size < temp)
    {
        len++;
        max_size = max_size * 10;
    }
    printf("len = %d   %d", len, max_size );
    temp=num;
    max_size = max_size /10;
    while(temp != 0)
    {
        rev_num = rev_num + max_size*(temp % 10);
        temp = temp / 10;
        max_size = max_size / 10;
    }
    return rev_num;
}


int anagrams(char* arr_str[],int num_str)
{
    int arr[26] = {0},i,j;

    for(i = 0; i < num_str; i++)
    {
        j=0;
        while(arr_str[i][j] != '\0')
        {
            arr[(arr_str[i][j] -'a')] ++;
            j++;
        }
    }
    for (i=0; i<26; i++)
    {
        if(arr[i] % num_str != 0)
            return E_FAILLURE;
    }
    return E_SUCCESS;
}

void reverse_word_string(char* str)
{
    char* rev_str;
    char* tokens[50];
    char* tok = strtok(str," ");
    int i=0,tok_len,k=0,j;

    rev_str = (char*)malloc(strlen(str));

    if(!str)
        return;
    do
    {
        tokens[k] = tok; k++;
        tok = strtok(NULL," ");
    }while(tok != NULL);
    for(j=k-1;j>=0;j--)
    {
        strcpy(&(rev_str[i]),tokens[j]);
        tok_len = strlen(tokens[j]);
        rev_str[i+tok_len] = ' ';
        i = i+tok_len+1;
    }
    rev_str[i-1] = '\0';
    strcpy(str,rev_str);

}

void permute_str(char *str, unsigned int start, unsigned int end)
{
    char temp;
    unsigned int i;
    ///printf("\n\n 1: %s",str);
    if(start == end)
    {
        printf("\n %s", str);
    }
    else
    {
        for(i=start;i<end;i++)
        {
            temp = str[start];
            str[start] = str[i];
            str[i] = temp;
            permute_str(str,start+1,end);
            temp = str[start];
            str[start] = str[i];
            str[i] = temp;
        }
    }
}

void str_combination(char* output, char* str,unsigned int len,unsigned int k,unsigned int idx)
{
    int i;
    if(k==idx)
    {
        output[k+1] = '\0';
        printf("\n%s",output);
    }
    else
    {
        for(i=idx;i<len;i++)
        {

            output[idx] = str[i];
            if(i < k)
                str_combination(output,(str+idx),len,k,idx+1);
            else
            {
                  output[k+1] = '\0';
                  printf("\n%s",output);
            }

        }
    }
}

void all_combinations_str(char* str,unsigned int k)
{
    unsigned int len = strlen(str);
    char* output = (char*)malloc(len+1);

    printf(" \n %d", len);

    str_combination(output,str,len,k,0);
}



void print_trei(trie_node* node)
{
    unsigned int i;
    printf("\nchar %c", node->c);
    if(node->is_val == 1)
    {
        printf("\nval = %d", node->val);
    }
    for(i=0;i<26;i++)
    {
        if(node->nodes[i] != NULL)
            print_trei(node->nodes[i]);
    }
}

void get_trie_node(struct trie_node** node,char c,int val)
{
    unsigned int i;
    (*node) = (struct trie_node*)malloc(sizeof(struct trie_node));
    for(i=0;i<26;i++)
    {
        (*node)->nodes[i] = NULL;
    }
    (*node)->c = c;
    if(val != INT_MIN)
    {
        (*node)->val = val;
        (*node)->is_val = 1;
    }
    else
        (*node)->is_val = 0;
}

void add_trie_word(trie_data* entry)
{
    trie_node *node = NULL;
    unsigned int i = 0;
    node = master;
    while(entry->str[i] != '\0')
    {
        if(node->nodes[entry->str[i]-'a'] == NULL)
        {

            if(entry->str[i+1] == '\0')
                get_trie_node(&(node->nodes[entry->str[i]-'a']),entry->str[i],entry->val);
            else
                get_trie_node(&(node->nodes[entry->str[i]-'a']),entry->str[i],INT_MIN);
        }
        else if(entry->str[i+1] == '\0')
            node->nodes[entry->str[i]-'a']->val = entry->val;
        node = node->nodes[entry->str[i]-'a'];
        i++;
    }
}

void construct_trie()
{
    get_trie_node(&master,' ',INT_MIN);
 }

int get_node_val(char* str)
{
    trie_node* node = master;
    unsigned int i = 0;
    while(str[i]!= '\0')
    {
        if(node == NULL)
        {
            printf("\n\n Error : String not present");
            return INT_MIN;
        }
        else
            node = node->nodes[str[i]-'a'];
        i++;
    }
    if(node->is_val == 1)
        return node->val;
    else
    {
        printf("\n\n Error : String not present");
        return INT_MIN;
    }
}

void get_strings(char* prefix,trie_node* node)
{
    char temp[2],temp1[100];
    int j;
    if(node->is_val == 1)
    {
            printf("\n String %s  val %d",prefix,node->val);
            return;
    }
    for(j=0;j<26;j++)
    {
        if(node->nodes[j] != NULL)
        {
                strcpy(temp1,prefix);
                temp[0]= node->nodes[j]->c;
                temp[1]='\0';
                strcat(temp1,temp);
                get_strings(temp1,node->nodes[j]);
        }
    }
}

void get_strings_with_prefix(char *prefix)
{
    trie_node* node = master;
    unsigned int i =0;
    while(prefix[i]!='\0')
    {
        if(node == NULL)
        {
            printf("\n\n Error : Prefix not present");
            return;
        }
        else
            node = node->nodes[prefix[i]-'a'];
        i++;
    }
    get_strings(prefix,node);
}

char* final_dir(char* cur_dir, char* string)
{
    char* temp = (char*)malloc(strlen(cur_dir)+strlen(string));
    char *temp2 = string , *tok;
    strcpy(temp,cur_dir);

    while((tok = strtok(temp2,"/")))
    {
        temp2 = NULL;
        if(!strcmp(tok,".."))
        {
            temp[(unsigned int)(strrchr(temp,'/')-temp)] = '\0';
        }
        else if (!strcmp(tok,"."))
        {
            continue;
        }
        else{
            strcat(temp,"/");
            strcat(temp,tok);
        }
    }
    return temp;
}

void min_coin(int* coin_arr,int val,int len)
{
    int* table = (int *)malloc(sizeof(int)*val+1);
    int i,j;
    int sub_val;

    table[0] = 0;
    for(i=1;i<= val;i++)
    {
        table[i] = INT_MAX;
    }

    for(j=1;j<= val;j++)
    {
        printf("\n");
        for(i=0;i<len;i++)
        {
            if(coin_arr[i] <= j)
            {
                sub_val = table[j-coin_arr[i]];
                if(sub_val != INT_MAX && sub_val+1 < table[j])
                    table[j] = sub_val +1 ;
            }
        }
         for(i = 0 ;i <= val; i++)
        {
            printf("  %d", table[i]);
        }
    }
// int coin_arr[10] = {1,5,4,7},val = 12;
    for(i = 0 ;i <= val; i++)
    {
        printf(" \n table [%d] = %d", i, table[i]);
    }

}

int total_was_of_coins(int* coin_arr,int val,int len)
{
    if(val == 0)
        return 1;
    if(val < 0 )
        return 0;
    if( len <= 0 &&  val > 0)
        return 0;
    printf("\n %d %d", val,len);
    return (total_was_of_coins(coin_arr,val,len-1) + total_was_of_coins(coin_arr,(val-coin_arr[len-1]),len));

}

