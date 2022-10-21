#include <iostream>
using namespace std;

void sort(int*, int, int);
int getpor(int*, int, int);
void swap(int*, int, int);


void QSort(int a[],int N) {
	sort(a, 0, N-1);
}

void sort(int a[], int low, int high) {
	int por;
	if (low < high) {
		int m = low + (high - low) / 2;
		if (a[high] < a[low]) swap(a, low, high);
		if (a[m] > a[high]) swap(a, m, high);
		if (a[m] > a[low]) swap(a, low, m);
	}
	if (low < high) {
		por = getpor(a, low, high);
		sort(a, low, por - 1);
		sort(a, por + 1, high);
	}
}

int getpor(int a[],int low,int high) {
	int por = a[low];
	while (low < high) {
		while (low<high && a[high]>=por) high--;
		swap(a, low, high);
		while (low < high && a[low] <= por) low++;
		swap(a, low, high);
	}
	return low;
}

void swap(int a[],int low,int high) {
	int t = a[low];
	a[low] = a[high];
	a[high] = t;
}

int main(int argc, char *argv[]) {
	int a[] = { 3, 7, 2, 1, 5, 4, 6 };
	QSort(a, 7);
	for (auto&i : a) {
		cout << i << endl;
	}
	return 0;
}