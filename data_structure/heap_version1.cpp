#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template<class T>
class MaxHeap {
private: 
	vector<T> data;
	int pos;       
public:
	MaxHeap(vector<T> src):data(src), pos(src.size() - 1) {
		for (int i = data.size() / 2; i >= 0; --i) {
			heapAdjust(i, data.size() - 1);
		}
	}
	void heapAdjust(int s, int m) {
		if (s == 0 && m == 0) return;               
		int temp, j;
		temp = data[s];
		for (j = s; j <= m; j *= 2) {               
			if (j < m && data[j] < data[j + 1]) ++j; 
			if (temp > data[j]) break;               
			data[s] = data[j];
			s = j;                                  
		}
		data[s] = temp;                              
	}
	T getMaxEle() {
		if (!data.empty()) return data[0];
	}
	T eraseTopAdjust() {                              
		assert(!data.empty());
		T top = data[0];
		swap(data[0], data[pos]);
		pos--;
		heapAdjust(0, pos);
		return top;
	}
	void addEle(T val) {                        
		if (pos < data.size() - 1) {
			data[pos + 1] = val;
			pos++;
		}
		else {
			data.push_back(val);
			pos = data.size() - 1;
		}
		for (int i = pos / 2; i >= 0; --i) {  
			heapAdjust(i, pos);
		}
	}
};


template<class T>
class MinHeap {
private:
	vector<T> data;
	int pos;      

public:
	MinHeap(vector<T> src):data(src), pos(src.size() - 1) {
		for (int i = data.size() / 2; i >= 0; --i) {
			heapAdjust(i, data.size() - 1);
		}
	}
	void heapAdjust(int s, int m) {
		if (s == 0 && m == 0) return;
		int temp, j;
		temp = data[s];
		for (j = s; j <= m; j *= 2) {               
			if (j < m && data[j] > data[j + 1]) ++j; 
			if (temp < data[j]) break;               
			data[s] = data[j];
			s = j;                                   
		}
		data[s] = temp;                             
	}
	T getMinEle() {
		if (!data.empty()) return data[0];
	}
	T eraseTopAdjust() {
		assert(!data.empty());
		T top = data[0];
		swap(data[0], data[pos]);
		pos--;
		heapAdjust(0, pos);
		return top;
	}
	void addEle(T val) {
		if (pos < data.size() - 1) {
			data[pos + 1] = val;
			pos++;
		}
		else {
			data.push_back(val);
			pos = data.size() - 1;
		}
		for (int i = pos / 2; i >= 0; --i) {
			heapAdjust(i, pos);
		}
	}
};

int main() {
	MaxHeap<int> myMaxHeap({ 3,2,5,1,7 });
	cout << myMaxHeap.eraseTopAdjust() << endl;
	cout << myMaxHeap.eraseTopAdjust() << endl;
	cout << myMaxHeap.eraseTopAdjust() << endl;
	myMaxHeap.addEle(9);
	cout << myMaxHeap.eraseTopAdjust() << endl;
	cout << myMaxHeap.eraseTopAdjust() << endl;
	cout << myMaxHeap.eraseTopAdjust() << endl;
	myMaxHeap.addEle(10);
	cout << myMaxHeap.eraseTopAdjust() << endl;

	//MinHeap<int> myMinHeap({ 3,2,5,1,7 });
	//cout << myMinHeap.getMinEle() << endl;
	return 0;
}