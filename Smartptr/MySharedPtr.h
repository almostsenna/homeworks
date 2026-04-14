#pragma once
#include <cstddef>
#include <utility>

template <typename T>
class MySharedPtr {
private:
    T* ptr;
    size_t* refCount;

    void releaseResource() {
        if (refCount != nullptr) {
            (*refCount)--;

            if (*refCount == 0) {
                delete ptr;
                delete refCount;
            }
        }

        ptr = nullptr;
        refCount = nullptr;
    }

public:
    // Constructors
    MySharedPtr() : ptr(nullptr), refCount(nullptr) {}

    explicit MySharedPtr(T* p) : ptr(p) {
        if (p != nullptr) {
            refCount = new size_t(1);
        }
        else {
            refCount = nullptr;
        }
    }

    // Copy constructor
    MySharedPtr(const MySharedPtr& other)
        : ptr(other.ptr), refCount(other.refCount) {
        if (refCount != nullptr) {
            (*refCount)++;
        }
    }

    // Copy assignment
    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            releaseResource();

            ptr = other.ptr;
            refCount = other.refCount;

            if (refCount != nullptr) {
                (*refCount)++;
            }
        }
        return *this;
    }

    // Move constructor
    MySharedPtr(MySharedPtr&& other) noexcept
        : ptr(other.ptr), refCount(other.refCount) {
        other.ptr = nullptr;
        other.refCount = nullptr;
    }

    // Move assignment
    MySharedPtr& operator=(MySharedPtr&& other) noexcept {
        if (this != &other) {
            releaseResource();

            ptr = other.ptr;
            refCount = other.refCount;

            other.ptr = nullptr;
            other.refCount = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MySharedPtr() {
        releaseResource();
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

    size_t use_count() const {
        return (refCount != nullptr) ? *refCount : 0;
    }

    void reset(T* p = nullptr) {
        releaseResource();

        if (p != nullptr) {
            ptr = p;
            refCount = new size_t(1);
        }
    }

    explicit operator bool() const {
        return ptr != nullptr;
    }
};