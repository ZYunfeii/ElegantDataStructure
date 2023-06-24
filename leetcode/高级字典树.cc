#include <bits/stdc++.h>
using namespace std;
/**
 * 描述
字典树又称为前缀树或者Trie树，是处理字符串常用的数据结构。

假设组成所有单词的字符仅是‘a’～‘z’，请实现字典树的结构，并包含以下四个主要的功能。

1. void insert(String word)：添加word，可重复添加；
2. void delete(String word)：删除word，如果word添加过多次，仅删除一次；
3. boolean search(String word)：查询word是否在字典树中出现过(完整的出现过，前缀式不算)；
4. int prefixNumber(String pre)：返回以字符串pre作为前缀的单词数量。

现在给定一个m，表示有m次操作，每次操作都为以上四种操作之一。每次操作会给定一个整数op和一个字符串word，op代表一个操作码，如果op为1，则代表添加word，op为2则代表删除word，op为3则代表查询word是否在字典树中，op为4代表返回以word为前缀的单词数量（数据保证不会删除不存在的word）。
 * 
*/

// 这道题在面阿里数据库的时候也出了，主要比一般的trie题多了个统计前缀单词个数的问题，阿里是把前缀所有单词找到，其实差不多
// 牛客：https://www.nowcoder.com/practice/a55a584bc0ca4a83a272680174be113b?tpId=117&tqId=37818&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=


class Trie {
private:
    vector<Trie*> trie;
    int end = 0;
public:
    Trie() {
        trie.resize(26);
    }
    void insert(string& word) {
        Trie* t = this;
        for (auto c : word) {
            if (t->trie[c - 'a'] == nullptr) {
                t->trie[c - 'a'] = new Trie;
            }
            t = t->trie[c - 'a'];
        }
        t->end++;
    }
    void mdelete(string& word) {
        Trie* t = this;
        for (auto c : word) {
            if (t->trie[c - 'a'] == nullptr) {
                return;
            }
            t = t->trie[c - 'a'];
        }
        if (t->end == 0) return;
        t->end--;
    }
    bool search(string& word) {
        Trie* t = this;
        for (auto c : word) {
            if (t->trie[c - 'a'] == nullptr) {
                return false;
            }
            t = t->trie[c - 'a'];
        }
        return t->end > 0;
    }
private:
    int count;
public:
    int prefixNumber(string& pre) {
        count = 0;
        Trie* t = this;
        for (auto c : pre) {
            if (t->trie[c - 'a'] == nullptr) {
                return 0;
            }
            t = t->trie[c - 'a'];
        }
        count += t->end;
        dfs(t);
        return count;
    }

    void dfs(Trie* t) {
        if (t == nullptr) {
            return;
        }
        for (int i = 0; i < t->trie.size(); ++i) {
            if (t->trie[i] == nullptr) continue;
            count += t->trie[i]->end;
            dfs(t->trie[i]);
        }
    }
};

class Solution {
public:
    /**
     * 
     * @param operators string字符串vector<vector<>> the ops
     * @return string字符串vector
     */
    
    vector<string> trieU(vector<vector<string> >& operators) {
        // write code here
        vector<string> res;
        Trie* t = new Trie;
        for (auto v : operators) {
            string op = v[0];
            string ele = v[1];
            if (op == "1") {
                t->insert(ele);
            } else if (op == "2") {
                t->mdelete(ele);
            } else if (op == "3") {
                if (t->search(ele)) {
                    res.push_back("YES");
                } else {
                    res.push_back("NO");
                }
            } else if (op == "4") {
                res.push_back(to_string(t->prefixNumber(ele)));
            }
        }
        return res;
    }

};

int main() {
    Solution sol;
    vector<vector<string>> op = {{"1","qwer"},{"1","qwe"},{"3","qwer"},{"4","q"},{"2","qwer"},{"3","qwer"},{"4","q"}};
    auto v = sol.trieU(op);
    for (auto s : v) {
        cout << s << endl;
    }
    return 0;
}
