#include "Queue.h"

//构造单链表
void QueueInit(Queue* plist)
{
	assert(plist);
	plist->head = NULL;
	plist->rear = NULL;
}

//销毁单链表
void QueueDestory(Queue* plist)
{
	QueueNode *tmp;
	while (plist->head) {//单个释放每个结点
		tmp = plist->head;
		plist->head = plist->head->next;
		free(tmp);
	}
}


void QueuePop(Queue* plist)
{
	assert(plist);
	QueueNode* tmp;
	if (plist->head) {
		tmp = plist->head;
		plist->head = plist->head->next;
		free(tmp);
	}
}

//前插结点
void QueuePush(Queue* plist, QuDataType x)
{
	QueueNode* cur = (QueueNode*)malloc(sizeof(QueueNode));
	cur->data = x;
	cur->next = NULL;
	if (QueueIsEmpty(plist))
	{
		plist->head = plist->rear = cur;
		return;
	}   
	plist->rear->next = cur;
	plist->rear = cur;
}

int QueueIsEmpty(Queue* plist)
{
	return plist->head ==NULL;
}

QuDataType QueueTop(Queue* plist)
{
	return plist->head->data;
}



