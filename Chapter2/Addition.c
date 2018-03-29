//Addition:
//---------
//Function Addition(A[0..N-1], B[0..N-1])
//begin
//	carry = 0, hold = 0
//	for i = N-1 downto 0
//		hold = A[i] + B[i] + carry
//		carry = hold / 10;
//		C[i+1] = hold % 10
//	C[0] = carry
//	return C
//end

#include<stdio.h>
#include<stdlib.h>

int *Addition(int *A, int *B, int length)
{
	int i, carry = 0, hold = 0;
	int *C = (int *)malloc((length + 1)*sizeof(int));
	for (i = length - 1; i >= 0; --i)
	{
		hold = *(A+i) + *(B+i) + carry;
		carry = hold / 10;
		*(C+i+1) = hold % 10;
	}
	*C = carry;
	return C;
}

int main()
{
	int length, lengthC, i, *C;
	int A[] = {9,0,5,9}; 
	int B[] = {0,8,8,0};
	length = sizeof(A)/sizeof(int);

	C = Addition(A, B, length);

	for(i = 0; i<length + 1; i++)
		printf("%d", *(C+i));

	getchar();
	return 0;
}
