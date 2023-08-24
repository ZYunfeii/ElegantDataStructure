#include <bits/stdc++.h>
using namespace std;

/**
 * 给一个数n，一个数组A，返回由A中元素组成的小于n的最大数
如n=23121，A={2,4,9| 返回22999
n=23121 A={9} 返回9999
n=23333 A={2,3} 返回23332
n=2222 A={2} 返回222
n=2 A={2} 无解
*/

void backtracking(vector<int>& v, vector<int>& numV, vector<int>& path, vector<int>& res, int start, bool flag) {
    if (start >= numV.size()) {
        int sum = 0;
        for (int i = 0; i < path.size(); ++i) {
            sum = sum * 10 + path[i];
        }
        res.push_back(sum);
        return;
    }
    if (flag == false && start < path.size()) {
        path[start] = 0;
        backtracking(v, numV, path, res, start + 1, true);
    }
    for (int i = 0; i < v.size(); ++i) {
        bool tag = false;
        for (int j = 0; j < start; ++j) {
            if (path[j] < numV[j]) {
                tag = true;
                break;
            }
        }
        if (tag == true || v[i] <= numV[start]) {
            path[start] = v[i];
            backtracking(v, numV, path, res, start + 1, true);
        } 
    }
}

int solver(vector<int>& v, int n) {
    vector<int> res;
    vector<int> numV;
    
    int t = n;
    while (n) {
        numV.push_back(n % 10);
        n /= 10;
    }
    vector<int> path(numV.size());
    reverse(numV.begin(), numV.end());
    bool flag = numV.size() == 1 ? true : false;
    backtracking(v, numV, path, res, 0, flag);
    int r = -1;
    for (int i = 0; i < res.size(); ++i) {
        if (res[i] > r && res[i] < t) {
            r = res[i];
        }
    }
    return r;
}

int main() {
    vector<int> v = {2, 4, 9};
    int n = 23121;
    cout << solver(v, n) << endl;

    v = {9};
    n = 23121;
    cout << solver(v, n) << endl;

    v = {2, 3};
    n = 23333;
    cout << solver(v, n) << endl;

    v = {2};
    n = 2222;
    cout << solver(v, n) << endl;

    v = {2};
    n = 2;
    cout << solver(v, n) << endl;
    return 0;
}