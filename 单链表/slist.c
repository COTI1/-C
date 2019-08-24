#include "slist.h"

//构造单链表
void SListInit(SList* plist)
{
	assert(plist);
	plist->head = NULL;
}

//销毁单链表
void SListDestory(SList* plist)
{
	SListNode *tmp;
	while (plist->head) {//单个释放每个结点
		tmp = plist->head;
		plist->head = plist->head->next;
		free(tmp);
	}
}


//前插结点
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


//前删结点
void SListPrint(SList* plist)
{
	assert(plist);
	SListNode *cur;
	for (cur = plist->head; cur; cur = cur->next) {
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}


//查找结点
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

//在第Y项前插入数据
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


//后插X
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

//单链表反转
void SListReverse(SList* plist)
{
	assert(plist->head);
#if 0  //在一个链表中，头插操作
	SlistNode *tmp = plist->head->next;
	SListNode *cur = plist->head;
	while (tmp) {
		cur->next = tmp->next;
		tmp->next = plist->head;
		plist->head = tmp;
		tmp = cur->next;
	}
#elif 0  //两个链表，一个头删，一个头插
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



//链表分叉问题
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



//判断是否有环
//找两个链表，一快一慢，两者相遇即成环
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




//找入环点

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