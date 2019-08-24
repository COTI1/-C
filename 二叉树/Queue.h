#ifndef _Queue_H_
#define _Queue_H_
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"btree.h"

typedef BTNode *  QuDataType;

typedef struct QueueNode
{
	QuDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue {
	QueueNode* head;
	QueueNode* rear;
}Queue;


void QueueInit(Queue* plist);
void QueueDestory(Queue* plist);
void QueuePop(Queue* plist);
QuDataType QueueTop(Queue* plist);
void QueuePush(Queue* plist, QuDataType x);
int QueueIsEmpty(Queue* plist);

#endif //_Queue_H_