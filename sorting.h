#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <string.h>

void bubblesort(int *arr,int len);

void insertionsort(int *arr,int len);

void selectionsort(int *arr,int len);

void meargesort(int *arr,int start,int end);

void quicksort(int *arr,int start,int end);

void heapsort(int *arr,int len);

#endif
