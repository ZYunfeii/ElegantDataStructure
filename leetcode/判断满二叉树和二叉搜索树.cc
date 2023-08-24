#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        if (root == nullptr) return {true, true};
        return {judegBst(root), judgeFullTree(root)};
    }

    bool judegBst(TreeNode* root) {
        vector<int> v;
        dfs(v, root);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] <= v[i - 1]) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<int>& v, TreeNode* root) {
        if (root == nullptr) return;
        dfs(v, root->left);
        v.push_back(root->val);
        dfs(v, root->right);
    }

    bool judgeFullTree(TreeNode* root) {
        struct Entry {
            TreeNode* root;
            int idx;
        };
        queue<Entry> q;
        Entry e{root, 0};
        q.push(e);
        int startIdx = 0;
        while (!q.empty()) {
            int sz = q.size();
            int id = startIdx - 1;
            for (int i = 0; i < sz; ++i) {
                Entry e = q.front();
                q.pop();
                if (e.idx != id + 1) {
                    return false;
                }
                id++;
                if (e.root->left) {
                    q.push(Entry{e.root->left, e.idx * 2 + 1});
                }
                if (e.root->right) {
                    q.push(Entry{e.root->right, e.idx * 2 + 2});
                }
            }
            startIdx = 2 * startIdx + 1;
        }
        return true;
    }
};