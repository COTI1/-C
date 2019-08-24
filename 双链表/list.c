#include "List.h"


void ListInit(List* plist)
{
	plist->head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->head->data, 0, sizeof(LTDataType));//清0,效率高
	plist->head->next = plist->head->prev = plist->head;
}

//前插
void ListPushFront(List* plist, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->data = x;
	plist->head->next->prev = cur;
	cur->next =plist-> head->next;
	plist->head->next = cur;
	cur->prev = plist->head;
	/*
	if (plist->head->prev = plist->head) {
		plist->head->prev = cur;
	}
    */
}

//后插
void ListPushBack(List* plist, LTDataType x)
{
	ListNode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->data = x;
	plist->head->prev->next = cur;
	cur->prev = plist->head->prev;
	//cur->prev->next = cur;
	plist->head->prev = cur;
	cur->prev = plist->head;

}
//自己写了一部分
void ListPrint(List* plist)
{
	ListNode *cur;
	printf("head->");
	for (cur = plist->head->next; cur != plist->head; cur = cur->next) {
		printf("%d->", cur->data);
	}
	printf("head\n");
}

void ListPopFront(List* plist) {
	ListNode* tmp = plist->head->next;
	if (tmp !=plist-> head) {
		tmp->prev->next = tmp->next;
		//plist->head->next=tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
}

void ListPopBack(List* plist) {
	ListNode* tmp = plist->head->prev;
	if (tmp != plist->head) {
		tmp->prev->next = tmp->next;
		//plist->head->next=tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);
	}
}


void ListDestroy(List* plist)
{
	ListNode* tmp = plist->head->next;
	if (tmp != plist->head) {//循环每个 前删操作
		tmp->prev->next = tmp->next;
		//plist->head->next=tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);//释放后无法找到下一个结点
		tmp = plist->head->next;//因为每次删除的是头结点的下一个结点，所以将TMP赋值为头结点
	}
	free(plist->head);
	plist->head = NULL;
}