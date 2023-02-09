#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
private:
    int key_; 
    int val_;
public:
    Node(int key, int val) : key_(key), val_(val), prev_(nullptr), next_(nullptr) {} 
    Node() {}
    void setKV(int key, int val) {
        key_ = key;
        val_ = val;
    }
    int getKey() {
        return key_;
    }
    int getVal() {
        return val_;
    }
    Node* prev_;
    Node* next_;
};

class DoubleLinkedList {
public:
    DoubleLinkedList() : head_(new Node), tail_(new Node) {
        head_->next_ = tail_;
        tail_->prev_ = head_;
    }
    void pushBack(Node* node) {
        tail_->prev_->next_ = node;
        node->prev_ = tail_->prev_;
        node->next_ = tail_;
        tail_->prev_ = node;
    }
    void popFront() {
        if (head_->next_ == tail_) return;
        Node* node = head_->next_;
        head_->next_ = head_->next_->next_;
        head_->next_->prev_ = head_;
        delete node;
    }
    void erase(Node* node) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
    }
    Node* top() {
        return head_->next_;
    }
private:
    Node* head_;
    Node* tail_;
};

class LRUCache {
public:
    LRUCache(size_t capacity) : capacity_(capacity) {}
    void put(int key, int val) {
        // 1. there is no key in map and the capacity is less than max capacity.
        if (map_.size() < capacity_ && map_.find(key) == map_.end()) {
            Node* node = new Node(key, val);
            map_.insert(pair<int, Node*>(key, node));
            dlist_.pushBack(node);
        }
        // 2. there exist key in map.
        if (map_.find(key) != map_.end()) {
            map_[key]->setKV(key, val);
            dlist_.erase(map_[key]);
            dlist_.pushBack(map_[key]);
        } else if (map_.size() == capacity_) {
        // 3. the capacity is up to the max capacity.
            map_.erase(dlist_.top()->getKey());
            dlist_.popFront();
            Node* node = new Node(key, val);
            map_.insert(pair<int, Node*>(key, node));
            dlist_.pushBack(node);
        }
    }
    int get(int key) {
        if (map_.find(key) == map_.end()) return -1;
        // exist
        dlist_.erase(map_[key]);
        dlist_.pushBack(map_[key]);
        return map_[key]->getVal();
    }
private:
    size_t capacity_;
    unordered_map<int, Node*> map_;
    DoubleLinkedList dlist_;
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
    return 0;
}





