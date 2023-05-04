#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
};

class DList {
private:
    Node* head;
    Node* tail;
public:
    DList() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        head->prev = tail;
        tail->next = head;
    }
    void push_front(Node* t) {
        t->next = head->next;
        t->prev = head;
        head->next = t;
        t->next->prev = t;
    }

    void remove(Node* t) {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }

    Node* back() {
        return tail->prev;
    }
};


class LRUCache {
public:
    unordered_map<int, Node*> m;
    DList* list;
    int cap;
    LRUCache(int capacity) {
        list = new DList;
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) {
            return -1;
        }
        int val = m[key]->val;
        list->remove(m[key]);
        list->push_front(m[key]);
        return val;
    }
    
    void put(int key, int value) {
        if (m.count(key) != 0) {
            m[key]->val = value;
            list->remove(m[key]);
            list->push_front(m[key]);
            return;
        }
        if (m.size() == cap) {
            Node* t = list->back();
            m.erase(t->key);
            list->remove(t);
        }
        Node* t = new Node{key, value};
        list->push_front(t);
        m[key] = t;
    }
};

int main(int argc, char** argv){
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    cout << lru.get(3) << endl;
    lru.put(5, 5);
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    return 0;
}