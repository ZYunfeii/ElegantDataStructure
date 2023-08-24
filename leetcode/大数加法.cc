#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int sz = max(n, m);
    string res(sz + 1, '0');
    int i = n - 1, j = m - 1;
    int flag = 0;
    int pos = res.size() - 1;
    while (i >= 0 || j >= 0 || flag) {
        int val1 = i >= 0 ? s1[i] - '0' : 0;
        int val2 = j >= 0 ? s2[j] - '0' : 0;
        int val = val1 + val2 + flag;
        if (val >= 10) {
            flag = 1;
        } else {
            flag = 0;
        }
        val = val % 10;
        res[pos--] = '0' + val;
        i--; j--;
    }
    int p = 0;
    for (; p < res.size(); ++p) {
        if (res[p] != '0') {
            break;
        }
    }
    return res.substr(p);
}

int main() {
    string num1 = "9234";
    string num2 = "1237";
    cout << add(num1, num2);
    return 0;
}