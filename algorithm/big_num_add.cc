#include <bits/stdc++.h>
using namespace std;

string bigNumAdd(string val1, string val2) {
    int flag = 0;
    string res = "";
    int p1 = val1.size() - 1, p2 = val2.size() - 1;
    while (p1 >= 0 || p2 >= 0) {
        int t1 = p1 >= 0 ? val1[p1] - '0' : 0;
        int t2 = p2 >= 0 ? val2[p2] - '0' : 0;
        int val = t1 + t2 + flag;
        flag = val / 10;
        val = val % 10;
        res.push_back('0' + val);
        p1--; p2--;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << bigNumAdd("12", "120");
    return 0;
}