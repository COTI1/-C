#include"btree.h"
#include"Queue.h"
#include"stack.h"
//创造二叉树
static int s_n ;
BTNode* BinaryTreeCreateExe(BTDataType* src)
{
	
	if (src[s_n] == '#')
	{
		s_n++;
		return NULL;
	}
	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->data = src[s_n];
	s_n++;
	cur->lchild = BinaryTreeCreateExe(src);
	cur->rchild = BinaryTreeCreateExe(src);

	return cur;
}
BTNode* BinaryTreeCreate(BTDataType* src)
{
	s_n = 0;
	return BinaryTreeCreateExe(src);

}


//递归先序
void BinaryTreePrevOrder(BTNode* root)
{
	
	if (root) 
	{
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}



//第K层有N个结点
int N=1,count;
int BinaryTreeLevelKSize(BTNode* root,int k)
{
	if (root)
	{
		N++;
		BinaryTreeLevelKSize(root->lchild,k);
		BinaryTreeLevelKSize(root->rchild,k);
		N--;
		if (N == k)
	    {
		   count++;
	    }
	}
	return count;
}


//树总共有几个结点
int TreeSize;
int BinaryTreeSize(BTNode* root)
{
	if (root)
	{
		TreeSize++;
		BinaryTreeSize(root->lchild);
		BinaryTreeSize(root->rchild);
	}
	return TreeSize;
}


//递归中序
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}


//递归后序
void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->lchild);
		BinaryTreePostOrder(root->rchild);
		putchar(root->data);
	}
}


void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->lchild);
		BinaryTreeDestory(root->rchild);
		free(root);
	}
}


//层序遍历，队列，队列为空跳出

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode*  cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->data);
		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}


//二叉树有多少个叶子结点
int TreeLeafSize;
int BinaryTreeLeafSize(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur)//左孩子为空且栈为空跳出
	{
		if (!cur->lchild && !cur->rchild)
		{
			TreeLeafSize++;
		}
		if (cur->rchild)
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)
		{
			cur = cur->lchild;
		}
		else
		{
			cur = StackTop(&st);
			StackPop(&st);
		}

	}
	StackDestory(&st);
	return TreeLeafSize;
}

//非递归前序
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur= root;//从根开始
	StackInit(&st,100);
	while (cur)//左孩子为空且栈为空跳出
	{
		putchar(cur->data);//访问当前结点
		if (cur->rchild)//如果有右孩子，右孩子入栈
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)//如果有左孩子。访问左孩子
		{
			cur = cur->lchild;
		}
		else//没有左孩子去栈顶
		{
			cur = StackTop(&st);
			StackPop(&st);//取到根时，
		}
	}
	StackDestory(&st);
}




//非递归中序
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur||!StackIsEmpty(&st))//左孩子为空且栈为空跳出
	{
		for (; cur;cur= cur->lchild)//将当前结点及左孩子入栈
		{ 
		   StackPush(&st, cur);
		}		
		cur = StackTop(&st);//取出栈顶（1.如果右孩子为空，for循环不进，直接取栈顶
		                    //2.如果右孩子不为空，那么是一个没有左孩子的结点
		                    //1.左子树访问完毕 2。左子树为空 无论那种，当前结点都要打印）
	  
	  //if (!cur)  break;   跳出循环为while(1)
		if(cur){      //可以省略掉if(cur){}
			putchar(cur->data);
		    StackPop(&st);
			cur=cur->rchild;//右子树为空时，检查栈是否为空，如果栈空，循环跳出
        }
	}
	StackDestory(&st);
}


//非递归后序
void BinaryTreePostOrderNonR(BTNode* root)//第一次初始（push)为0，第二次为1，第三次直接打印
{
	char tag[64];
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	
	do//左孩子为空且栈为空跳出
	{
		for (; cur; cur=cur->lchild)//将当前结点及其左孩子们入栈
		{
			
			StackPush(&st, cur);	
			tag[st.size-1] = 0;//重置左子树访问标记（LT）
		}
		while (tag[st.size-1] && !StackIsEmpty(&st))//可以向前遍历，直接打印    
			//前面的条件分两种情况
			//1.当此次的CUR为空时，上面的FOR不进，此条件成立
			//2.当CUR不为空，上面的FOR进，此条件不成立
			//如果检测到当前的LT被置位（也就是情况1），那么在打印完当前结点后，再去检查上一个结点是不是也被打印了，证明使右子树。所以用WHILE循环打印
			//后面的条件只在循环出时生效
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
		}
		if(!StackIsEmpty(&st))//此条件只在最后一次循环跳出时生效
		{
		   cur = StackTop(&st);
		   //1.如果WHILE进了，左子树访问完毕，给LT置位
		   //2.如果WHILE没进，证明左子树不存在，给LT置位
		   tag[st.size-1] = 1;
		   cur = cur->rchild;
		   //左子树访问完毕后，访问右子树
		}
	} while (!StackIsEmpty(&st));
	//由于后序遍历中根节点最后出栈，所以根结点出栈前，栈不可能为空，所以以栈是否为空作为循环跳出条件
	
	StackDestory(&st);
}


//判断二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	int tag = 0;
	Queue qu;
	BTNode*  cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		
		cur = QueueTop(&qu);
		if (cur->rchild && !cur->lchild)
		{
			return 0;
		}
		if (tag && (cur->rchild || cur->lchild))
		{
			return 0;
		}
		if (cur->lchild)
		{
			QueuePush(&qu, cur->lchild);
		}
		if (cur->rchild)
		{
			QueuePush(&qu, cur->rchild);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}
