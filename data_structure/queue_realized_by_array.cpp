#include <iostream>
#include <string>
#include <exception>
// 数组实现队列，采用固定大小数组循环push思路，使用first_和last_作为头尾指针，first_以右知道last_（可循环）为队列内容，方法复杂度均为O(1)
class queue {
    #define SIZE 6
public:
    queue() {
        arr_ = new int[SIZE];
        last_ = first_ = -1;
    }
    void push(int data) {
        int idx = (last_ + 1) % SIZE;
        if (idx == first_) {
            // 队列满
            throw std::range_error("queue is full!");
        }
        if (first_ == -1) first_ = 0;
        last_ = idx;
        count++;
        arr_[idx] = data;
    }

    int front() {
        return arr_[first_];
    }

    void pop() {
        if (empty()) throw std::range_error("queue is empty!");
        first_ = (first_ + 1) % SIZE;
        count--;
    }

    bool empty() {
        return count == 0;
    }

    ~queue()  {
        delete[] arr_;
    }   

private:
    int* arr_;
    int last_;
    int first_;
    int count = 0;
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    fprintf(stdout, "whether queue is empty:%d\n", q.empty());
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "queue front: %d\n", q.front());
    q.pop();
    fprintf(stdout, "whether queue is empty:%d\n", q.empty());
    return 0;
}