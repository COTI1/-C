#ifndef  _SORT_H_
#define  _SORT_H_
#define BUFSIZE 10000

#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void QuickSort(int *src, int n);
void printArray(int * src, int n);
//void InsertSort(int * src, int n);
void ShellSort(int * src, int n);
void MergeSort(int * src, int n);

void QuickSortNonR(int *src, int n);




#endif  //_SORT_H_