#include "slist.h"

//���쵥����
void SListInit(SList* plist)
{
	assert(plist);
	plist->head = NULL;
}

//���ٵ�����
void SListDestory(SList* plist)
{
	SListNode *tmp;
	while (plist->head) {//�����ͷ�ÿ�����
		tmp = plist->head;
		plist->head = plist->head->next;
		free(tmp);
	}
}


//ǰ����
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->data = x;
	cur->next = plist->head;
	plist->head = cur;
}


void SListPopFront(SList* plist)
{
	assert(plist);
	SListNode* tmp;
	if (plist->head) {
		tmp = plist->head;
		plist->head = plist->head->next;
		free(tmp);
	}
}


//ǰɾ���
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode *cur;
	for (cur = plist->head; cur; cur = cur->next) {
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}


//���ҽ��
SListNode* SListFind(SList* plist, SLTDataType x)
{
	assert(plist);
	SListNode *cur;
	for (cur = plist->head; cur; cur = cur->next) {
		if (cur->data == x) {
			return cur;
		}
	}
	return NULL;
}

//�ڵ�Y��ǰ��������
void SListInsertFront(SList* plist, SLTDataType x, SLTDataType src)
{
	assert(plist);
	SListNode* cur;
	SListNode *newdata = (SListNode *)malloc(sizeof(SListNode));
	if (plist->head->data == x) {
		SListPushFront(plist, src);
		return;
	}
	for (cur = plist->head; cur->next; cur = cur->next) {
		if (cur->next->data == x) {
			break;
		}
	}
	newdata->data = src;
	newdata->next = cur->next;
	cur->next = newdata;
}


//���X
void SListInsertAfter(SListNode *pos, SLTDataType x)
{
	assert(pos);
	SListNode *cur = (SListNode *)malloc(sizeof(SListNode));
	cur->data = x;
	cur->next = pos->next;
	pos->next = cur;
}


void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode *tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
}

//������ת
void SListReverse(SList* plist)
{
	assert(plist->head);
#if 0  //��һ�������У�ͷ�����
	SlistNode *tmp = plist->head->next;
	SListNode *cur = plist->head;
	while (tmp) {
		cur->next = tmp->next;
		tmp->next = plist->head;
		plist->head = tmp;
		tmp = cur->next;
	}
#elif 0  //��������һ��ͷɾ��һ��ͷ��
	Slist *reve = (SList *)malloc(sizeof(SList));
	SListInit(reve);
	SListNode* cur;
	for (cur = plist->head; cur; cur = cur->next) {
		SListPushFront(reve, cur->data);
	}
	SListDestory(plist);
	plist->head = reve;
#else
	SListNode* tmp = plist->head->next;
	SListNode* cur = plist->head;
	cur->next = NULL;
	while (tmp) {
		plist->head = tmp;
		tmp = tmp->next;
		plist->head->next = cur;
		cur = plist->head;
	}
#endif
}



//����ֲ�����
SListNode * GetIntersectionNode(SList* listA, SList* listB)
{
	int lenA = 0;
	int lenB = 0;
	SListNode* cur;
	SListNode* headlong = listA->head;
	SListNode* headshort = listB->head;
	for (cur = listA->head; cur; cur = cur->next) {
		lenA++;
	}
	for (cur = listB->head; cur; cur = cur->next) {
		lenB++;
	}
	int gap = lenA - lenB;
	if (gap < 0) {
		gap *= -1;
		headshort = listA->head;
		headlong = listB->head;
	}
	int i;
	for (i = 0; i < gap; i++) {

	}

}



//�ж��Ƿ��л�
//����������һ��һ���������������ɻ�
int SListHasCycle(SList * plist)
{
	SListNode *fast = plist->head;
	SListNode *slow = plist->head;
	while (slow&&fast&&fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return fast;
		}
	}
	return NULL;
}




//���뻷��

SListNode* SListGetCycleNode(SList* plist)

{

	SListNode *fast = plist->head;
	SListNode *slow = plist->head;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return fast;
		}

	}
	return NULL;
}



SListNode * SListDetectCycle(SList* plist)
{

	SListNode *tmp = SListGetCycleNode(plist);
	if (NULL == tmp)
	{
		return NULL;
	}
	SListNode * cur = plist->head;
	for (; cur; cur = cur->next, tmp = tmp->next)
	{
		if (cur == tmp)
		{
			return cur;
		}
	}
	return NULL;
}