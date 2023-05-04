#include <bits/stdc++.h>
using namespace std;
// 题目：凑出target的排列
vector<vector<int>> res;
vector<int> path;

void backtracking(vector<int>& v, int target) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    if (target < 0) return;
    for (int i = 0; i < v.size(); ++i) {
        path.push_back(v[i]);
        backtracking(v, target - v[i]);
        path.pop_back();
    }
}

int main() {
    vector<int> v = {1,2,3,4,5};
    
    backtracking(v, 10);
    for (auto f : res) {
        for (auto n : f) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}