
#include"heap.h"

int main()
{
	Heap hp;
	int a[10] = {12,2,56,7,3,5,73,45,6,23};
	HeapInit(&hp, a, 10);
	HeapPrintS(&hp);
	putchar('\n');
	HeapPush(&hp, 23);
	HeapSort(&hp);
	HeapPrint(&hp);
	putchar('\n');

	HeapN(&hp);
	HeapDestory(&hp);

	

	system("pause");
	return 0;
}





