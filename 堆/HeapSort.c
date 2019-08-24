#include<stdio.h>
#include<stdlib.h>
//static���ƶ��������Ʊ�׼������������
static void adjustDown(int* data, int size, int m)//���µ����㷨
{
	int cur = m;
	int n;
	while (cur * 2 + 1 < size)
	{
		if (cur * 2 + 2 >= size)
		{   //û���Һ���
			n = cur * 2 + 1;
		}
		else    //�Ƚ��������ӵĴ�С
		{
			if (data[cur * 2 + 1] > data[cur * 2 + 2])
			{
				n = cur * 2 + 1;
			}
			else
			{
				n = cur * 2 + 2;
			}
		}

		if (data[cur] < data[n])//�ͽϴ�ĺ��ӽ��н���
		{
			int tmp = data[cur];
			data[cur] = data[n];
			data[n] = tmp;

			cur = n;

		}
		else
		{
			break;
		}
	}
}

void SwapHeap(int* data, int size)
{
	if (size == 0)
	{
		return;
	}

	int tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;

	adjustDown(data, size - 1, 0);
}


void HeapSortS(int* src, int n)
{
	int i;

	for (i = n / 2 - 1; i >= 0; i--)//�����һ����Ҷ�ӽ����ǰ�������µ�������
	{
		adjustDown(src, n, i);
	}
	for (; n > 1; n--)
	{
		SwapHeap(src, n);
	}
}



void PrintArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d  ", arr[i]);
	}
	putchar('\n');
}


int main1()
{
	int data[10] = { 12,2,56,7,3,5,73,45,6,23 };
	HeapSortS(data, 10);
	PrintArray(data, 10);
	system("pause");
	return 0;
}

