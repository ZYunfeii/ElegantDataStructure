#include <iostream>
#include "simple_message_queue.h"
#include <thread>

int main(int argc, char* argv[]) {
    SimpleMessageQueue<int>* mq = new SimpleMessageQueue<int>(32);
    std::vector<std::thread> q;
    for (int i = 0; i < 5; ++i) {
        q.push_back(
            std::thread([&mq](){
                while (1) {
                    int val = mq->pop();
                    std::cout << "Thread id:" << std::this_thread::get_id() 
                    << "  Val:" << val << std::endl;
                }
            })
        );
    }

    for (int i = 0; i < 10; ++i) {
        q.push_back(
            std::thread([&mq](){
                while (1) {
                    mq->push(rand() % 20);
                    std::cout << "Thread id:" << std::this_thread::get_id() 
                    << "  push success" << "  size:" << mq->size() << std::endl;
                }
            })
        );
    }

    for (auto& t : q) {
        t.join();
    }
    return 0;
}