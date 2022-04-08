//#include <iostream>
//using namespace std;
//void swap(int &a, int &b) {
//	int t = a;
//	a = b;
//	b = t;
//}
//// 插入排序 
//void Insertion_sort(int A[], int N) {
//	for (int p = 1; p < N; p++) {
//		int tmp = A[p];   // 取出一个数 
//		int j = p;
//		for (; tmp < A[j - 1] && j > 0; j--)  // 找到这个数适合的位置 
//			A[j] = A[j - 1];  // “腾“出位置 
//		A[j] = tmp;  //  把合适大小的数放入 
//	}
//}
//// 获得主元 
//int GetPivot(int A[],int L, int R) {
//	int center = (L + R) / 2;
//	// 排序  A[L] < A[center] < A[R] 
//	if (A[R] < A[center])
//		swap(A[R], A[center]);
//	if (A[R] < A[L])
//		swap(A[R], A[L]);
//	if (A[center] < A[L])
//		swap(A[L], A[center]);
//	// 把主元藏在 R-1 
//	swap(A[center], A[R - 1]);
//	return A[R - 1];
//}
//void Quicksort(int A[],int Left, int Right) {
//	int cutoff = 100;
//	if (cutoff <= Right - Left) {
//		int Pivot = GetPivot(A,Left, Right);
//		int i = Left;
//		int j = Right - 1;
//		while (1) {
//			while (A[++i] < Pivot);
//			while (A[--j] > Pivot);
//			if (i < j)
//				swap(A[i], A[j]);
//			else
//				break;
//		}
//		swap(A[i], A[Right - 1]);
//		Quicksort(A,Left, i - 1);
//		Quicksort(A,i + 1, Right);
//	}
//	else
//		Insertion_sort(A + Left, Right - Left + 1);
//}
//
//void Quick_sort(int A[],int N) {
//	Quicksort(A,0, N - 1);
//}

/*int main()
{
	int A[] = { 6,2,1,3,5,7,8,10 };
	Quick_sort(A, 8);
	for (auto i : A)
	{
		cout << i << endl;
	}

	return 0;
}*/