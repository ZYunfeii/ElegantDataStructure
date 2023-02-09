#include <iostream>
#include <unordered_map>
#include <list>
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

// using standard library 'list' to realize the LRU
// the back of the list is the newest data
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity_(capacity) {}
    void put(int key, int val) {
        // 1. there is no key in map and the capacity is less than max capacity.
        if (map_.size() < capacity_ && map_.find(key) == map_.end()) {
            Node* node = new Node(key, val);
            map_.insert(pair<int, Node*>(key, node));
            dlist_.push_back(node);
        }
        // 2. there exist key in map.
        if (map_.find(key) != map_.end()) {
            map_[key]->setKV(key, val);
            dlist_.remove(map_[key]);
            dlist_.push_back(map_[key]);
        } else if (map_.size() == capacity_) {
        // 3. the capacity is up to the max capacity.
            map_.erase(dlist_.front()->getKey());
            Node* frontNode = dlist_.front();
            dlist_.pop_front();
            delete frontNode;
            Node* node = new Node(key, val);
            map_.insert(pair<int, Node*>(key, node));
            dlist_.push_back(node);
        }
    }
    int get(int key) {
        if (map_.find(key) == map_.end()) return -1;
        // exist
        dlist_.remove(map_[key]);
        dlist_.push_back(map_[key]);
        return map_[key]->getVal();
    }
private:
    size_t capacity_;
    unordered_map<int, Node*> map_;
    list<Node*> dlist_;
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