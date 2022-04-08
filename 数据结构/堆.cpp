//#include <iostream>
//#include <vector>
//#include <assert.h>
//using namespace std;
// 
//// 堆是具有下列性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆；
//// 每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆
//// 构建堆复杂度O(n) 重建堆复杂度O(nlogn)
//
//// 最大堆
//template<class T>
//class MaxHeap {
//private: 
//	vector<T> data;
//	int pos;       // 记录堆的终止索引 当没有erase元素时 pos == data.size() - 1
//public:
//	MaxHeap(vector<T> src):data(src), pos(src.size() - 1) {
//		for (int i = data.size() / 2; i >= 0; --i) {
//			heapAdjust(i, data.size() - 1);
//		}
//	}
//	void heapAdjust(int s, int m) {
//		if (s == 0 && m == 0) return;               // 有些书用1作为root，如果用0的话要考虑这种情况，否则在for中会一直循环退不出来
//		int temp, j;
//		temp = data[s];
//		for (j = s; j <= m; j *= 2) {                // 对于完全二叉树，一个节点i的左节点和右节点为2i和2i+1
//			if (j < m && data[j] < data[j + 1]) ++j; // 找到左右孩子中值大的索引 j < m是保证j+1有定义
//			if (temp > data[j]) break;               // 由于子树已经是大顶堆了，如果temp还大于左右孩子的最大值，那么不用进行之后的遍历了
//			data[s] = data[j];
//			s = j;                                   // 准备遍历大的节点的孩子节点
//		}
//		data[s] = temp;                              // 最后将一开始的节点插入到“合适”的位置
//	}
//	T getMaxEle() {
//		if (!data.empty()) return data[0];
//	}
//	T eraseTopAdjust() {                              // 返回根节点后删除并重新调整堆
//		assert(!data.empty());
//		T top = data[0];
//		swap(data[0], data[pos]);
//		pos--;
//		heapAdjust(0, pos);
//		return top;
//	}
//	void addEle(T val) {                        // 加入节点到堆 加在树的末尾
//		if (pos < data.size() - 1) {
//			data[pos + 1] = val;
//			pos++;
//		}
//		else {
//			data.push_back(val);
//			pos = data.size() - 1;
//		}
//		for (int i = pos / 2; i >= 0; --i) {  // 重新调整堆
//			heapAdjust(i, pos);
//		}
//	}
//};
//
//// 最小堆
//template<class T>
//class MinHeap {
//private:
//	vector<T> data;
//	int pos;       // 记录堆的终止索引 当没有erase元素时 pos == data.size() - 1
//
//public:
//	MinHeap(vector<T> src):data(src), pos(src.size() - 1) {
//		for (int i = data.size() / 2; i >= 0; --i) {
//			heapAdjust(i, data.size() - 1);
//		}
//	}
//	void heapAdjust(int s, int m) {
//		if (s == 0 && m == 0) return;
//		int temp, j;
//		temp = data[s];
//		for (j = s; j <= m; j *= 2) {                // 对于完全二叉树，一个节点i的左节点和右节点为2i和2i+1
//			if (j < m && data[j] > data[j + 1]) ++j; // 找到左右孩子中值小的索引 j < m是保证j+1有定义
//			if (temp < data[j]) break;               // 由于子树已经是小顶堆了，如果temp还小于左右孩子的最大值，那么不用进行之后的遍历了
//			data[s] = data[j];
//			s = j;                                   // 准备遍历小的节点的孩子节点
//		}
//		data[s] = temp;                              // 最后将一开始的节点插入到“合适”的位置
//	}
//	T getMinEle() {
//		if (!data.empty()) return data[0];
//	}
//	T eraseTopAdjust() {
//		assert(!data.empty());
//		T top = data[0];
//		swap(data[0], data[pos]);
//		pos--;
//		heapAdjust(0, pos);
//		return top;
//	}
//	void addEle(T val) {
//		if (pos < data.size() - 1) {
//			data[pos + 1] = val;
//			pos++;
//		}
//		else {
//			data.push_back(val);
//			pos = data.size() - 1;
//		}
//		for (int i = pos / 2; i >= 0; --i) {
//			heapAdjust(i, pos);
//		}
//	}
//};
//
//int main() {
//	MaxHeap<int> myMaxHeap({ 3,2,5,1,7 });
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	myMaxHeap.addEle(9);
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//	myMaxHeap.addEle(10);
//	cout << myMaxHeap.eraseTopAdjust() << endl;
//
//	//MinHeap<int> myMinHeap({ 3,2,5,1,7 });
//	//cout << myMinHeap.getMinEle() << endl;
//	return 0;
//}