#include <bits/stdc++.h>
using namespace std;

string bigNumMul(string val1, string val2) {
    string res(val1.size() + val2.size(), '0');
    for (int i = val1.size() - 1; i >= 0; --i) {
        for (int j = val2.size() - 1; j >= 0; --j) {
            int p1 = i + j + 1;
            int p2 = i + j;
            int val = (val1[i] - '0') * (val2[j] - '0') + res[p1] - '0';
            res[p1] = val % 10 + '0';
            res[p2] += val / 10;
        }
    }
    int idx = 0;
    while (idx < res.size() && res[idx] == '0') {
        idx++;
    }
    return res.substr(idx, res.size() - idx);
}

int main() {
    cout << bigNumMul("12", "120");
    return 0;
}