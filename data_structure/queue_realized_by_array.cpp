#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;
// 数组实现队列，采用固定大小数组循环push思路，使用first_和last_作为头尾指针，first_以右知道last_（可循环）为队列内容，方法复杂度均为O(1)
class MyCircularQueue {
public:
    vector<int> v;
    int first, last;
    bool full;
    MyCircularQueue(int k) {
        v.resize(k);
        first = last = 0;
        full = false;
    }
    
    bool push(int value) {
        if (last == first && full) {
            return false;
        }
        v[last] = value;
        last = (last + 1) % v.size();
        if (last == first) {
            full = true;
        }
        return true;
    }
    
    bool pop() {
        if  (first == last && !full) {
            return false;
        }
        first =  (first + 1) % v.size();
        if (full) {
            full = false;
        }
        return true;
    }
    
    int front() {
        if (!empty()) {
            return v [first];
        } else {
            return -1;
        }
        
    }
    
    int rear() {
        if (!empty()) {
            return v[(last + v.size() - 1) % v.size()];
        } else {
            return -1;
        }
    }
    
    bool empty() {
        if  (first == last && !full) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        return full;
    }
};

int main() {
    try {
        MyCircularQueue q(10);
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        fprintf(stdout, "whether queue is empty:%d\n", q.empty());
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "queue first: %d\n", q.front());
        q.pop();
        fprintf(stdout, "whether queue is empty:%d\n", q.empty());
    } catch (std::range_error& e) {
        fprintf(stdout, "error:%s\n", e.what());
    }
    return 0;
}