#include <stdio.h>
#include <string.h>

void bubblesort(int *arr,int len)
{
	int i,j,temp;

	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void insertionsort(int *arr,int len)
{
	int i,j,temp;

	for(i=0;i<len-1;i++)
	{
		j=i;
		while((j>=0) && (arr[j] > arr[j+1]))
		{
			temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
			j--;
		}
	}
}


void selectionsort(int *arr,int len)
{
	int i,j,temp,smallest;

	for(i=0;i<len-1;i++)
	{
		smallest=i;
		for(j=i+1;j<len;j++)
		{
			if(arr[smallest]>arr[j])
			{
				smallest=j;
			}
		}
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
	}
}

void mearge(int* arr,int s,int m,int e)
{
	int temp[50];

	int i=s,j=m,k=0;

	while((i < m) && (j <= e))
	{
		if(arr[i]<arr[j])
		{
			temp[k] = arr[i];
			i++;k++;
		}
		else
		{
			temp[k]=arr[j];
			j++;k++;
		}
	}
	while(i<m)
	{
		temp[k]=arr[i];
		i++;k++;
	}
	while(j<=e)
	{
		temp[k]=arr[j];
		j++;k++;
	}
	i=0;
	for(k=s;k<=e;k++)
	{
	     arr[k]=temp[i];
        i++;
	}
}

void meargesort(int *arr,int start,int end)
{
     int middle;
	if( start < end)
	{
        middle = (start + end + 1) / 2;
		meargesort(arr,start,middle-1);
		meargesort(arr,middle,end);
		mearge(arr,start,middle,end);
	}
}

void quicksort(int *arr,int start,int end)
{
    int i=start,j=end,pivot= arr[end];
    int temp;

    if((end - start +1) < 2)
        return;
    do
    {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }while(i<j);
    quicksort(arr,start,j-1);
    quicksort(arr,j+1,end);
}

void heapify(int *arr,int i,int len)
{
    int largest = i,flag=0,temp;
    if ((2*i+2 < len) && arr[2*i+2] > arr[largest])
    {
        flag=1;largest=2*i+2;
    }
    if ((2*i+1 < len) && arr[2*i+1] > arr[largest])
    {
        flag=1;largest=2*i+1;
    }
    if(flag == 1)
    {
        temp=arr[largest];
        arr[largest]= arr[i];
        arr[i]=temp;
        heapify(arr,largest,len);
    }
}

void heapsort(int *arr,int len)
{
    int i=0,temp;
    for(i=0;i<len/2;i++)
    {
         heapify(arr,i,len);
    }
    for(i=0;i<len;i++)
    {
        temp = arr[0];
        arr[0] = arr[len-i-1];
        arr[len-i-1]=temp;
        heapify(arr,0,len-i-1);
    }
}

