//#include <iostream>
//
//using namespace std;
//
//void insert_sort(int A[], int N) {
//	int tmp; // 哨兵
//	int j;
//	for (int i = 1; i < N; ++i) {
//		if (A[i] < A[i - 1]) {
//			tmp = A[i];
//			for (j = i - 1; A[j] > tmp; --j) { // 这个循环就是移动牌的过程，把大于A[i]的前面已经排好的牌往后移动一格（会覆盖A[i],但是我们有哨兵记录A[i]）
//				A[j + 1] = A[j];
//			}
//			A[j + 1] = tmp;
//		}
//	}
//}
//
//int main(int argc, char** argv) {
//	int A[] = { 5,4,3,6 };
//	int N = sizeof(A) / sizeof(A[0]);
//	insert_sort(A, N);
//	for (int i = 0; i < N; ++i) {
//		cout << A[i] << " ";
//	}
//	return 0;
//}