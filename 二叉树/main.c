#include"btree.h"
#include"Queue.h"
#include <stdio.h>
#include <stdlib.h>
//ABD#GI##J###CE#HK###F##
int main()
{
	
	BTNode* root = BinaryTreeCreate("ABD#GI##J###CE#HK###F##");
	
	int TreeSize=BinaryTreeSize(root);
	printf("树总共有结点%d个\n", TreeSize);

	int TreeLeafSize = BinaryTreeLeafSize(root);
	printf("树的叶子结点有%d个\n", TreeLeafSize);

	int Complete=BinaryTreeComplete(root);
	printf("二叉树是否为完全二叉树：%d\n", Complete);
	
	int TreeLevelKSize = BinaryTreeLevelKSize(root, 4);
	printf("第K层有几个数：%d\n", TreeLevelKSize);
	


	printf("前序：");
	BinaryTreePrevOrder(root);
	
	printf("\n中序：");
	BinaryTreeInOrder(root);
    
	printf("\n后序：");
	BinaryTreePostOrder(root);
	
	printf("\n层序：");
	BinaryTreeLevelOrder(root);
	
	
	printf("\n前序：");
	BinaryTreePrevOrderNonR(root);
	
	printf("\n中序：");
	BinaryTreeInOrderNonR(root);
	
	printf("\n后序：");
    BinaryTreePostOrderNonR(root);

	putchar('\n');
	
	
	BinaryTreeDestory(root);

	system("pause");
	return 0;
}