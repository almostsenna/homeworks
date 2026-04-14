#pragma once
#include <utility>

template <typename T>
class MyUniquePtr {
private:
    T* ptr;

public:
    // Constructors
    MyUniquePtr() : ptr(nullptr) {}

    explicit MyUniquePtr(T* p) : ptr(p) {}

    // Copy is forbidden
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // Move constructor
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyUniquePtr() {
        delete ptr;
    }

    // Operators
    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    // Methods
    T* get() const {
        return ptr;
    }

    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void reset(T* p = nullptr) {
        if (ptr != p) {
            delete ptr;
            ptr = p;
        }
    }

    void swap(MyUniquePtr& other) {
        T* temp = ptr;
        ptr = other.ptr;
        other.ptr = temp;
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }
};