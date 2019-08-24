#include "List.h"


void ListInit(List* plist)
{
	plist->head = (ListNode*)malloc(sizeof(ListNode));
	memset(&plist->head->data, 0, sizeof(LTDataType));//��0,Ч�ʸ�
	plist->head->next = plist->head->prev = plist->head;
}

//ǰ��
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

//���
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
//�Լ�д��һ����
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
	if (tmp != plist->head) {//ѭ��ÿ�� ǰɾ����
		tmp->prev->next = tmp->next;
		//plist->head->next=tmp->next;
		tmp->next->prev = tmp->prev;
		free(tmp);//�ͷź��޷��ҵ���һ�����
		tmp = plist->head->next;//��Ϊÿ��ɾ������ͷ������һ����㣬���Խ�TMP��ֵΪͷ���
	}
	free(plist->head);
	plist->head = NULL;
}