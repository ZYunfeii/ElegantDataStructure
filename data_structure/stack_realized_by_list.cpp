#include <iostream>

using namespace std;

// ջ��ʽ�洢

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node(T data) :data(data) {}
};

template<class T>
class Stack {
public:
	Stack(T data) {
		head = new Node<T>(data);
		head->next = nullptr;
	}

	void push(Node<T>* n) {
		n->next = head->next;
		head->next = n;
	}

	Node<T>* top() {
		return head->next;
	}

	void pop() {
		Node<T>* tmp = head->next;
		if (!head->next) return;
		head->next = head->next->next;
		delete tmp;
	}

	bool empty() {
		return !head->next;
	}

	Node<T>* head;
};

int main() {
	Stack<int> stk(0);
	for (int i = 0; i < 5; ++i) {
		stk.push(new Node<int>(i));
	}

	while (!stk.empty()) {
		Node<int>* tmp = stk.top();
		cout << tmp->data << endl;
		stk.pop();
	}

	return 0;
}