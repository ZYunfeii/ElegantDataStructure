#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;

class RWLock {
public:
    RWLock() : readCount(0), writeCount(0) {}
    ~RWLock() = default;
    void readLock() {
        unique_lock<mutex> lk(mtx);
        cond.wait(lk, writeCount == 0);
        readCount++;
    }
    void writeLock() {
        unique_lock<mutex> lk(mtx);
        cond.wait(lk, readCount == 0 && writeCount == 0);
        writeCount++;
    }
    void unlock() {
        unique_lock<mutex> lk(mtx);
        if (writeCount > 0) {
            writeCount--;
        } else {
            readCount--;
        }
        if (readCount == 0 && writeCount == 0) {
            cond.notify_all();
        } else {
            cond.notify_one();
        }
    }
private:
    mutex mtx;
    condition_variable cond;
    int readCount;
    int writeCount;
};

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}