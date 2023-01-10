#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

// 创建list
Node* create_list() {
	Node* head = new Node;
	head->next = nullptr;
	return head;
}

// 头插法
void insert(Node* t, Node* head) {
	t->next = head->next;
	head->next = t;
}

void print_list(Node* head) {
	Node* tmp = head->next;
	while (tmp) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << "print complete!"<<endl;
}

// 删除：默认list中val不同，删除对应val的节点
void delete_node(int val, Node* head) {
	Node* pre = head;
	Node* cur = head->next;
	while (cur) {
		if (cur->val == val) {
			pre->next = cur->next;
			delete cur;
			return;
		}
		cur = cur->next;
		pre = pre->next;
	}
}

// 删除整个list
void delete_list(Node* head) {
	Node* cur = head->next;
	Node* tmp;
	while (cur) {
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	head->next = nullptr; // key!
}

int main()
{
	Node* mylist = create_list();
	for (int i = 0; i < 4; ++i) {
		Node* tmp = new Node;
		tmp->val = i;
		insert(tmp, mylist);
	}
	print_list(mylist);

	delete_node(2, mylist);
	print_list(mylist);

	delete_list(mylist);
	print_list(mylist);

	return 0;
}

