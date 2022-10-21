#include <iostream>
using namespace std;

int get_por(int arr[], int low, int high) { // 这个函数不仅获得了中枢轴，还带部分有序（中枢轴左侧小于中枢轴，右侧大于）
	// 中枢轴的值默认为arr的第一个元素
	while (low < high && arr[high] > arr[low]) high--;
	swap(arr[low], arr[high]); // 交换后，此时arr[high]的位置为“假设”中枢轴位置
	while (low < high && arr[low] < arr[high]) low++;
	swap(arr[low], arr[high]); // 交换后，此时arr[low]的位置为“真实”中枢轴位置
	return low;
}

void sort(int arr[], int low, int high) {
	if (low < high) {
		int t = get_por(arr, low, high);
		sort(arr, low, t);
		sort(arr, t + 1, high);
	}
}

void q_sort(int arr[], int N) {
	sort(arr, 0, N - 1);
}

int main() {
	int arr[] = { 7,2,3,4,5 };
	q_sort(arr, sizeof arr / sizeof arr[0]);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}