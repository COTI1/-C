#include"btree.h"
#include"Queue.h"
#include"stack.h"
//���������
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


//�ݹ�����
void BinaryTreePrevOrder(BTNode* root)
{
	
	if (root) 
	{
		putchar(root->data);
		BinaryTreePrevOrder(root->lchild);
		BinaryTreePrevOrder(root->rchild);
	}
}



//��K����N�����
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


//���ܹ��м������
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


//�ݹ�����
void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->lchild);
		putchar(root->data);
		BinaryTreeInOrder(root->rchild);
	}
}


//�ݹ����
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


//������������У�����Ϊ������

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


//�������ж��ٸ�Ҷ�ӽ��
int TreeLeafSize;
int BinaryTreeLeafSize(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur)//����Ϊ����ջΪ������
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

//�ǵݹ�ǰ��
void BinaryTreePrevOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur= root;//�Ӹ���ʼ
	StackInit(&st,100);
	while (cur)//����Ϊ����ջΪ������
	{
		putchar(cur->data);//���ʵ�ǰ���
		if (cur->rchild)//������Һ��ӣ��Һ�����ջ
		{
			StackPush(&st, cur->rchild);
		}
		if (cur->lchild)//��������ӡ���������
		{
			cur = cur->lchild;
		}
		else//û������ȥջ��
		{
			cur = StackTop(&st);
			StackPop(&st);//ȡ����ʱ��
		}
	}
	StackDestory(&st);
}




//�ǵݹ�����
void BinaryTreeInOrderNonR(BTNode* root)
{
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	while (cur||!StackIsEmpty(&st))//����Ϊ����ջΪ������
	{
		for (; cur;cur= cur->lchild)//����ǰ��㼰������ջ
		{ 
		   StackPush(&st, cur);
		}		
		cur = StackTop(&st);//ȡ��ջ����1.����Һ���Ϊ�գ�forѭ��������ֱ��ȡջ��
		                    //2.����Һ��Ӳ�Ϊ�գ���ô��һ��û�����ӵĽ��
		                    //1.������������� 2��������Ϊ�� �������֣���ǰ��㶼Ҫ��ӡ��
	  
	  //if (!cur)  break;   ����ѭ��Ϊwhile(1)
		if(cur){      //����ʡ�Ե�if(cur){}
			putchar(cur->data);
		    StackPop(&st);
			cur=cur->rchild;//������Ϊ��ʱ�����ջ�Ƿ�Ϊ�գ����ջ�գ�ѭ������
        }
	}
	StackDestory(&st);
}


//�ǵݹ����
void BinaryTreePostOrderNonR(BTNode* root)//��һ�γ�ʼ��push)Ϊ0���ڶ���Ϊ1��������ֱ�Ӵ�ӡ
{
	char tag[64];
	Stack st;
	BTNode * cur = root;
	StackInit(&st, 100);
	
	do//����Ϊ����ջΪ������
	{
		for (; cur; cur=cur->lchild)//����ǰ��㼰����������ջ
		{
			
			StackPush(&st, cur);	
			tag[st.size-1] = 0;//�������������ʱ�ǣ�LT��
		}
		while (tag[st.size-1] && !StackIsEmpty(&st))//������ǰ������ֱ�Ӵ�ӡ    
			//ǰ����������������
			//1.���˴ε�CURΪ��ʱ�������FOR����������������
			//2.��CUR��Ϊ�գ������FOR����������������
			//�����⵽��ǰ��LT����λ��Ҳ�������1������ô�ڴ�ӡ�굱ǰ������ȥ�����һ������ǲ���Ҳ����ӡ�ˣ�֤��ʹ��������������WHILEѭ����ӡ
			//���������ֻ��ѭ����ʱ��Ч
		{
			cur = StackTop(&st);
			putchar(cur->data);
			StackPop(&st);
		}
		if(!StackIsEmpty(&st))//������ֻ�����һ��ѭ������ʱ��Ч
		{
		   cur = StackTop(&st);
		   //1.���WHILE���ˣ�������������ϣ���LT��λ
		   //2.���WHILEû����֤�������������ڣ���LT��λ
		   tag[st.size-1] = 1;
		   cur = cur->rchild;
		   //������������Ϻ󣬷���������
		}
	} while (!StackIsEmpty(&st));
	//���ں�������и��ڵ�����ջ�����Ը�����ջǰ��ջ������Ϊ�գ�������ջ�Ƿ�Ϊ����Ϊѭ����������
	
	StackDestory(&st);
}


//�ж϶������Ƿ�Ϊ��ȫ������
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
