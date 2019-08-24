#include"heap.h"

void adjustDown(Heap* hp, int m)//向下调整算法
{
	int cur = m;
	int n;
	while (cur*2+1 < hp->size)
	{
		if (cur * 2 + 2 >= hp->size) {   //没有右孩子
			n = cur * 2 + 1;
		}
		else    //比较两个孩子的大小
		{
			if(hp->data[cur*2+1] > hp->data[cur*2+2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}
		if (hp->data[cur] < hp->data[n])//和较大的孩子进行交换
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[n];
			hp->data[n] = tmp;

			cur = n;

		}
		else
		{
			break;
		}
	}
}


void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->capacity = n * 2;
	hp->size = n;
	hp->data = (HPDataType*)calloc(hp->capacity, sizeof(HPDataType));
	
	int i;
	for (i = 0; i < n; i++) 
	{
		hp->data[i] = a[i];
	}
	for (i = n/2-1; i >=0; i--) //从最后一个非叶子结点向前进行向下调整方法
	{
		adjustDown(hp, i);
	}
}


void HeapDestory(Heap* hp) 
{
	if (hp->data)
	{
		free(hp->data);
	}
	hp->data = NULL;
}


void HeapPush(Heap* hp, HPDataType x)//插入
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->data = (HPDataType*)realloc(hp->data, hp->capacity*sizeof(HPDataType));
	}
	
	int cur = hp->size;
	hp->data[hp->size] = x;
	
	hp->size++;
	

	while (cur>0) 
	{
		if (hp->data[cur] > hp->data[(cur - 1) / 2])
		{
			int tmp = hp->data[cur];
			hp->data[cur] = hp->data[(cur - 1) / 2];
			hp->data[(cur - 1) / 2] = tmp;

			cur = (cur - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPop(Heap* hp)
{
	if (hp->size == 0) 
	{
		return;
	}
	
	hp->size--;
	int tmp = hp->data[0];
	hp->data[0] = hp->data[hp->size];
	hp->data[hp->size] = tmp;
    
	adjustDown(hp, 0);
}



HPDataType HeapTop(Heap* hp) 
{
	if (hp->size == 0) 
	{
		return (HPDataType) 0;
	}
	return hp->data[0];
}




int HeapPrintS(Heap* hp) {
	int i;
	int rn = 0;
	int bin = 2;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d  ", hp->data[i]);
		if (i == rn)
		{
			putchar('\n');
			rn += bin;
			bin  *= 2;
		}
	}
}

int HeapPrint(Heap* hp)
{
	int i;
	for (i = 0; i < hp->size; i++)
	{
		printf("%d  ", hp->data[i]);
		
	}
}


void HeapSort(Heap* hp)// 堆排序    可以改成求第N大的值问题
{
	int tmp = hp->size;
	while (hp->size > 1)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
}



//第N大
void HeapN(Heap* hp)
{
	int tmp = hp->size;
	int num;
	printf("输入N:");
	scanf("%d", &num);
	while (hp->size > num)
	{
		HeapPop(hp);
	}
	hp->size = tmp;
	int count = hp->size - num;
	printf("第N大的数为：%d", hp->data[count]);

}
