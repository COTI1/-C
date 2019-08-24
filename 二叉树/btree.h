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

int BinaryTreeSize(BTNode* root); //求结点个数
int BinaryTreeLeafSize(BTNode* root); 
int BinaryTreeLevelKSize(BTNode* root,int k);//第几层有几个结点
//1.层序遍历法（无孩子也入队） 2.给递归算法加层号


void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

void BinaryTreeLevelOrder(BTNode* root);

void BinaryTreePrevOrderNonR(BTNode* root);
void BinaryTreeInOrderNonR(BTNode* root);
void BinaryTreePostOrderNonR(BTNode* root);

#endif // ! _BTREE_H_
