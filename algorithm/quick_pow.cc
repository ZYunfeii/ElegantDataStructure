#include <bits/stdc++.h>
using namespace std;

int quickPow(int x, int n) {
    // x^n
    int res = 1;
    int t = x;
    while (n) {
        res *= n & 1 ? t : 1;
        t *= t;
        n >>= 1;
    }
    return res;
}

int main() {
    cout << quickPow(5, 3);
    return 0;
}