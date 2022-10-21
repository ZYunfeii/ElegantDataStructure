#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void bubble_sort(int A[], int N) {
	for (int i = N - 1; i > 1; --i) { // ע���Ƿ�������
		for (int j = 0; j < i; ++j) {
			if (A[j] > A[j + 1]) swap(A[j], A[j + 1]);
		}
	}
}

int main(int argc, char** argv) {
	int A[] = { 2, 5, 1, 0, 3 };
	int N = sizeof(A) / sizeof(A[0]);
	bubble_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}