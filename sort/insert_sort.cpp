#include <iostream>

using namespace std;

void insert_sort(int A[], int N) {
	int tmp; // �ڱ�
	int j;
	for (int i = 1; i < N; ++i) {
		if (A[i] < A[i - 1]) {
			tmp = A[i];
			for (j = i - 1; A[j] > tmp; --j) { // ���ѭ�������ƶ��ƵĹ��̣��Ѵ���A[i]��ǰ���Ѿ��źõ��������ƶ�һ�񣨻Ḳ��A[i],�����������ڱ���¼A[i]��
				A[j + 1] = A[j];
			}
			A[j + 1] = tmp;
		}
	}
}

int main(int argc, char** argv) {
	int A[] = { 5,4,3,6 };
	int N = sizeof(A) / sizeof(A[0]);
	insert_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}