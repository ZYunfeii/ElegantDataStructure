#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string txt, string pat) {
        vector<int> next(pat.size(), 0);
        getNext(pat, next);
        int j = 0;
        for (int i = 0; i < txt.size(); ++i) {
            while (j > 0 && txt[i] != pat[j]) { // mark: while!
                j = next[j - 1];
            }
            if (txt[i] == pat[j]) {
                ++j;
            }
            if (j == pat.size()) {
                return i - j + 1;
            }
        }
        return -1;
    }

    void getNext(string& pat, vector<int>& next) { // 使用不减一的前缀数组
        int j = 0;
        // next[0] = 0;
        for (int i = 1; i < pat.size(); ++i) {
            while (j > 0 && pat[i] != pat[j]) { // mark: while ！
                j = next[j - 1];
            }
            if (pat[j] == pat[i]) {
                ++j;
            }
            next[i] = j;
        }
    }    
};

int main(int argc, char** argv) {
    Solution* sol = new Solution;
    string txt = "leetcode";
    string pat = "tco";
    fprintf(stdout, "begin index is: %d\n", sol->strStr(txt, pat));

    return 0;
}