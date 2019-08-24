#include"sort.h"
#include"Queue.h"
int main()
{
#if 1
	int src[10] = { 2,8,7,6,5 };
	InsertSort(src, 10);
	//ShellSort(src,10);
	//MergeSort(src,10);
	//QuickSort(src, 10);
	//QuickSortNonR(src, 10);
	printArray(src, 10);
#else
	srand(time(NULL));
	int src[BUFSIZE];
	int i;
	for (i = 0; i < BUFSIZE; i++)
	{
		src[i] = rand() % 5000 + 1;//1~5000`

	}
	//InsertSort(src, BUFSIZE);
	//ShellSort(src,BUFSIZE);
	//MergeSort(src,BUFSIZE);
	//QuickSort(src, BUFSIZE);
	//QuickSortNonR(src, BUFSIZE);
	printArray(src, BUFSIZE);
#endif
	system("pause");
	return 0;
}
