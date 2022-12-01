#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����������ʵ��
typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	int data;
	node(int src) :data(src) {
		lchild = nullptr;
		rchild = nullptr;
	}
}BiTreeNode, *BiTree;

class BST {
private:
	BiTree tree;
public:

	BST() {
		tree = nullptr;
	}

	// BST �������
	void insert(BiTreeNode node) {
		insertRecur(node, tree);
	}

	void insertRecur(BiTreeNode node, BiTree& root) {
		if (root == nullptr){
			root = new BiTreeNode(node.data); // ������root = &node, node�������Ǹ���ʱ���� 
			return;
		}

		if (node.data < root->data) {
			insertRecur(node, root->lchild);
		}
		else {
			insertRecur(node, root->rchild);
		}

	}

	// ɾ����������������ݽṹ��p352
	void erase(int key) {
		if (deleteBST(tree, key)) {
			cout << "ɾ���ɹ�!" << endl;
		}
		else {
			cout << "ɾ��ʧ��!" << endl;
		}
	}

	bool deleteBST(BiTree& root, int key) {
		// ����DFS�ҵ�Ҫɾ���Ľڵ�
		if (root == nullptr) return false;
		else {
			if (key == root->data) return deleteNode(root); 
			else if (key < root->data) return deleteBST(root->lchild, key);
			else return deleteBST(root->rchild, key);
		}
	}

	bool deleteNode(BiTree& root) {
		BiTree tmp;
		if (root->rchild == nullptr) { // û�������������ֱ�Ӱ�������������
			tmp = root;
			root = root->lchild;
			delete tmp;
		}
		else if (root->lchild == nullptr) { // û�������������ֱ�Ӱ�������������
			tmp = root;
			root = root->rchild;
			delete tmp;
		}
		else {                         // ��������������������
			BiTree q = root;
			BiTree s = root->lchild;
			// �������������ҽڵ�s����Ϊ����ڵ�һ���������������Ľڵ�ͬʱһ���������������нڵ�ֵС�������������ɾ���ڵ�
			// q��s��ǰ���ڵ�
			while (s->rchild) { 
				q = s;
				s = s->rchild;
			}
			root->data = s->data;
			if (q != root) {
				q->rchild = s->lchild;
			}
			else {
				q->lchild = s->lchild;  // q == root������Ǵ�ɾ���ڵ�����ӽڵ�û������������ʱֱ�Ӱ����ӽڵ��������������
			}
			delete s;
		}
		return true;
	}

	// BST���Ҳ���O(logn)
	BiTree search(int key) {
		BiTree res = searchDfs(tree, key);
		if (res == nullptr) {
			cout << "û�ж�Ӧ�ڵ�!" << endl;
			return nullptr;
		}
		else return res;
	}

	BiTree searchDfs(BiTree& root, int key) {
		if (root == nullptr) return nullptr;
		if (key < root->data) return searchDfs(root->lchild, key);
		else if(key > root->data) return searchDfs(root->rchild, key);
		else return root;
	}
	
	void preOrderTraverse() {  // �������
		recurDfsPre(tree);
	}
	void recurDfsPre(BiTree& tree) {
		if (tree == nullptr) return;
		cout << tree->data << endl;
		recurDfsPre(tree->lchild);
		recurDfsPre(tree->rchild);
	}

	void inOrderTraverse() {    // �������
		recurDfsIn(tree);
	}
	void recurDfsIn(BiTree& tree) {
		if (tree == nullptr) return;
		recurDfsIn(tree->lchild);
		cout << tree->data << endl;
		recurDfsIn(tree->rchild);
	}

	void postOrderTraverse() {   // �������
		recurDfsPost(tree);
	}
	void recurDfsPost(BiTree& tree) {
		if (tree == nullptr) return;
		recurDfsPost(tree->lchild);
		recurDfsPost(tree->rchild);
		cout << tree->data << endl;
	}

	void levelTraverse() { // �������
		queue<BiTree> q;
		q.push(tree);
		while (!q.empty()) {
			for (int i = 0; i < q.size(); ++i) {
				BiTree tmp = q.front();
				q.pop();
				cout << tmp->data << endl;
				if (tmp->lchild) q.push(tmp->lchild);
				if (tmp->rchild) q.push(tmp->rchild);
			}
		}
	}
};

int main() {
	BST t;
	t.insert(BiTreeNode(3));
	t.insert(BiTreeNode(2));
	t.insert(BiTreeNode(5));
	t.insert(BiTreeNode(1));
	t.erase(3);
	t.levelTraverse();
	cout << t.search(5)->data << endl;
	return 0;
}