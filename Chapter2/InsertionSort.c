//Insertion Sort:
//---------------
//Function InsertionSort(A[0..N-1])
//begin
//	for i = 1 to N-1
//		key = A[i]
//		j = i-1
//		while j>0 and A[j] > key
//			A[j+1] = A[j]
//			j = j-1
//		A[j+1] = key
//
//	return A
//end

#include<stdio.h>

int *Insertion_sort(static int *A, int length)
{
	int i, j, key, count =0;
	for (i = 1; i < length; ++i)
	{
		key = A[i];
		// Replace with A[j] < key to search in non-Increasing order
		for (j = i-1; j>=0 && A[j]>key ; --j) 
		{
			A[j+1]=A[j];
			count++;
		}
		A[j+1] = key;
	}
	printf("Count = %d\n", count);
	return A;
}

int main()
{
	int i, length, *SortedArray;
	int a[]={5, 2, 4, 6, 1, 3};
	length = sizeof(a)/sizeof(int);
	
	SortedArray = Insertion_sort(a, length);
	for (i = 0; i < length; i++)
		printf("%d ",SortedArray[i]);

	getchar();
	return 0;
}
