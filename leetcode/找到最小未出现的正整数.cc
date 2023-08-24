#include <bits/stdc++.h>
using namespace std;

// 用O(n)的时间和O(1)的空间，找到给定数组中没出现过的最小正整数
// 解法：原地hash

int solver(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] <= 0) {
            v[i] = v.size() + 1;
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        int num = abs(v[i] - 1);
        if (num < v.size()) {
            v[num] = -v[num];
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            return i + 1; 
        }
    }
    return v.size() + 1;
}

int main() {
    vector<int> v = {-2 , 9, 1, 2, 0, 3, 4};
    cout << solver(v);
    return 0;
}