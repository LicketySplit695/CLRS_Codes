//Selection Sort:
//---------------
//SelectionSort(A[0..N-1])
//	for i = 0 to N-1
//		min = A[i]
//		pos = 0
//		for j = i+1 to N-1
//			if A[j] < min
//			then
//				min = a[j]
//				pos = j
//		if(pos > 0)
//			swap(A[i], A[pos])


#include<stdio.h>
void swapInt(int *a, int *b);

int *SelectionSort(int *a, int length)
{
	int i, j, min, pos;

	for (i = 0; i < length - 1; i++)
	{
		min = a[i]; pos = 0;
		for (j = i + 1; j < length; j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				pos = j;
			}
		}
		if (pos > 0)
			swapInt(&a[i], &a[pos]);
	}
	return a;
}

void swapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() 
{
	int a[] = {1,7,4,2,3};
	int length, *sortedArray, i;

	length = sizeof(a) / sizeof(int);
	sortedArray = SelectionSort(a, length);

	for (i = 0; i < length; i++)
	{
		printf("%d ", *(sortedArray + i));
	}

	getchar();
	return 0;
}
