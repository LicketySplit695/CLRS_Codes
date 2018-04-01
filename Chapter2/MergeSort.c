//Merge Sort:
//-----------
//Merge(A, p, q, r)
//	n1 = q - p + 1
//	n2 = r - q
//	L[0..N1] <- Left SubArray
//	R[0..N2] <- Right SubArray
//	for i = 0 to N1 - 1
//		L[i] = A[p + i]
//	L[N1] = infinity
//	for j = 0 to N2 - 1
//		R[j] = A[q + 1 + j]
//	R[N2] = infinity
//	i = 0
//	j = 0
//	for k = p to k <= r
//		if L[i] <= R[j]
//		then
//			A[k] = L[i]
//			i = i + 1
//		else
//			A[k] = R[j]
//			j = j + 1
//
//MergeSort(A, p, r)
//	if p < r
//	then
//		q = (p+r)/2
//		MergeSort(A, p, q)
//		MergeSort(A, q + 1, r)
//		Merge(A, p, q, r)	

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void Merge(int *A, int p, int q, int r)
{
	int n1, n2, *L, *R, i, j, k;

	n1 = q - p + 1;
	n2 = r - q;
	L = (int *)malloc((n1 + 1) * sizeof(int));
	R = (int *)malloc((n2 + 1) * sizeof(int));

	for (i = 0; i < n1; i++)
		*(L + i) = *(A + p + i);
	*(L + i) = INT_MAX;

	for (j = 0; j < n2; j++)
		*(R + j) = *(A + q + 1 + j);
	*(R + j) = INT_MAX; 

	for (i = 0, j = 0, k = p; k <= r; k++)
	{
		if (*(L + i) <= *(R + j))
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int *A, int p, int r)
{
	int q;

	if (p < r)
	{
 		q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main() 
{
	int A[] = {1,7,4,9,1};
	int length, i;

	length = sizeof(A) / sizeof(int);
	MergeSort(A, 0, length - 1);

	for (i = 0; i < length; i++)
	{
		printf("%d ", A[i]);
	}

	getchar();
	return 0;
}
