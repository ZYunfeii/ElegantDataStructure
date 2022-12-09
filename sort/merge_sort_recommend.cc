#include <iostream>
using namespace std;
// chatGPT给的例程 比较简洁 故推荐
void merge(int arr[], int start, int end) {
    // 左闭右闭
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    merge(arr, start, mid);
    merge(arr, mid + 1, end);
    // 类似后序遍历
    double* tmp = new double[end - start + 1];
    // 类似合并有序链表
    int i = start, j = mid + 1, pos = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[pos++] = arr[i++];
        } else {
            tmp[pos++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[pos++] = arr[i++];
    }
    while (j <= end) {
        tmp[pos++] = arr[j++];
    }
    // 拷贝到原数组
    for (int i = start, j = 0; i <= end; ++i, ++j) {
        arr[i] = tmp[j];
    }
}

void merge_sort(int arr[], int N) { // 统一接口
    merge(arr, 0, N - 1);
}

int main() {
	int arr[] = { 3, 7, 2, 1, 5, 4, 6 };
	merge_sort(arr, sizeof arr / sizeof arr[0]);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}