
#ifndef SAMPLE_H
#define SAMPLE_H

#define E_FAILLURE 0
#define E_SUCCESS 1

typedef struct
{
    int val;
    unsigned int i,j;
}sub_array;

typedef struct
{
    char str[50];
    int val;
}trie_data;

struct trie_node
{
    char c;
    struct trie_node *nodes[26];
    int is_val,val;
};

typedef struct trie_node trie_node;

int detect_palindrome(const char* xx);
void maximum_subsequence(sub_array* max_seq, int *xx,unsigned int len);
unsigned int rev_int(unsigned int num);
int anagrams(char* arr_str[],int num_str);
void reverse_word_string(char *str);
void permute_str(char *str, unsigned int start, unsigned int end);

void construct_trie();
void add_trie_word(trie_data* entry);
void print_trei(trie_node* node);
int get_node_val(char* str);
void get_strings(char* prefix,trie_node* node);
void get_strings_with_prefix(char *prefix);
void all_combinations_str(char* str,unsigned int k);

char* final_dir(char* cur_dir, char* string);
void min_coin(int* coin_arr,int val,int len);
int total_was_of_coins(int* coin_arr,int val,int len);
#endif // SAMPLE_H
