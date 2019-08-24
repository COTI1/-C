#include"sort.h"
#include"Queue.h"

void printArray(int * src,int n) 
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d   ", src[i]);
	}
	putchar('\n');
}

//数组规模足够小时，插排最优
//数组越有序，插排越快
//时间复杂度O（n2）
void InsertSort(int * src, int n)
{
	int i, j;
	int tmp;
	for (i = 1; i < n; i++)
	{
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1]>tmp; j--)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

//希尔排序  数组越有序，插排越快
//利用了插排的特点
void ShellSort(int * src, int n)
{
	int i, j, k;
	int tmp, gap;
	for(gap=n/2;gap;gap/=2)//控制GAP的大小
	for(k=0;k<gap;k++)//进行K次插排
	{
	    for (i = gap+k; i < n; i+=gap)
	   {
		    tmp = src[i];
		    for (j = i; j >= gap && src[j - gap] > tmp; j-=gap)
		    {
		    	src[j] = src[j - gap];
		    }
		    src[j] = tmp;
	    }
	}
}



//归并排序
void dealMergeSort(int * src, int * tmp, int start, int end)
{
	if (start >= end)
	{
		return ;
	}	
	int mid = (start + end) / 2;
	dealMergeSort(src, tmp,start, mid);
	dealMergeSort(src, tmp, mid+1, end);
	
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a <= mid && b <= end)
	{
		if (src[a] < src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++, c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}
	int i;
	for (i = start; i <= end; i++)
	{
		src[i] = tmp[i];
	}

}

void MergeSort(int * src, int n)
{
	int* tmp = (int *)malloc(n * sizeof(int));
	dealMergeSort(src,tmp,  0, n - 1);
	free(tmp);
}




//快排  前序遍历，中序输出
void swapArgs(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	 *pa = *pb;
	 *pb = tmp;
}


/*
双指针法2
以5为基础
			2, 0, 7, 6, 5, 4, 3, 1, 8, 9   
			2, 0, 7, 6, 9, 4, 3, 1, 8, 5
开始	   a^                          ^b     a向后走 b往前走
		       	 a^              ^b           交换a b
			2，0, 1, 6, 9, 4, 3, 7, 8, 5      a向后走 b往前走
			        a^        ^b              交换a b
			2，0, 1, 3, 9, 4, 6, 7, 8, 5      a向后走 b往前走
			           a^  ^b                 交换a b
			2，0, 1, 3, 4, 9, 6, 7, 8, 5      a往后走，a=b循环结束，a与end交换 
			              a^b 
*/
int doublePointerWay2(int *src, int start, int end)
{
	int a = start, b = end - 1;
	int mid = (start + end) / 2;
	swapArgs(src + mid, src + end);//保护枢纽元
	while (a<=b)
	{
		while ( a<end &&src[a] <= src[end] )
		{
			a++;
		}
		while ( b>0 &&src[b] >= src[end] )
		{
			b--;
		}
		if (a == b && (a == 0 || a == end))
			break;
		if (a < b)
		{
		     swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + end);
	return a;
}

int doublePointerWay1(int *src, int start, int end)//双指针法1
{
	int a = start, b = end;
	int flag = 0;
	while (src[b] > src[a])
	{
		b--;
	}
	while (a<b)
	{
		/*与下面的等同
		while (src[b] > src[a])
		{
			b--;
		}
		   
       swapArgs(src[b], src[a]);
	   while (src[b] < src[a])
	   {
		   a++;
	   }
	   swapArgs(src[b], src[a]);
	   */
		swapArgs(src+b, src+a);
		flag = !flag;
		while (src[b] >= src[a])
		{
			flag ? a++: b--;
		}
	}
	return flag ? b:a;//最后一次没有移动的指针被返回
}
/*
挖坑算法（自己）
以2为基础 
            2, 0, 7, 6, 5, 4, 3, 1, 8, 9      
开始	   a^                          ^b     b向前走
           a^                     ^b          b覆盖a
            1，0, 7, 6, 5, 4, 3, 1, 8, 9      a往后走
			     a^              ^b           a覆盖b
            1，0, 7, 6, 5, 4, 3, 7, 8, 9      b往前走
			  b^ a^
            1，0, 2, 6, 5, 4, 3, 7, 8, 9       a,b指针交叉，将2赋回去，结束
*/
int WaKengSort(int *src, int start, int end)
{
	int tmp = src[start];
	int flag = 0;
	int a = start, b = end;
	int mid = (start + end) / 2;

	while (a < b)
	{
		while (b > start && src[b] >= tmp)
		{
			b--;
			flag = 0;
		}
		src[a] = src[b];
		while (a < end && src[a] <= tmp)
		{
			a++;
			flag = 1;
		}
		src[b] = src[a];

	}
	if (flag)
	{
		src[b] = tmp;
		return b;
	}
	else
	{
		src[a] = tmp;
		return a;
	}
		while (a<=b)
	{
		while ( a<end &&src[a] <= src[end] )
		{
			a++;
		}
		while ( b>0 &&src[b] >= src[end] )
		{
			b--;
		}
		if (a == b && (a == 0 || a == end))
			break;
		if (a < b)
		{
		     swapArgs(src + a, src + b);
		}
	}
}

//挖坑法
int digWay(int *src, int start, int end)
{
	int flag = 0;
	int a = start, b = end;
	int tmp = src[start];
	while (1)
	{
		while (b > start &&src[b] >= tmp)
		{
			b--;
		}
		if (a < b)
		{ 
			src[a] = src[b];
		}
		else
		{ 
			src[a] = tmp;
			return a;
		}
		
		while (a < end && src[a] <= tmp)
		{
			a++;
		}
		if (a < b)
		{
			src[b] = src[a];
		}
		else
		{
			src[b] = tmp;
			return b;
		}
	}
}

int HoareWay(int *src, int start, int end)
{
	int a = start + 1, b = end - 2;
	int mid = (start + end) / 2;
	//将start,mid,end比较，冒泡排序
	if (src[start] > src[mid])
	{
		swapArgs(src + start, src + mid);
	}
	if (src[mid] > src[end])
	{
		swapArgs(src + end, src + mid);
	}
	if (src[start] > src[mid])
	{
		swapArgs(src + start, src + mid);
	}
	//若只有三个数，则直接返回mid
	if (end - start <= 2)
	{
		return mid;
	}
	//保护基准值
	swapArgs(src + mid, src + end - 1);
	while (a <= b)
	{
		while (a < end-1 &&src[a] <= src[end-1])
		{
			a++;
		}
		while (b > 1 && src[b] >= src[end-1])
		{
			b--;
		}
		if (a == b && (a == 1 || a == end-1))
			break;
		if (a < b)
		{
			swapArgs(src + a, src + b);
		}
	}
	swapArgs(src + a, src + (end-1));
	return a;
}


//快排递归
void dealQuickSort(int *src, int start, int end)
{
    int mid;
	if (start + 8 < end)
	{
		//mid = HoareWay(src, start, end);
		//mid = digWay(src, start, end);
		//mid = WaKengSort(src, start, end);
		//mid = doublePointerWay2(src, start, end);
		mid = doublePointerWay1(src, start, end);
		dealQuickSort(src, start, mid - 1);
		dealQuickSort(src, mid + 1, end);
	}
	else
		InsertSort(src + start, end - start + 1);
}


void QuickSort(int *src, int n)
{
	dealQuickSort(src, 0, n-1);
}

void QuickSortNonR(int *src, int n)
{
	int start, end;
	int mid;
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu,0);
	QueuePush(&qu,n-1);
	while (!QueueIsEmpty(&qu))
	{
		start = QueueTop(&qu);
		QueuePop(&qu);
		end= QueueTop(&qu);
		QueuePop(&qu);
		mid = HoareWay(src,start,end);
		if (start < mid-1)
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid);

		}
		if (mid+1 < end)
		{
			QueuePush(&qu, mid+1);
			QueuePush(&qu, end);

		}
	}
	QueueDestory(&qu);
}