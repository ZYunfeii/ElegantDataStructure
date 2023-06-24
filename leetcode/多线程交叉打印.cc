#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

// 多线程交叉打印两个数组：A{1，2，3}，B{a，b，c}，要求A先打印，输出1a2b3c，提示使用线程间同步机制

condition_variable cond1;
condition_variable cond2;
mutex mtx1;
mutex mtx2;
atomic_bool flag(0); // 和wait的第二个参数一起使用，解决唤醒丢失，即notify时cond并没有到wait

void threadA() {
    cout << "1" << endl;
    flag.store(1);
    cond2.notify_one();
    unique_lock<mutex> lk(mtx1);
    cond1.wait(lk);

    lk.unlock();
    cout << "2" << endl;
    flag.store(1);
    cond2.notify_one();
    lk.lock();
    cond1.wait(lk);

    lk.unlock();
    cout << "3" << endl;
    flag.store(1);
    cond2.notify_one();
}

void threadB() {
    unique_lock<mutex> lk(mtx2);
    cond2.wait(lk, [](){return flag.load();});
    flag.store(false);
    cout << "a" << endl;
    lk.unlock();
    cond1.notify_one();

    lk.lock();
    cond2.wait(lk, [](){return flag.load();});
    flag.store(false);
    cout << "b" << endl;
    lk.unlock();
    cond1.notify_one();

    lk.lock();
    cond2.wait(lk, [](){return flag.load();});
    flag.store(false);
    cout << "c" << endl;
    lk.unlock();
}


int main() {
    thread(threadA).detach();
    thread(threadB).detach();
    sleep(2);
    return 0;
}