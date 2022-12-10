#include <queue>
#include <condition_variable>
#include <mutex>

template <class T>
class SimpleMessageQueue {
public:
    SimpleMessageQueue(size_t maxSize) : maxSize_(maxSize) {}
    bool push(T val) {
        std::unique_lock<std::mutex> lk(mtx_);
        while (queue_.size() >= maxSize_) {
            pushCond_.wait(lk);
        }
        queue_.push(val);
        popCond_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lk(mtx_);
        while (queue_.empty()) {
            popCond_.wait(lk);
        }
        T val = queue_.front();
        queue_.pop();
        pushCond_.notify_one();
        return val;
    }

    size_t size() {
        return queue_.size();
    }
private:
    std::queue<T> queue_;
    std::mutex mtx_;
    size_t maxSize_;
    std::condition_variable pushCond_;
    std::condition_variable popCond_;
};
