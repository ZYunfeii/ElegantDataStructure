#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int key;
	int val;
} Node;
class HashTable {
private:
	static const int HASHSIZE = 12;
	static const int NULLKEY = -32768;
	vector<Node*> elem;

public:
	HashTable() {
		elem = vector<Node*>(HASHSIZE);
		for (int i = 0; i < HASHSIZE; ++i) {
			elem[i] = nullptr;
		}
	}
	int hash(int key) {
		return key % HASHSIZE;
	}
	void insertHash(int key, int val) {
		int addr = hash(key);
		while (elem[addr] != nullptr) {
			addr = (addr + 1) % HASHSIZE;   
		}
		elem[addr] = new Node{key, val};
	}
	int searchHash(int key) {
		int addr = hash(key);
		while (elem[addr]->key != key) {    
			addr = (addr + 1) % HASHSIZE;
			if (addr == hash(key)) {  // 走了一圈回来了
				return NULLKEY;
			}
		}
		return elem[addr]->val;
	}
};

int main() {
	HashTable tab;
	tab.insertHash(14, 2);
	tab.insertHash(3, 4);
	tab.insertHash(2, 7);
	cout << tab.searchHash(3) << endl;
	return 0;
}