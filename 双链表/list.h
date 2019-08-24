#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int LTDataType;

typedef struct ListNode {
    LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;



typedef struct List {
	ListNode* head;
}List;

void ListInit(List* plist);
void ListDestroy(List* plist);
void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);
ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);
void ListPrint(List* plist);


#endif //_LIST_H_