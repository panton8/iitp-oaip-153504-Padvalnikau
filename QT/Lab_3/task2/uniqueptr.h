#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include <type_traits>
#include <utility>

template <typename T>
struct UniquePtr {

    UniquePtr() noexcept
        : ptr(nullptr) {}
    explicit UniquePtr(T* ptr)
        : ptr(ptr) {}
    //copy
    UniquePtr(UniquePtr const& other) = delete;
    UniquePtr& operator=(UniquePtr const& other) = delete;

    ~UniquePtr() {
        delete ptr;
    }

    T& operator*() const {
        return *ptr;
    }
    T* operator->() const noexcept {
        return ptr;
    }

    //move
    UniquePtr(UniquePtr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        reset(other.release());
        return *this;
    }
    T* get() const {
        return ptr;
    }
    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }
    bool isNull() const noexcept
    {
        return ptr == nullptr;
    }
    void swap(UniquePtr& other) noexcept
    {
        std::swap(this->ptr, other.ptr);
    }
    void reset(T* p) noexcept{
        delete ptr;
        ptr = p;
    }
    explicit operator bool() const noexcept { return (ptr != nullptr); }
private:
    T* ptr;
};

template <typename T, typename... Args>
UniquePtr<T> make_unique_ptr(Args&&... args)
{
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
struct UniquePtr<T[]>
{
public:
    UniquePtr() noexcept
        : ptr(nullptr) {}
    explicit UniquePtr(T* ptr)
        : ptr(ptr) {}
    ~UniquePtr()
    {
        delete[] ptr;
    }
    //copy
    UniquePtr(UniquePtr const& other) = delete;
    UniquePtr& operator=(UniquePtr const& other) = delete;

    T& operator*() const {
        return *ptr;
    }
    T* operator->() const noexcept {
        return ptr;
    }
    T& operator[] (const int& i) const
    {
        return ptr[i];
    }

    //move
    UniquePtr(UniquePtr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    //
    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        reset(other.release());
        return *this;
    }
    T* get() const {
        return ptr;
    }
    T* release() {
        T* tmp = ptr;
        ptr = nullptr;
        return tmp;
    }
    bool isNull() const noexcept
    {
        return ptr == nullptr;
    }
    void swap(UniquePtr& other) noexcept
    {
        std::swap(this->ptr, other.ptr);
    }
    void reset(T* p) noexcept {
        delete[] ptr;
        ptr = p;
    }
    explicit operator bool() const noexcept { return (ptr != nullptr); }
private:
    T* ptr;
};

#endif // UNIQUEPTR_H
