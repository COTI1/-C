#ifndef  _HEAP_H_
#define   _HEAP_H_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int HPDataType;

typedef struct Heap {
	HPDataType* data;   
	int size;    
	int capacity;
}Heap;

void HeapN(Heap* hp);
void HeapInit(Heap* hp, HPDataType* a, int n); 
void HeapDestory(Heap* hp); 
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp); 
HPDataType HeapTop(Heap* hp);
int HeapPrint(Heap* hp);
int HeapPrintS(Heap* hp);
void HeapSort(Heap* hp);// ∂—≈≈–Ú 
void TestHeap();
int HeapSize(Heap* hp); 
int HeapEmpty(Heap* hp);

#endif