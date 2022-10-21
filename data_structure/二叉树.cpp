//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//typedef struct node
//{
//	struct node *lchild;
//	struct node *rchild;
//	char data;
//}BiTreeNode, *BiTree;
//
//class Tree {
//private:
//	BiTree tree;
//public:
//	void create() {
//		BiTree T = new BiTreeNode;
//		this->tree = createBiTree(T);
//	}
//	BiTree createBiTree(BiTree& T) { // 注意使用的是指针的引用 如果只是传入指针会被拷贝
//		char c;
//		cin >> c;
//		if ('#' == c)
//			T = NULL;
//		else
//		{
//			cout << "创建一个节点!" << endl;
//			T = new BiTreeNode;
//			T->data = c;
//			createBiTree(T->lchild);
//			createBiTree(T->rchild);
//		}
//		return T;
//	}
//	void preOrderTraverse() {  // 先序遍历
//		recurDfsPre(tree);
//	}
//	void recurDfsPre(BiTree& tree) {
//		if (tree == nullptr) return;
//		cout << tree->data << endl;
//		recurDfsPre(tree->lchild);
//		recurDfsPre(tree->rchild);
//	}
//
//	void inOrderTraverse() {    // 中序遍历
//		recurDfsIn(tree);
//	}
//	void recurDfsIn(BiTree& tree) {
//		if (tree == nullptr) return;
//		recurDfsIn(tree->lchild);
//		cout << tree->data << endl;
//		recurDfsIn(tree->rchild);
//	}
//
//	void postOrderTraverse() {   // 后序遍历
//		recurDfsPost(tree);
//	}
//	void recurDfsPost(BiTree& tree) {
//		if (tree == nullptr) return;
//		recurDfsPost(tree->lchild);
//		recurDfsPost(tree->rchild);
//		cout << tree->data << endl;
//	}
//
//	void levelTraverse() { // 层序遍历
//		queue<BiTree> q;
//		q.push(tree);
//		while (!q.empty()) {
//			for (int i = 0; i < q.size(); ++i) {
//				BiTree tmp = q.front();
//				q.pop();
//				cout << tmp->data << endl;
//				if(tmp->lchild) q.push(tmp->lchild);
//				if(tmp->rchild) q.push(tmp->rchild);
//			}
//		}
//	}
//};
//
//int main() {
//	Tree t;
//	t.create();
//	t.preOrderTraverse();
//	t.levelTraverse();
//	return 0;
//}