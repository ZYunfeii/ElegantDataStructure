#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node
{
	struct node *lchild;
	struct node *rchild;
	char data;
}BiTreeNode, *BiTree;

class Tree {
private:
	BiTree tree;
public:
	void create() {
		BiTree T = new BiTreeNode;
		this->tree = createBiTree(T);
	}
	BiTree createBiTree(BiTree& T) { // ע��ʹ�õ���ָ������� ���ֻ�Ǵ���ָ��ᱻ����
		char c;
		cin >> c;
		if ('#' == c)
			T = NULL;
		else
		{
			cout << "����һ���ڵ�!" << endl;
			T = new BiTreeNode;
			T->data = c;
			createBiTree(T->lchild);
			createBiTree(T->rchild);
		}
		return T;
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
				if(tmp->lchild) q.push(tmp->lchild);
				if(tmp->rchild) q.push(tmp->rchild);
			}
		}
	}
};

int main() {
	Tree t;
	t.create();
	t.preOrderTraverse();
	t.levelTraverse();
	return 0;
}