#include <iostream>
using namespace std;

template<class T>
struct Node {
	T data;
	Node<T> *next;
	Node(T src) :data(src), next(nullptr) {}
	Node() :next(nullptr) {}
};

template<class T>
class CircularLinkedList {
private:
	Node<T> *head_;
	size_t counter_;
public:
	explicit CircularLinkedList() {
		head_ = new Node<T>;
		head_->next = head_;
		counter_ = 0;
	}

	void PushFront(T data) {
		Node<T> *node = new Node<T>(data);
		node->next = head_->next;
		head_->next = node;
		counter_++;
	}

	void PushBack(T data) {
		Node<T> *node = new Node<T>(data);
		node->next = head_;   // 循环链表最后一个节点指向头
		Node<T>* tmp = head_;
		for (int i = 0; i < counter_; ++i) {
			tmp = tmp->next; // 找到最后一个节点
		}
		tmp->next = node;
		counter_++;
	}

	void PopFront() {
		if (counter_ == 0) return;
		Node<T> *tmp = head_->next;
		head_->next = head_->next->next;
		counter_--;
		delete tmp;
	}

	void PopBack() {
		if (counter_ == 0) return;
		Node<T> *tmp = head_;
		for (int i = 0; i < counter_ - 1; ++i) {
			tmp = tmp->next; // 找到最后一个节点前一个节点
		}
		Node<T> *delete_node = tmp->next;
		tmp->next = tmp->next->next;
		counter_--;
		delete delete_node;
	}

	void PrintList() { // 仅支持data为可打印类型
		if (counter_ == 0) return;
		Node<T> *tmp = head_;
		for (int i = 0; i < counter_; ++i) {
			tmp = tmp->next;
			cout << tmp->data << endl;
		}
	}

	bool IsEmpty() {
		return counter_ == 0;
	}

	size_t Size() {
		return counter_;
	}

	void Clear() {
		if (counter_ == 0) return;
		Node<T> *cur = head_->next;
		Node<T> *next = nullptr;
		while (cur != head_) {
			next = cur->next;
			delete cur;
			cur = next;
		}
		head_->next = head_;
		counter_ = 0;
	}
};

int main(){
	CircularLinkedList<int> my_cir_link_list;
	my_cir_link_list.PushBack(2);
	my_cir_link_list.PushFront(3);
	my_cir_link_list.PushBack(4);
	my_cir_link_list.PrintList();
	my_cir_link_list.PopBack();
	my_cir_link_list.PrintList();

	return 0;
}

