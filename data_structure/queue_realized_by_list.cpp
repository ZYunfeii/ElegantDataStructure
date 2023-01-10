#include <iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node(T data) :data(data) {}
	Node() {};
};

template<class T>
class queue {
public:
	Node<T>* head;
	Node<T>* tail;
	queue() {
		head = new Node<T>;
		head->next = nullptr;
		tail = head;
	}
	// β�巨
	void push(Node<T>* n) {
		tail->next = n;
		tail = n;
	}

	Node<T>* front() {
		return head->next;
	}

	Node<T>* back() {
		return tail;
	}

	// ����ʵ�ֶ�����
	void pop() {
		if (!head->next) return;
		Node<T>* tmp = head;
		head = head->next;
		delete tmp;

		//if (!head->next) return;
		//Node<T>* tmp = head->next;
		//head->next = head->next->next;
		//delete tmp;
	}

	bool empty() {
		return !head->next;
	}
};

int main() {
	queue<int>* q = new queue<int>;
	for (int i = 0; i < 5; ++i) {
		q->push(new Node<int>(i));
	}

	while (!q->empty()) {
		Node<int>* node = q->front();
		cout << node->data << " ";
		q->pop();
	}

	return 0;
}