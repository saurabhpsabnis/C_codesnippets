
#include <stdio.h>
#include <limits.h>


int binary_search(int val, int* sorted_arr, int start, int end)
{
    unsigned int x;
    while(start <= end)
    {
        x = (end+start)/2;
        if(sorted_arr[x] ==  val)
        {
           // printf("Found");
            return sorted_arr[x];
        }
        else if(val < sorted_arr[x])
        {
            end = x-1;
        }
        else
        {
            start = x+1;
        }
    }
   // printf("number not found\n\n");
    return INT_MIN;
}
