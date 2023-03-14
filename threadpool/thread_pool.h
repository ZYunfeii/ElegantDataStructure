#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <atomic>
#define THREAD_NNUMBER 4
#define MAX_TASK_NUMBER 1024
typedef std::function<void(void)> Task;
class ThreadPool {
public:
    static ThreadPool* getInstance() {
        if (threadPool_ == nullptr) {
            std::unique_lock<std::mutex> lk(singleMutex_);
            if (threadPool_ == nullptr) {
                threadPool_ = new ThreadPool(THREAD_NNUMBER);
            }
        }
        return threadPool_;
    }

    void addTask(Task t) {
        std::unique_lock<std::mutex> lk(mtx_);
        while (queue_.size() >= MAX_TASK_NUMBER) {
            condProductor_.wait(lk);
        }
        queue_.push(t);
        lk.unlock();
        condConsumer_.notify_one();
    }

    void stop() {
        std::unique_lock<std::mutex> lk(mtx_);
        run_.store(false);
        condConsumer_.notify_all();
    }

private:
    ThreadPool(uint32_t threadNum){
        threadNum_ = threadNum;
        run_.store(true);
        for (int i = 0; i < threadNum_; ++i) {
            threadVec_.push_back(
                std::thread([this]() {
                    while (run_.load()) {
                        std::unique_lock<std::mutex> lk(mtx_);
                        while (queue_.empty()) {
                            condConsumer_.wait(lk);
                            if (!run_.load()) {
                                break;
                            }
                        }
                        Task task = queue_.front();
                        queue_.pop();
                        condProductor_.notify_one();
                        lk.unlock();
                        task();
                    }
                })
            );
            threadVec_.back().detach(); 
        }
    };
    std::queue<Task> queue_;
    std::vector<std::thread> threadVec_;
    static ThreadPool* threadPool_;
    std::mutex mtx_;
    
    static std::mutex singleMutex_;
    std::condition_variable condConsumer_;
    std::condition_variable condProductor_;
    uint32_t threadNum_;
    std::atomic<bool> run_;
};

ThreadPool* ThreadPool::threadPool_ = nullptr;
std::mutex ThreadPool::singleMutex_;


#endif