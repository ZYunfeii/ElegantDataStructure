#include <iostream>

typedef struct {
    int data_;
} Data;

template <class T>
class MySharedPtr {
public:
    MySharedPtr(T* d) : data_(d) {
        if (d) {
            count_ = new int(1);
        } else {
            count_ = new int(0);
        }
    }
    MySharedPtr(MySharedPtr& rhs) {
        if (this != &rhs) {
            data_ = rhs.data_;
            count_ = rhs.count_;
            ++(*count_);
        }
    }
    MySharedPtr& operator=(MySharedPtr& rhs) {
        if (rhs.data_ == this->data_) return *this;
        if (data_) {
            if (!--(*count_)) {
                std::cout << "delete" << std::endl;
                delete data_;
                delete count_;
            }
        }
        data_ = rhs.data_;
        count_ = rhs.count_;
        (*count_)++;
        return *this;
    }
    T& operator*() {
        if (data_) {
            return *data_;
        }
    }
    T* operator->() {
        if (data_) {
            return data_;
        }
    }
    int useCount() {
        return *count_;
    }

    int* count_;
    T* data_;
    ~MySharedPtr() {
        if (!--count_) {
            delete data_;
        }
    }
};

int main() {
    MySharedPtr<Data> sp(new Data);
    MySharedPtr<Data> sp2(nullptr);
    sp2 = sp;
    std::cout << sp.useCount() << std::endl;
    MySharedPtr<Data> sp3(new Data);
    sp2 = sp3;
    sp = sp3;
    std::cout << sp3.useCount() << std::endl;
    std::cout << sp.useCount() << std::endl;
    std::cout << sp2.useCount() << std::endl;
    std::cout << sp->data_ << std::endl;
    return 0;
}