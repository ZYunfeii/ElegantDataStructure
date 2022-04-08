//#include<iostream>
//using namespace std;
//
//void sort(int*, int, int);
//int getpor(int*, int, int);
//void swap(int*, int, int);
//
//
//// 《大话数据结构》 快速排序算法实现
//void QSort(int a[],int N) {
//	sort(a, 0, N-1);
//}
//
//void sort(int a[], int low, int high) {
//	int por;
//	if (low < high) {
//		int m = low + (high - low) / 2;
//		if (a[high] < a[low]) swap(a, low, high);
//		if (a[m] > a[high]) swap(a, m, high);
//		if (a[m] > a[low]) swap(a, low, m);
//	}
//	if (low < high) {
//		por = getpor(a, low, high);
//		sort(a, low, por - 1);
//		sort(a, por + 1, high);
//	}
//}
//
//int getpor(int a[],int low,int high) {
//	int por = a[low];
//	while (low < high) {
//		while (low<high && a[high]>=por) high--;
//		swap(a, low, high);
//		while (low < high && a[low] <= por) low++;
//		swap(a, low, high);
//	}
//	return low;
//}
//
//void swap(int a[],int low,int high) {
//	int t = a[low];
//	a[low] = a[high];
//	a[high] = t;
//}

//int main(int argc, char *argv[]) {
//	int a[] = {5,2,3,1};
//	QSort(a, 4);
//	for (auto&i : a) {
//		cout << i << endl;
//	}
//	return 0;
//}