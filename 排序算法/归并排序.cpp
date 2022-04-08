//#include <iostream>
//using namespace std;
//
//// 归并排序实现 
//void Merge(int A[], int tmpA[], int L, int R, int RightEnd) {
//	// L = 左边起始位置，R = 右边起始位置，RightEnd = 右边终点位置 
//	int LeftEnd = R - 1;   // 左边终点位置 
//	int tmp = L;   //  存放结果的开始位置 
//	int NumElements = RightEnd - L + 1;  // 归并个数 
//	while (L <= LeftEnd && R <= RightEnd) {
//		if (A[L] <= A[R])
//			tmpA[tmp++] = A[L++];
//		else
//			tmpA[tmp++] = A[R++];
//	}
//	// 左边有剩 
//	while (L <= LeftEnd)
//		tmpA[tmp++] = A[L++];
//	// 右边有剩 
//	while (R <= RightEnd)
//		tmpA[tmp++] = A[R++];
//	//  导回结果 
//	for (int i = 0; i < NumElements; i++, RightEnd--)
//		A[RightEnd] = tmpA[RightEnd];
//}
//// 分治 
//void Msort(int A[], int tmpA[], int L, int RightEnd) {
//	// L = 左边起始位置，RightEnd = 右边终点位置 
//	// 如果还有元素 
//	if (L < RightEnd) {
//		int center = (L + RightEnd) / 2;
//		Msort(A, tmpA, L, center);  // 左半边 
//		Msort(A, tmpA, center + 1, RightEnd);  // 右半边
//		Merge(A, tmpA, L, center + 1, RightEnd);  // center+1 是右边起点 
//	}
//}
//
//// 归并排序（递归）
//void Merge_sort(int A[],int N){
//	int * tmpA = new int[N];
//	Msort(A,tmpA,0,N-1);
//	delete[] tmpA;
//}

//int main()
//{
//	int A[] = { 1,2,5,7,10,4,8,9,10 };
//	//int tempA[15];
//	//Merge(A, tempA, 0, 5, 8);
//	Merge_sort(A, 9);
//	for (auto &r : A)
//	{
//		cout << r << endl;
//	}
//	return 0;
//}