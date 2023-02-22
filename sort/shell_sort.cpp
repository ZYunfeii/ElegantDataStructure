#include <iostream>
using namespace std;

/*
这里的希尔排序使用的是“缩小增量排序”方法。
它首先将数组按一定间隔（增量）分成几个子序列，对每个子序列进行插入排序。然后逐步缩小增量，重复上述过程，直到增量为1，最终完成排序。
*/

void shellSort(int arr[], int n) {
    // 计算增量序列
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}


int main(int argc, char** argv) {
	int A[] = { 3,4,1,5 };
	int N = sizeof(A) / sizeof(A[0]);
	shellSort(A, N);
	for (int i = 0; i < N; ++i) {
		cout << A[i] << " ";
	}
	return 0;
}