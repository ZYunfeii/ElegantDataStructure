#include <iostream>
#include <unistd.h>
#include "thread_pool.h"
using namespace std;

void func() {
    for (int i = 0; i < 10000000; ++i) {

    }
    cout << this_thread::get_id() << endl;
}

int main() {
    auto tp = ThreadPool::getInstance();
    for (int i = 0; i < 100; ++i) {
        tp->addTask(func);
    }
    sleep(4);
    return 0;
}