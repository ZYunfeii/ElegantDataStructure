#include <iostream>
using namespace std;

void merge(int arr[], int tmp[], int s, int mid, int m) {
	// 把tmp的[s,mid]和[mid+1,m]合并为arr[s,m]
	// 类似于双指针赋值 也像leetcode有序链表合并
	int i, j, k;
	for (k = s, j = mid + 1, i = s; j <= m && i <= mid; ++k) {
		if (tmp[i] < tmp[j]) {
			arr[k] = tmp[i++];
		}
		else {
			arr[k] = tmp[j++];
		}
	}
	// 如果还有剩余
	if (i <= mid) {
		for (int n = 0; n <= mid - i; ++n) {
			arr[k + n] = tmp[i + n];
		}
	}
	if (j <= m) {
		for (int n = 0; n <= m - j; ++n) {
			arr[k + n] = tmp[j + n];
		}
	}
}

void m_sort(int arr[], int tmp[], int s, int m) {
	int t[100];
	if (s == m) {
		tmp[s] = arr[s];
	}
	else {
		int mid = s + (m - s) / 2;
		m_sort(arr, t, s, mid); // 把arr的[s,mid]归并为有序的t[s,mid]
		m_sort(arr, t, mid + 1, m); // 把arr的[mid+1,m]归并为有序的t[mid+1,m]
		merge(tmp, t, s, mid, m); // 把t的[s,mid]和[mid+1,m]合并为tmp[s,m]
	}
}

void merge_sort(int arr[], int N) {
	m_sort(arr, arr, 0, N - 1);
}

int main() {
	int arr[] = { 4,2,4,6,1,3 };
	merge_sort(arr, sizeof arr / sizeof arr[0]);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}