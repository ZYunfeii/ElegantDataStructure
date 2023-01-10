#include <iostream>
#include <vector>
using namespace std;
// 并查集使用的一个例子，以leetcode为例：https://leetcode-cn.com/problems/evaluate-division/comments/
class UnionFind {
private:
	vector<int> parent_;
	vector<double> weight_;
public:
	UnionFind(int n) {
		parent_.resize(n);
		weight_.resize(n);
		for (int i = 0; i < n; ++i) {
			parent_[i] = i;  // 一开始都是指向自己
			weight_[i] = 1.0;
		}
	}
	// 并查集的合并
	void myunion(int x, int y, double value) {
		int rootX = find(x); // 只要调用find就会压缩并查集
		int rootY = find(y); // 只要调用find就会压缩并查集
		if (rootX == rootY) return;
		parent_[rootX] = rootY;
		weight_[rootX] = value * weight_[y] / weight_[x];
	}
	// 并查集的路径压缩
	int find(int x) {
		if (x != parent_[x]) {
			int origin = parent_[x];
			parent_[x] = find(parent_[x]);
			weight_[x] *= weight_[origin];
		}
		return parent_[x];
	}
	// 并查集查找是否连通 并返回边权
	double isConnected(int x, int y) {
		int rootX = find(x); // 只要调用find就会压缩并查集
		int rootY = find(y); // 只要调用find就会压缩并查集
		if (rootX == rootY) {
			return weight_[x] / weight_[y];
		}
		else {
			return -1.0;
		}
	}
};

int main() {
	UnionFind union_find(10);
	union_find.myunion(1, 2, 0.5); // 1指向2 权0.5
	union_find.myunion(3, 4, 2);   // 3指向4 权2
	union_find.myunion(1, 3, 5);   // 1指向3 权5 
	/*
		1------->2-----?----->4
		↓                  ↑
		3--------------------
	*/
	cout << union_find.isConnected(2, 4) << endl; // 返回20
	cout << union_find.isConnected(1, 4) << endl; // 返回10

	return 0;
}