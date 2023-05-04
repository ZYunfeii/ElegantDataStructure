#include <iostream>
using namespace std;
// 从小到大
int get_por(int arr[], int low, int high) { // 这个函数不仅获得了中枢轴，还带部分有序（中枢轴左侧小于中枢轴，右侧大于）
	// 中枢轴的值默认为arr的第一个元素
    int por = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= por) high--;
		swap(arr[low], arr[high]);
		while (low < high && arr[low] <= por) low++;
		swap(arr[low], arr[high]);
	}
	return low;
}
// 从大到小
// int get_por(int arr[], int low, int high) { // 这个函数不仅获得了中枢轴，还带部分有序（中枢轴左侧小于中枢轴，右侧大于）
// 	// 中枢轴的值默认为arr的第一个元素
//     int por = arr[low];
// 	while (low < high) {
// 		while (low < high && arr[high] <= por) high--;
// 		swap(arr[low], arr[high]);
// 		while (low < high && arr[low] >= por) low++;
// 		swap(arr[low], arr[high]);
// 	}
// 	return low;
// }

void sort(int arr[], int low, int high) {
	if (low < high) {
		int t = get_por(arr, low, high);
		sort(arr, low, t - 1);
		sort(arr, t + 1, high);
	}
}

void q_sort(int arr[], int N) {
	sort(arr, 0, N - 1);
}

int main() {
	int arr[] = { 3, 7, 2, 1, 5, 4, 6 };
	q_sort(arr, sizeof arr / sizeof arr[0]);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}