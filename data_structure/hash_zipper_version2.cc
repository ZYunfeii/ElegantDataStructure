#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>

typedef struct node {
    int key_;
    int val_;
} Node;

class HashTable {
private:
    std::vector<std::list<std::shared_ptr<Node>>> hash_;
    int hash(int key) {
        return key % hash_.size();
    }
public:
    HashTable() = delete;
    HashTable(int size) {
        hash_.resize(size);
    }
    void insert(int key, int val) {
        int slot = hash(key);
        for (auto i = hash_[slot].begin(); i != hash_[slot].end(); ++i) {
            if (i->get()->key_ == key) {
                i->get()->val_ = val;
                return;
            }
        }
        hash_[slot].push_back(std::shared_ptr<Node>(new Node{key, val})); 
    }
    int get(int key) {
        int slot = hash(key);
        for (auto i = hash_[slot].begin(); i != hash_[slot].end(); ++i) {
            if (i->get()->key_ == key) {
                return i->get()->val_;
            }
        }
        
        throw std::range_error("no key.");
    }
    void del(int key) {
        int slot = hash(key);
        std::for_each(hash_[slot].begin(), hash_[slot].end(), [&key, &slot, this](std::shared_ptr<Node> p) {
            if (p.get()->key_ == key) {
                hash_[slot].remove(p);
            }
        });
    }
};

int main() {
    HashTable hashtab(4);
    hashtab.insert(1, 2);
    hashtab.insert(2, 4);
    hashtab.insert(4, 6);
    hashtab.insert(8, 0);
    hashtab.insert(8, 10);
    hashtab.insert(11, 22);

    fprintf(stdout, "hash[8] = %d\n", hashtab.get(8));
    return 0;
}