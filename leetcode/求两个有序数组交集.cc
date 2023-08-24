#include <bits/stdc++.h>
using namespace std;
// version1: O(n + m)
vector<int> solver1(const vector<int>& v1, const vector<int>& v2) {
    int ptr1 = 0, ptr2 = 0;
    vector<int> res;
    while (ptr1 < v1.size() && ptr2 < v2.size()) {
        if (v1[ptr1] < v2[ptr2]) {
            ptr1++;
        } else if (v1[ptr1] == v2[ptr2]) {
            res.push_back(v1[ptr1]);
            ptr1++;
            ptr2++;
        } else {
            ptr2++;
        }
    }
    return res;
}
// version 2: 双边二分，O(log(m + n))
vector<int> solver2(vector<int>& v1, vector<int>& v2) {
    int ptr1 = 0, ptr2 = 0;
    vector<int> res;
    auto bSearch = [](vector<int>& v, int left, int right, int target)->int {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] > target) {
                right = mid - 1;
            } else if (v[mid] < target) {
                left = mid + 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    };
    while (ptr1 < v1.size() && ptr2 < v2.size()) {
        if (v1[ptr1] < v2[ptr2]) {
            int idx = bSearch(v1, ptr1 + 1,(int) (v1.size() - 1), v2[ptr2]);
            if (idx == ptr1)  ptr1++;
            else ptr1 = idx;
        } else if (v1[ptr1] == v2[ptr2]) {
            res.push_back(v1[ptr1]);
            ptr1++;
            ptr2++;
        } else {
            int idx = bSearch(v2, ptr2 + 1,(int) (v2.size() - 1), v1[ptr1]);
            if (ptr2 == idx) ptr2++;
            else ptr2 = idx;
        }
    }
    return res;

}

int main() {
    vector<int> v1 = {3, 7, 8, 11, 35};
    vector<int> v2 = {8, 9, 10, 35};
    auto v = solver2(v1, v2);
    for (auto n : v) {
        cout << n << endl;
    } cout << endl;
    return 0;
}