#include "Queue.h"

//���쵥����
void QueueInit(Queue* plist)
{
	assert(plist);
	plist->head = NULL;
	plist->rear = NULL;
}

//���ٵ�����
void QueueDestory(Queue* plist)
{
	QueueNode *tmp;
	while (plist->head) {//�����ͷ�ÿ�����
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

//ǰ����
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



