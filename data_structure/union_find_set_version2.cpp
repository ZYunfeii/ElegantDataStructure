#include <iostream>
#include <vector>
class UnionFindSet {
public:
    UnionFindSet(int n) {
        parent_.resize(n);
        for (int i = 0; i < parent_.size(); ++i) {
            parent_[i] = i;
        }
        count_ = n;
    }
    void munion(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;
        parent_[pRoot] = qRoot;
        count_--;
    }
    int find(int x) {
        //                        0
        // 0--6--2--1   --->     /|\ 
        //                      6 2 1
        if (parent_[x] != x) { // mark: not while!
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    size_t count() {
        return count_;
    }
private:
    std::vector<int> parent_; 
    size_t count_;
};

int main(int argc, char* argv[]) {
    #define N 6
    UnionFindSet ufs(N);
    fprintf(stdout, "union find set size:%d\n", N);
    
    fprintf(stdout, "test union find set method============\n");

    //    0------2------4
    //    3------1------5 

    ufs.munion(0, 2);
    ufs.munion(1, 5);
    ufs.munion(1, 3);
    ufs.munion(2, 4);

    fprintf(stdout, "连通分量:%d\n", ufs.count());
    fprintf(stdout, "0和2是否连接:%d\n", ufs.connected(0, 2));
    fprintf(stdout, "0和4是否连接:%d\n", ufs.connected(0, 4));
    fprintf(stdout, "3和5是否连接:%d\n", ufs.connected(3, 5));
    fprintf(stdout, "1和4是否连接:%d\n", ufs.connected(1, 4));
    fprintf(stdout, "3和4是否连接:%d\n", ufs.connected(3, 4));

    return 0;
}