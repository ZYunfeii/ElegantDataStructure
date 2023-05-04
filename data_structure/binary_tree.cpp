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
    BTree(deque<string> d) {
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
	void preOrderRecur() {
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
	void preOrderNonRecur() {
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty()) {
			Node* n = stk.top();
			stk.pop();
			if (n->right) stk.push(n->right);
			if (n->left) stk.push(n->left);
			cout << n->val << endl;
		}
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
	// 递归中序
	void inOrderRecur() {
		in(root);
	}
	void in(Node* root) {
		if (!root) return;
		in(root->left);
		cout << root->val << endl;
		in(root->right);
	}
	void inOrderNonRecur() {
		Node* cur = root;
		stack<Node*> stk;
		while (!stk.empty()) {
			while (cur) {
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			cout << cur->val << endl;
			cur = cur->right;
		}
	}

	void postOrderNonRecur() {
		stack<Node*> stk;
		stk.push(root);
		vector<int> res;
		while (!stk.empty()) {
			Node* n = stk.top();
			stk.pop();
			if (n->left) stk.push(n->left);
			if (n->right) stk.push(n->right);
			res.push_back(n->val);
		}
		reverse(res.begin(), res.end());
		for_each(res.begin(), res.end(), [](int& v){
			cout << v << endl;
		});
	}
};



int main(int argc, char** argv) {
    deque<string> d = {"3", "#", "2", "1", "#", "#", "4", "#", "#"}; // 根据先序遍历结果构造树（这里必须有null的标记）
    BTree b(d);
	b.preOrderRecur();
	cout << " ---------- " << endl;
	b.levelTraversal();
	cout << " ---------- " << endl;
	b.inOrderRecur();
	cout << " ---------- " << endl;
	b.preOrderNonRecur();
	cout << " ---------- " << endl;
	b.postOrderNonRecur();
	cout << " ---------- " << endl;
	b.inOrderNonRecur(); 
    return 0;
}