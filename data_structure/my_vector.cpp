#include <bits/stdc++.h>
using namespace std;

template<class T>
class Vector {
private:
    T* data_;
    size_t size_;
    int capacity_;
public:
    Vector(int n, T val) {
        for (int i = 0; i < n; ++i) {
            push_back(val);
        }
    }
    Vector() {
        capacity_ = 2;
        data_ = new T[capacity_];
        size_ = 0;
    }
    void push_back(T val) {
        if (size_ >= capacity_) {
            realloc();
        }
        data_[size_++] = val;
    }
    size_t size() {
        return size_;
    }
    T operator[](int idx) {
        return data_[idx];
    }
    ~Vector() {
        delete[] data_;
    }
    void realloc() {
        T* newData = new T[capacity_ * 2];
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        capacity_ *= 2;
        delete[] data_;
        data_ = newData;
    }
    int getCapacity() {
        return capacity_;
    }
};

int main() {
    Vector<int> v;
    v.push_back(2);
    v.push_back(10);
    cout << v[1] << endl;
    v.push_back(7);
    v.push_back(8);
    cout << v[3] << endl;
    cout << v.getCapacity() << endl;
    return 0;
}