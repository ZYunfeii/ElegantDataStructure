#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

class BTree {
private:
    Node* root;
public:
    BTree(deque<string>& d) {
        root = create(d);
    }

    Node* create(deque<string>& d) {
        if (d.empty()) {
            return nullptr;
        }
        string s = d.front();
        d.pop_front();
        if (s == "#") {
            return nullptr;
        }
        int val = stoi(s);
        Node* node = new Node{val};
        node->left = create(d);
        node->right = create(d);
        return node;
    }
	void preOrder() {
		Node* t = root;
		pre(t);
	}
	void pre(Node* root) {
		if (root == nullptr) {
			return;
		}
		cout << root->val << endl;
		pre(root->left);
		pre(root->right);
	}
	void levelTraversal() {
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; ++i) {
				Node* t = q.front();
				q.pop();
				cout << t->val << endl;
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
		}
	}
};



int main(int argc, char** argv) {
    deque<string> d = {"3", "#", "2", "1", "#", "#", "4", "#", "#"}; // 根据中序遍历结果构造树（这里必须有null的标记）
    BTree b(d);
	b.preOrder();
	b.levelTraversal();
    return 0;
}