#include <bits/stdc++.h>
using namespace std;
// 将www.baidu.com转化成www.udiab.moc

string solver(string s) {
    string t;
    string res;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '.') {
            t += s[i];
            continue;
        }
        reverse(t.begin(), t.end());
        res += t + ".";
        t.clear();
    }
    reverse(t.begin(), t.end());
    res += t;
    return res;
}

int main() {
    cout << solver("www.baidu.com");
    return 0;
}