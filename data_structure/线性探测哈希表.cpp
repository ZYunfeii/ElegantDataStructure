//#include <iostream>
//using namespace std;
//
//class HashTable {
//private:
//	static const int HASHSIZE = 12;
//	static const int NULLKEY = -32768;
//	int* elem;
//public:
//	HashTable() {
//		elem = new int[HASHSIZE];
//		for (int i = 0; i < HASHSIZE; ++i) {
//			elem[i] = NULLKEY;
//		}
//	}
//	int hash(int key) {
//		return key % HASHSIZE;
//	}
//	void insertHash(int key) {
//		int addr = hash(key);
//		while (elem[addr] != NULLKEY) {
//			addr = (addr + 1) % HASHSIZE;    // 开放定址法线性探测
//		}
//		elem[addr] = key;
//	}
//	int searchHash(int key) {
//		int addr = hash(key);
//		while (elem[addr] != key) {    // hash冲突了
//			addr = (addr + 1) % HASHSIZE;
//			if (elem[addr] == NULLKEY || addr == hash(key)) { // 如果循环一圈或者下一个探测为null则搜索失败（在插入的时候不可能留有null）
//				return NULLKEY;
//			}
//		}
//		return elem[addr];
//	}
//};
//
//int main() {
//	HashTable tab;
//	tab.insertHash(14);
//	tab.insertHash(3);
//	tab.insertHash(2);
//	cout << tab.searchHash(2) << endl;
//	return 0;
//}