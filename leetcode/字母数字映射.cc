#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
/**
 * 给定一个字母和数字的映射关系，如 1-26 对应a-z，然后输入一个数字型的字符串如“123”，请输出所有可能的字母型字符串，“abc”和“aw”和”lc”。
 * **/
string path;
vector<string> res;

void backtracking(string& s, int start) {
    if (start >= s.size()) {
        res.push_back(path);
        return;
    }
    char c = s[start];
    path.push_back(c - '1' + 'a');
    backtracking(s, start + 1);
    path.pop_back();
    if (start + 1 < s.size()) {
        string tmp = s.substr(start, 2);
        int num = stoi(tmp);
        if (num <= 26) {
            path.push_back(num - 1 + 'a');
            backtracking(s, start + 2);
            path.pop_back();
        }
    }
}

int main() {
    string str = "2435";
    backtracking(str, 0);
    for (auto s : res) {
        cout << s << endl;
    }
    return 0;
}