#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void select_sort(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (A[i] > A[j]) swap(A[i], A[j]);
		}
	}
}

int main(int argc, char** argv) {
	int A[] = { 3,2,1,6 };
	int N = sizeof(A) / sizeof(A[0]);
	select_sort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return  0;
}