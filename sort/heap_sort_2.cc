#include <iostream>

using namespace std;
// 最大堆 排序排出来是从小到大 因为会把大顶堆的头放到尾再调整堆 如此往复就是升序了
void heap_adjust(int arr[], int s, int m) {
	int t = s;
	int temp = arr[s];
	int j;
	for (j = 2 * s + 1; j <= m; j = 2 * j + 1) { // 以s为节点，其左节点为2*s+1,右节点为2*s+2（这里s从0开始）
		if (j < m && arr[j] < arr[j + 1]) {
			++j; // 找到下一层较大节点对应的索引
		}
		if (temp >= arr[j]) break; // 如果根结点比其子节点最大值还大，则不需要调整
		arr[t] = arr[j]; 
		t = j;
	}
	arr[t] = temp; // 最后不能用j的位置，因为j最后会乘以2再加1，超出m
}

void heap_sort(int arr[], int N) {
	// 构建堆
	for (int i = N / 2 - 1; i >= 0; --i) { // N / 2 - 1为有子节点的节点中索引最大的那个
		heap_adjust(arr, i, N - 1); 
	}
	// 排序
	for (int i = N - 1; i >= 0; --i) {  // 把第一个元素和最后一个元素交换，然后对0-N-2元素调整
		swap(arr[0], arr[i]);
		heap_adjust(arr, 0, i - 1);
	}
}

int main() {
	//      7
	//     /  \
	//    1    3
	//   / \  
	//  0   4
	int arr[5] = { 7,1,3,0,4 };


	heap_sort(arr, 5);
	for (int i = 0; i < sizeof arr / sizeof arr[0]; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}