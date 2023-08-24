#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    TreeNode(int val) {
        val_ = val;
        left_ = right_ = nullptr;
    }
    int val_;
    TreeNode* left_;
    TreeNode* right_;
};

TreeNode* createTree(deque<string>& deq) {
    if (deq.empty()) return nullptr;
    if (deq.front() == "#") {
        deq.pop_front();
        return nullptr;
    }
    TreeNode* newNode = new TreeNode(stoi(deq.front()));
    deq.pop_front();
    newNode->left_ = createTree(deq);
    newNode->right_ = createTree(deq);
    return newNode;
}

int main() {
  deque<string> deq = {"2", "3", "4", "#", "#", "1", "#", "#", "#"};
  auto tree = createTree(deq);

  return 0;
}