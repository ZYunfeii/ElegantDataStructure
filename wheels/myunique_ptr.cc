#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
template <class T>
class UQPtr {
public:
    UQPtr() noexcept : ptr(nullptr) {} 
    explicit UQPtr(T* p) noexcept : ptr(p) {}
    UQPtr(UQPtr&& right) noexcept : ptr(right.ptr) {
        right.ptr = nullptr;
    }
    UQPtr(const UQPtr&) = delete;
    ~UQPtr() {
        delete ptr;
    }
    UQPtr& operator=(UQPtr&& right) noexcept {
        if (this != &other) {
            reset(other.ptr);
            other.ptr = nullptr;
        }
        return *this;
    }
    UQPtr& operator=(const UQPtr&) = delete;
    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }
    T* release() noexcept {
        T* p = ptr;
        ptr = nullptr;
        return p;
    }
    T* get() const noexcept {
        return ptr;
    }
    UQPtr& operator=(T&) = delete;
    UQPtr(const T&) = delete;
private:
    T* ptr;
};

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}