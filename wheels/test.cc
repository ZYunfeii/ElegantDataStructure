#include <bits/stdc++.h>
#include <thread>
#include <unistd.h>
using namespace std;

condition_variable cond;
condition_variable cond2;
mutex mtx;
void threadA() {
    sleep(1);
    cond.notify_one();
    unique_lock<mutex> lk(mtx);
    cond2.wait(lk);
    cout << "hello" << endl;
}

void threadB() {
    unique_lock<mutex> lk(mtx);
    cond.wait(lk);
    cout << "do process" << endl;
    sleep(1);
    cout << "process done" << endl;
    lk.unlock();
    cond2.notify_one();
}

int main() {
    thread(threadA).detach();
    thread(threadB).detach();
    sleep(4);
    return 0;
}