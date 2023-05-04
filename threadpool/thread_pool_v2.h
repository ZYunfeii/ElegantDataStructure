#ifndef ILOVERS_THREAD_POOL_H
#define ILOVERS_THREAD_POOL_H
 
#include <iostream>
#include <functional>
#include <thread>
#include <condition_variable>
#include <future>
#include <atomic>
#include <vector>
#include <queue>
 
// 命名空间
namespace ilovers {
    class TaskExecutor;
}
 
class ilovers::TaskExecutor{
    using Task = std::function<void()>;
private:
    // 线程池
    std::vector<std::thread> pool;
    // 任务队列
    std::queue<Task> tasks;
    // 同步
    std::mutex m_task;
    std::condition_variable cv_task;
    // 是否关闭提交
    std::atomic<bool> stop;
    
public:
    // 构造
    TaskExecutor(size_t size = 4): stop {false}{
        size = size < 1 ? 1 : size;
        for(size_t i = 0; i< size; ++i){
            pool.emplace_back(&TaskExecutor::schedual, this);    // push_back(std::thread{...})
        }
    }
    
    // 析构
    ~TaskExecutor(){
        for(std::thread& thread : pool){
            thread.detach();    // 让线程“自生自灭”
            //thread.join();        // 等待任务结束， 前提：线程一定会执行完
        }
    }
    
    // 停止任务提交
    void shutdown(){
        this->stop.store(true);
    }
    
    // 重启任务提交
    void restart(){
        this->stop.store(false);
    }
    
    // 提交一个任务
    template<class F, class... Args>
    auto commit(F&& f, Args&&... args) ->std::future<decltype(f(args...))> {
        if(stop.load()){    // stop == true ??
            throw std::runtime_error("task executor have closed commit.");
        }
        
        using ResType =  decltype(f(args...));    // typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
        auto task = std::make_shared<std::packaged_task<ResType()>>(
                        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
                );    // wtf !
        {    // 添加任务到队列
            std::lock_guard<std::mutex> lock {m_task};
            tasks.emplace([task](){   // push(Task{...})
                (*task)();
            });
        }
        cv_task.notify_all();    // 唤醒线程执行
        
        std::future<ResType> future = task->get_future();
        return future;
    }
    
private:
    // 获取一个待执行的 task
    Task get_one_task(){
        std::unique_lock<std::mutex> lock {m_task};
        /*
        当其他notify_one()将wait唤醒之后，wait不断尝试获取互斥量锁，如果获取不到，流程就卡在wait这里等着获取。如果获取到了，wait就获取到锁（就等于上锁）；
        （1）如果wait有第二个参数（lambda）,就判断这个表达式，如果lambda为false，那么流程如上，又休眠，再等待唤醒；
        （2）如果表达式为true，那么wait返回，流程走下来（此时互斥量锁还是锁着的），流程只要能走到这里来，这个互斥量锁一定是锁着的。
        （3）如果没有第二个参数，wait就返回，流程走下来（带第二个参数的wait等价while里面写wait）
        */
        cv_task.wait(lock, [this](){ return !tasks.empty(); });    // wait 直到有 task 
        Task task {std::move(tasks.front())};    // 取一个 task
        tasks.pop();
        return task;
    }
    
    // 任务调度
    void schedual(){
        while(true){
            if(Task task = get_one_task()){
                task();    //
            }else{
                // return;    // done
            }
        }
    }
};
 
#endif
 

 
 
