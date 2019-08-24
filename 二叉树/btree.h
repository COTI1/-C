#ifndef  _BTREE_H_
#define _BTREE_H_

#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode { 
	BTDataType data;   
	struct BinaryTreeNode* lchild;
	struct BinaryTreeNode* rchild;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* src);
void BinaryTreeDestory(BTNode* root);

int BinaryTreeSize(BTNode* root); //�������
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root,int k);//�ڼ����м������
//1.������������޺���Ҳ��ӣ� 2.���ݹ��㷨�Ӳ��


void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

#endif // ! _BTREE_H_
