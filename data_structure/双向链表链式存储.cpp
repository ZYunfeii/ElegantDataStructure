#include <iostream>

using namespace std;

// ˫������ 

class Node {
public:
	int val;
	Node * prev;
	Node  * next;
public:
	Node(int val):val(val){}
};

class DoubleLinkedList {
public:
	Node * head;
	Node * tail;

public:
	DoubleLinkedList() {
		this->head = new Node(0);
		this->tail = new Node(0);

		head->next = tail;
		tail->prev = head;
		head->prev = nullptr;
		tail->next = nullptr;
	}

	void addFirst(Node* newNode) {
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}

	void addLast(Node* newNode) {
		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
	}

	void deleteNode(Node * n) {
		n->next->prev = n->prev;
		n->prev->next = n->next;
	}

	void deleteLast() {
		if (head->next == tail) return;
		deleteNode(tail->prev);
	}

	void deleteFirst() {
		if (head->next == tail) return;
		deleteNode(head->next);
	}

	void print_list() {
		Node* tmp = head->next;
		while (tmp->next) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
};

int main() {
	DoubleLinkedList* dlist = new DoubleLinkedList;
	for (int i = 0; i < 5; ++i) {
		Node* tmp = new Node(i);
		dlist->addFirst(tmp); // �����д��addFirst(&Node(i)) !!
	}
	dlist->print_list();

	dlist->deleteLast();
	dlist->print_list();

	dlist->addLast(new Node(6));
	dlist->print_list();

	return 0;
}