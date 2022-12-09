#include <iostream>
using namespace std;
// chatGPT给的代码
void heap_adjust(int arr[], int i, int N) {
    // 调整[i, N)为堆 更通俗点 把arr[i]换到子树（也可能不动）合适的位置，因为arr[i]可能比较小（针对大顶堆）
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < N && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heap_adjust(arr, largest, N);
    }
}

void heap_sort(int arr[], int N) {
    for (int i = N / 2; i >= 0; --i) {
        heap_adjust(arr, i, N);
    }
    for (int i = N - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        // 每次交换后，arr[0]的位置大概率不对，需要调整它到合适的位置
        heap_adjust(arr, 0, i);
    }
}

int main() {
	int arr[] = { 3, 7, 2, 1, 5, 5, 4, 6 };
	heap_sort(arr, sizeof arr / sizeof arr[0]);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}