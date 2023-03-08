#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char** argv) {
	int A[] = { 5,4,3,6, 7, 1};
	int N = sizeof(A) / sizeof(A[0]);
	insertionSort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}