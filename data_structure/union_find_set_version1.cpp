#include <iostream>
#include <vector>
using namespace std;
// https://leetcode-cn.com/problems/evaluate-division/comments/
class UnionFind {
private:
	vector<int> parent_;
	vector<double> weight_;
public:
	UnionFind(int n) {
		parent_.resize(n);
		weight_.resize(n);
		for (int i = 0; i < n; ++i) {
			parent_[i] = i;  
			weight_[i] = 1.0;
		}
	}
	
	void myunion(int x, int y, double value) {
		int rootX = find(x); 
		int rootY = find(y); 
		if (rootX == rootY) return;
		parent_[rootX] = rootY;
		weight_[rootX] = value * weight_[y] / weight_[x];
	}
	
	int find(int x) {
		if (x != parent_[x]) {
			int origin = parent_[x];
			parent_[x] = find(parent_[x]);
			weight_[x] *= weight_[origin];
		}
		return parent_[x];
	}
	
	double isConnected(int x, int y) {
		int rootX = find(x); 
		int rootY = find(y); 
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
	union_find.myunion(1, 2, 0.5); 
	union_find.myunion(3, 4, 2);   
	union_find.myunion(1, 3, 5);  
	/*
		1------->2-----?----->4
		��                  ��
		3--------------------
	*/
	cout << union_find.isConnected(2, 4) << endl; // ����20
	cout << union_find.isConnected(1, 4) << endl; // ����10

	return 0;
}