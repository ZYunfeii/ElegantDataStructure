#include <bits/stdc++.h>
using namespace std;
/*
题目描述
给定一个乱序的栈，设计算法将其升序排列。

ps: 允许额外使用一个栈来辅助操作 

输入
[4, 2, 1, 3]
输出
[1, 2, 3, 4]

https://mp.weixin.qq.com/s/g_AqwsSEUwlRSevnStPkEA
*/

int main() {

    stack<int> stk;
    stk.push(4);
    stk.push(2);
    stk.push(1);
    stk.push(3);

    stack<int> tmp;
    int t;
    while (!stk.empty()) {
        if (tmp.empty() || stk.top() >= tmp.top()) {
            tmp.push(stk.top());
            stk.pop();
            continue;
        }
        if (stk.top() < tmp.top()) {
            t = stk.top();
            stk.pop();
            while (!tmp.empty() && tmp.top() > t) {
                stk.push(tmp.top());
                tmp.pop();
            }
            tmp.push(t);
        } 
    }

    while (!tmp.empty()) {
        cout << tmp.top() << endl;
        tmp.pop();
    }
    return 0;
}