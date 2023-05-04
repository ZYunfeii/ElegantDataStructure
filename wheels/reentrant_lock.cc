#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
// 可重入锁可以避免死锁，提高代码的安全性和可靠性。
class ReentrantLock {
public:
    ReentrantLock() = default;
    ~ReentrantLock() = default;
    void lock() {
        thread::id tid = this_thread::get_id();
        if (owner == tid) {
            count++;
        } else {
            mtx.lock();
            owner = tid;
            count = 1;
        }
    }
    void unlock() {
        if (owner == this_thread::get_id()) {
            count--;
            if (count == 0) {
                owner = thread::id();
                mtx.unlock();
            }
        }
    }
private:
    thread::id owner;
    size_t count = 0;
    mutex mtx;
};
TEST(ReentrantLock, lock) {
    
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}