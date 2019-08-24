#ifndef _SLIST_H_
#define _SLIST_H_
/*
for(cur = head; cur; cur = cur->next)
{
	 cur;
}

for(cur = head->next; cur != head; cur = cur->next)
{
	  cur;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



typedef int SLTDataType;

typedef struct SListNode
{
   SLTDataType data;
   struct SListNode* next;
}SListNode;

typedef struct SList {
     SListNode* head;
}SList;


void SListInit(SList* plist);
void SListDestory(SList* plist);
SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
void SListInsertAfter(SListNode* pos, SLTDataType x);
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);
void SListReverse(SList* plist);
void SListPrint(SList* plist);
void TestSList();
int SListHasCycle(SList* plist);

SListNode * GetIntersectionNode(SList* listA, SList* listB);
#endif //_SLIST_H_