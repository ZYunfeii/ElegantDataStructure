#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// ���Ǿ����������ʵ���ȫ��������ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶ѣ�
// ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ����ΪС����
// �����Ѹ��Ӷ�O(n) �ؽ��Ѹ��Ӷ�O(nlogn)

// ����
template<class T>
class MaxHeap {
private: 
	vector<T> data;
	int pos;       // ��¼�ѵ���ֹ���� ��û��eraseԪ��ʱ pos == data.size() - 1
public:
	MaxHeap(vector<T> src):data(src), pos(src.size() - 1) {
		for (int i = data.size() / 2; i >= 0; --i) {
			heapAdjust(i, data.size() - 1);
		}
	}
	void heapAdjust(int s, int m) {
		if (s == 0 && m == 0) return;               // ��Щ����1��Ϊroot�������0�Ļ�Ҫ�������������������for�л�һֱѭ���˲�����
		int temp, j;
		temp = data[s];
		for (j = s; j <= m; j *= 2) {                // ������ȫ��������һ���ڵ�i����ڵ���ҽڵ�Ϊ2i��2i+1
			if (j < m && data[j] < data[j + 1]) ++j; // �ҵ����Һ�����ֵ������� j < m�Ǳ�֤j+1�ж���
			if (temp > data[j]) break;               // ���������Ѿ��Ǵ󶥶��ˣ����temp���������Һ��ӵ����ֵ����ô���ý���֮��ı�����
			data[s] = data[j];
			s = j;                                   // ׼��������Ľڵ�ĺ��ӽڵ�
		}
		data[s] = temp;                              // ���һ��ʼ�Ľڵ���뵽�����ʡ���λ��
	}
	T getMaxEle() {
		if (!data.empty()) return data[0];
	}
	T eraseTopAdjust() {                              // ���ظ��ڵ��ɾ�������µ�����
		assert(!data.empty());
		T top = data[0];
		swap(data[0], data[pos]);
		pos--;
		heapAdjust(0, pos);
		return top;
	}
	void addEle(T val) {                        // ����ڵ㵽�� ��������ĩβ
		if (pos < data.size() - 1) {
			data[pos + 1] = val;
			pos++;
		}
		else {
			data.push_back(val);
			pos = data.size() - 1;
		}
		for (int i = pos / 2; i >= 0; --i) {  // ���µ�����
			heapAdjust(i, pos);
		}
	}
};

// ��С��
template<class T>
class MinHeap {
private:
	vector<T> data;
	int pos;       // ��¼�ѵ���ֹ���� ��û��eraseԪ��ʱ pos == data.size() - 1

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
		for (j = s; j <= m; j *= 2) {                // ������ȫ��������һ���ڵ�i����ڵ���ҽڵ�Ϊ2i��2i+1
			if (j < m && data[j] > data[j + 1]) ++j; // �ҵ����Һ�����ֵС������ j < m�Ǳ�֤j+1�ж���
			if (temp < data[j]) break;               // ���������Ѿ���С�����ˣ����temp��С�����Һ��ӵ����ֵ����ô���ý���֮��ı�����
			data[s] = data[j];
			s = j;                                   // ׼������С�Ľڵ�ĺ��ӽڵ�
		}
		data[s] = temp;                              // ���һ��ʼ�Ľڵ���뵽�����ʡ���λ��
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