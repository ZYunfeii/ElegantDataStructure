#include <iostream>
using namespace std;


void Merge(int A[], int tmpA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;  
	int tmp = L;  
	int NumElements = RightEnd - L + 1;  
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			tmpA[tmp++] = A[L++];
		else
			tmpA[tmp++] = A[R++];
	}

	while (L <= LeftEnd)
		tmpA[tmp++] = A[L++];

	while (R <= RightEnd)
		tmpA[tmp++] = A[R++];

	for (int i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = tmpA[RightEnd];
}

void Msort(int A[], int tmpA[], int L, int RightEnd) {
	if (L < RightEnd) {
		int center = (L + RightEnd) / 2;
		Msort(A, tmpA, L, center);  
		Msort(A, tmpA, center + 1, RightEnd); 
		Merge(A, tmpA, L, center + 1, RightEnd);  
	}
}

void Merge_sort(int A[],int N){
	int * tmpA = new int[N];
	Msort(A,tmpA,0,N-1);
	delete[] tmpA;
}

int main()
{
	int A[] = { 1,2,5,7,10,4,8,9,10 };
	//int tempA[15];
	//Merge(A, tempA, 0, 5, 8);
	Merge_sort(A, 9);
	for (auto &r : A)
	{
		cout << r << endl;
	}
	return 0;
}