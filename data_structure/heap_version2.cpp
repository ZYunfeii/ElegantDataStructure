#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> v;
    int curSize;
public:
    MaxHeap(vector<int>& d) {
        v = d;
        curSize = v.size();
        for (int i = curSize / 2 - 1; i >= 0; --i) {
            heapAdjust(i, curSize);
        }
    }
    void heapAdjust(int low, int high) {
        if (low >= high) return;
        int left = 2 * low + 1;
        int right = 2 * low + 2;
        int largest = low;
        if (left < high && v[left] > v[largest]) {
            largest = left;
        }
        if (right < high && v[right] > v[largest]) {
            largest = right;
        }
        if (largest != low) {
            swap(v[low], v[largest]);
            heapAdjust(largest, high);
        }
    }

    void add(int val) {
        if (curSize == v.size()) {
            v.push_back(val);
        } else {
            v[curSize] = val;
        }
        curSize++;
        for (int i = curSize / 2 - 1; i >= 0; --i) {
            heapAdjust(i, curSize);
        }
    }

    void pop() {
        if (curSize == 0) {
            return;
        }
        v[0] = v[curSize - 1];
        curSize--;
        heapAdjust(0, curSize);
    }

    int top() {
        if (curSize == 0) return INT_MIN;
        return v[0];
    }

    bool empty() {
        return curSize == 0;
    }
};

int main() {
    vector<int> v = {5, 3, 1, 2, 7};
    MaxHeap h(v);
    while (!h.empty()) {
        int val = h.top();
        cout << val << endl;
        h.pop();
    }
    return 0;
}