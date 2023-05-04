#include <bits/stdc++.h>
using namespace std;

string bigNumSub(string a, string b) {
    auto f = [](string& a, string& b)->bool{
        if (a.size() == b.size()) return a < b;
        else return a.size() < b.size();
    };
    int negative = false;
    if (f(a, b)) {
        negative = true;
        swap(a, b);
    }
    int flag = 0;
    string res;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0) {
        int val1 = i >= 0 ? a[i] - '0' : 0;
        int val2 = j >= 0 ? b[j] - '0' : 0;
        int c = (val1 - val2 - flag + 10) % 10;
        res += '0' + c;
        flag = val1 - val2 - flag < 0 ? 1 : 0;
        i--; j--;
    }
    if (negative) {
        res.push_back('-');
    }
    reverse(res.begin(), res.end());
    i = 0;
    for (; i < res.size() - 1; ++i) {
        if (res[i] != '0') {
            break;
        }
    }
    
    return res.substr(i);
}

int main() {
    string a = "123";
    string b = "2345";
    cout << bigNumSub(a, b);
    return 0;
}