#ifndef UNIQUE_LOCK_H
#define UNIQUE_LOCK_H
#include <mutex>
template<class T>
class UQLock {
private:
    T& mtx_;
    bool ownsLock_;
public:
    UQLock UQLock(UQLock& right) = delete;
    UQLock& operator=(UQLock& right) = delete;
    ~UQLock() {
        mtx_.unlock();
    }
    explicit UQLock(T& mtx) {
        mtx_ = mtx;
        mtx_.lock();
        ownsLock_ = true;
    }
    UQLock(T& mtx, std::defer_lock_t) {
        mtx_ = mtx;
        ownsLock_ = false;
    }
    UQLock(T& mtx, std::try_to_lock_t) {
        mtx_ = mtx;
        ownsLock_ = mtx.try_lock();  // try_lock是非阻塞调用，如果可以加锁就加锁并返回true，否则返回false
    }
    UQLock(T& mtx, std::adopt_lock_t) { // 收养一个已经加了锁的lock
        mtx_ = mtx;
        ownsLock_ = true;
    }
    void lock() {
        if (!ownsLock_) {
            mtx_.lock();
            ownsLock_ = true;
        }
    }
    void unlock() {
        if (ownsLock_) {
            mtx_.unlock();
            ownsLock_ = false;
        }
    }
    bool try_lock() {
        if (!ownsLock_) {
            ownsLock_ = mtx_.try_lock();
        }
        return ownsLock_;
    } 
};

#endif