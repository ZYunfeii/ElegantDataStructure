//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// 二叉搜索树实现
//typedef struct node
//{
//	struct node *lchild;
//	struct node *rchild;
//	int data;
//	node(int src) :data(src) {
//		lchild = nullptr;
//		rchild = nullptr;
//	}
//}BiTreeNode, *BiTree;
//
//class BST {
//private:
//	BiTree tree;
//public:
//
//	BST() {
//		tree = nullptr;
//	}
//
//	// BST 插入操作
//	void insert(BiTreeNode node) {
//		insertRecur(node, tree);
//	}
//
//	void insertRecur(BiTreeNode node, BiTree& root) {
//		if (root == nullptr){
//			root = new BiTreeNode(node.data); // 不能用root = &node, node传进来是个临时变量 
//			return;
//		}
//
//		if (node.data < root->data) {
//			insertRecur(node, root->lchild);
//		}
//		else {
//			insertRecur(node, root->rchild);
//		}
//
//	}
//
//	// 删除操作详见《大话数据结构》p352
//	void erase(int key) {
//		if (deleteBST(tree, key)) {
//			cout << "删除成功!" << endl;
//		}
//		else {
//			cout << "删除失败!" << endl;
//		}
//	}
//
//	bool deleteBST(BiTree& root, int key) {
//		// 先序DFS找到要删除的节点
//		if (root == nullptr) return false;
//		else {
//			if (key == root->data) return deleteNode(root); 
//			else if (key < root->data) return deleteBST(root->lchild, key);
//			else return deleteBST(root->rchild, key);
//		}
//	}
//
//	bool deleteNode(BiTree& root) {
//		BiTree tmp;
//		if (root->rchild == nullptr) { // 没有右子树的情况直接把左子树接上来
//			tmp = root;
//			root = root->lchild;
//			delete tmp;
//		}
//		else if (root->lchild == nullptr) { // 没有左子树的情况直接把右子树接上来
//			tmp = root;
//			root = root->rchild;
//			delete tmp;
//		}
//		else {                         // 既有左子树又有右子树
//			BiTree q = root;
//			BiTree s = root->lchild;
//			// 找左子树的最右节点s，因为这个节点一定是左子树中最大的节点同时一定比右子树的所有节点值小，用它来代替待删除节点
//			// q是s的前驱节点
//			while (s->rchild) { 
//				q = s;
//				s = s->rchild;
//			}
//			root->data = s->data;
//			if (q != root) {
//				q->rchild = s->lchild;
//			}
//			else {
//				q->lchild = s->lchild;  // q == root的情况是待删除节点的左孩子节点没有右子树，此时直接把左孩子节点的左子树接上来
//			}
//			delete s;
//		}
//		return true;
//	}
//
//	// BST查找操作O(logn)
//	BiTree search(int key) {
//		BiTree res = searchDfs(tree, key);
//		if (res == nullptr) {
//			cout << "没有对应节点!" << endl;
//			return nullptr;
//		}
//		else return res;
//	}
//
//	BiTree searchDfs(BiTree& root, int key) {
//		if (root == nullptr) return nullptr;
//		if (key < root->data) return searchDfs(root->lchild, key);
//		else if(key > root->data) return searchDfs(root->rchild, key);
//		else return root;
//	}
//	
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
//				if (tmp->lchild) q.push(tmp->lchild);
//				if (tmp->rchild) q.push(tmp->rchild);
//			}
//		}
//	}
//};
//
//int main() {
//	BST t;
//	t.insert(BiTreeNode(3));
//	t.insert(BiTreeNode(2));
//	t.insert(BiTreeNode(5));
//	t.insert(BiTreeNode(1));
//	t.erase(3);
//	t.levelTraverse();
//	cout << t.search(5)->data << endl;
//	return 0;
//}