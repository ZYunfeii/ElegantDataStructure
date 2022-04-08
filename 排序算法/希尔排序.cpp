#include <iostream>

using namespace std;

void shell_sort(int A[], int N) {
	int tmp; // 哨兵
	int increment = N; 
	int j;
	do {
		increment = increment / 3 + 1; // 增量怎么变化的机制其实是不影响希尔排序的正确性的，但是可能会影响性能
		for (int i = increment; i < N; ++i) {
			if (A[i] < A[i - increment]) {
				tmp = A[i]; // 用哨兵存储A[i]
				for (j = i - increment; j >= 0 && A[j] > tmp; j -= increment) {
					A[j + increment] = A[j]; // 这里的逻辑挺像插入排序的，只是插入排序increment=1，事实上最后一次希尔排序就是插入排序
				}
				A[j + increment] = tmp; // 这句别忘了，哨兵存储的是A[i](为什么要存储，因为在交换的过程中会让后面的数覆盖这个数，最后j停在待插入tmp位置的前increment处)
			}
		}
	} while (increment > 1); // 相当于increment = 1时终止
}

int main(int argc, char** argv) {
	int A[] = { 3,4,1,5 };
	int N = sizeof(A) / sizeof(A[0]);
	shell_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}