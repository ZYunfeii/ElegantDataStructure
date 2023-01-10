#include <iostream>
#include <unordered_map>
using namespace std;

// LRU LeetCode 后端最高频率题
class Node {
public:
	int val;
	int key;   // 这里得有key 双端链表删除的时候需要让map对应的key的值也删除，因此node里面得保存key的信息
	Node * prev;
	Node  * next;
public:
	Node(int key, int val) {
		this->key = key;
		this->val = val;
	}
};

class DoubleLinkedList {
public:
	Node * head;
	Node * tail;

public:
	DoubleLinkedList() {
		this->head = new Node(0, 0);
		this->tail = new Node(0, 0);

		head->next = tail;
		tail->prev = head;
	}

	void addFirst(Node * newNode) {
		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
	}

	int deleteNode(Node * n) {
		n->next->prev = n->prev;
		n->prev->next = n->next;
		return n->key;
	}

	int deleteLast() {
		if (head->next == tail) return -1;
		return deleteNode(tail->prev);
	}
};

class LRUCache {
public:
	unordered_map<int, Node *> map;
	DoubleLinkedList * cache;
	int cap;
	LRUCache(int capacity) {
		this->map = unordered_map<int, Node *>();
		this->cache = new DoubleLinkedList();
		this->cap = capacity;
	}

	void put(int key, int val) {
		Node * newNode = new Node(key, val);
		if (map.find(key) != map.end()) {   // map中存在该key
			cache->deleteNode(map[key]);
			map[key] = newNode;             // 这里不能用insert insert如果存在key不会更新val
			cache->addFirst(newNode);       // 保证新加入节点的最新性
		}
		else {                             // map中不存在该key
			if (map.size() == cap) {
				int k = cache->deleteLast();
				map.erase(k);
			}
			cache->addFirst(newNode);
			map.insert(pair<int, Node*>(key, newNode));
		}
	}

	int get(int key) {
		if (map.find(key) == map.end()) return -1;
		int val = map[key]->val;
		put(key, val);
		return val;
	}
};

int main()
{
	LRUCache * lru = new LRUCache(2);
	lru->put(2, 1);
	lru->put(3, 2);
	lru->put(4, 4);
	cout << lru->get(2) << endl;
}


