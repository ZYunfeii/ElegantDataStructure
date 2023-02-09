#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/implement-trie-prefix-tree/description/
class Trie {
public:
    vector<Trie*> t;
    bool isEnd;
    Trie() {
        t.resize(26);
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        for (char& c : word) {
            if (node->t[c - 'a'] == nullptr) {
                node->t[c - 'a'] = new Trie;
            }
            node = node->t[c - 'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (auto& c : word) {
            if (node->t[c - 'a'] == nullptr) {
                return false;
            }
            node = node->t[c - 'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto& c : prefix) {
            if (node->t[c - 'a'] == nullptr) {
                return false;
            }
            node = node->t[c - 'a'];
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie;
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    return 0;
}