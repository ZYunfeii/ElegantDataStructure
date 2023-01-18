#include <iostream>
#include <string>
#include <exception>

class stack{
public:
    #define SIZE 6
    stack() {
        arr_ = new int[SIZE];
    }

    void push(int val) {
        int idx = last_ + 1;
        if (idx == SIZE) {
            throw std::range_error("stack is full!");
        }
        arr_[idx] = val;
        last_ = idx;
        count_++;
    }

    void pop() {
        if (empty()) {
            throw std::range_error("stack is empty!");
        }
        last_--;
        count_--;
    }

    int top() {
        return arr_[last_];
    }

    bool empty() {
        return count_ == 0;
    }

    ~stack() {
        delete[] arr_;
    }

private:
    int last_ = -1;
    int count_ = 0;
    int* arr_;
};

int main() {
    stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    fprintf(stdout, "whether stack is empty:%d\n", stk.empty());
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "stack top: %d\n", stk.top());
    stk.pop();
    fprintf(stdout, "whether stack is empty:%d\n", stk.empty());
    
    return 0;
}