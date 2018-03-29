//Linear Search:
//--------------
//Function LinearSearch(A[0..N-1], ToBeSearched)
//begin
//	pos = 0
//	for i = 0 to N-1
//		if A[i] = ToBeSearched
//			pos = i
//			break
//	return pos
//end

#include<stdio.h>

int LinearSearch(int *a, int length, int ToBeSearched)
{
	int i, pos = 0;
	for(i = 0; i<length; i++)
		if(*(a+i) == ToBeSearched)
		{
			pos = i;
			break;
		}
	return pos;
}

int main()
{
	int pos, length;
	int Arr[] = {1,3,4,5,7,8};
	int search = 3;
	length = sizeof(Arr)/sizeof(int);

	pos = LinearSearch(Arr, length, search);

	if(!pos)
		printf("Nill");
	else
		printf("%d", pos+1);

	getchar();
	return 0;
}
