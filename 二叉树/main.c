#include"btree.h"
#include"Queue.h"
#include <stdio.h>
#include <stdlib.h>
//ABD#GI##J###CE#HK###F##
int main()
{
	
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	
	int TreeSize=BinaryTreeSize(root);
	printf("���ܹ��н��%d��\n", TreeSize);

	int TreeLeafSize = BinaryTreeLeafSize(root);
	printf("����Ҷ�ӽ����%d��\n", TreeLeafSize);

	int Complete=BinaryTreeComplete(root);
	printf("�������Ƿ�Ϊ��ȫ��������%d\n", Complete);
	
	int TreeLevelKSize = BinaryTreeLevelKSize(root, 4);
	printf("��K���м�������%d\n", TreeLevelKSize);
	


	printf("ǰ��");
	BinaryTreePrevOrder(root);
	
	printf("\n����");
	BinaryTreeInOrder(root);
    
	printf("\n����");
	BinaryTreePostOrder(root);
	
	printf("\n����");
	BinaryTreeLevelOrder(root);
	
	
	printf("\nǰ��");
	BinaryTreePrevOrderNonR(root);
	
	printf("\n����");
	BinaryTreeInOrderNonR(root);
	
	printf("\n����");
    BinaryTreePostOrderNonR(root);

	putchar('\n');
	
	
	BinaryTreeDestory(root);

	system("pause");
	return 0;
}