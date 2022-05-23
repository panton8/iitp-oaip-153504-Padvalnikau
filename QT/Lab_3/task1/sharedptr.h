#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <utility>
#include <iostream>

template<class T>

struct ControlBlock
{
    T* ptr= nullptr;
    int sharedCount = 0;
    int weakCount = 0;
};

//SharedPtr

template<class T>
class WeakPtr;

template<class T>
class SharedPtr
{
private:
    template<class U> friend class WeakPtr;
    ControlBlock<T>* controlBlock = nullptr;
public:
    SharedPtr(){}

    explicit SharedPtr(T* ptr) : controlBlock(new ControlBlock<T>)
      {
          controlBlock->ptr = ptr;
          ++(controlBlock->sharedCount);
      }

      explicit SharedPtr(const WeakPtr<T>& ptr)
          : controlBlock(ptr.controlBlock)
      {
          if (controlBlock) ++(controlBlock->sharedCount);
      }

      ~SharedPtr()
      {
          if (!controlBlock) return;
          --(controlBlock->sharedCount);
          if (controlBlock->sharedCount <= 0) {
              delete controlBlock->ptr;
              controlBlock->ptr = nullptr;
          }
      }

      //copy

      SharedPtr(const SharedPtr& other)
      {
          controlBlock = other.controlBlock;
          ++(controlBlock->sharedCount);
      }

      SharedPtr<T>& operator=(SharedPtr<T>& other)
      {
          if (controlBlock) {
              --(controlBlock->sharedCount);
          }
          controlBlock = other.controlBlock;
          if (controlBlock) {
              ++(controlBlock->sharedCount);
          }

          return *this;
      }

      //move

      SharedPtr(SharedPtr&& other) noexcept
      {
          controlBlock = other.controlBlock;
          if (controlBlock) {
              controlBlock->ptr = other.controlBlock->ptr;
          }
          other.controlBlock->ptr = nullptr;
      }

      SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept
      {
          if (this->controlBlock) {
              --(controlBlock->sharedCount);
          }
          controlBlock = other.controlBlock;
          if (controlBlock) controlBlock->ptr = other.controlBlock->ptr;
          other.controlBlock = nullptr;

          return *this;
      }

      T* operator->() const
      {
          return controlBlock->ptr;
      }

      T& operator*() const
      {
          return *(controlBlock->ptr);
      }

      int use_count() const
      {
          if (controlBlock) {
              return controlBlock->sharedCount;
          }
      }

      bool isNull() const
      {
          return (controlBlock->ptr == nullptr);
      }

      void swap(const SharedPtr<T>& other)
      {
          std::swap(controlBlock, other.controlBlock);
      }

      void reset(T* p)
      {
          delete controlBlock->ptr;
          controlBlock->ptr = p;
      }

      T* get() const noexcept { return controlBlock->ptr; }
};

template<typename T, typename... Args>
SharedPtr<T> make_shared_ptr(Args&&... args) // передаем n аргументов
{
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

//WeakPtr

template<class T>
class WeakPtr
{
private:
    template<class U> friend class SharedPtr;

    ControlBlock<T>* controlBlock = nullptr;
public:
    WeakPtr()
        : controlBlock(nullptr)
    {
    }

    WeakPtr(const SharedPtr<T>& other)
    {
        controlBlock = other.controlBlock;
        if (controlBlock) {
            ++(controlBlock->weakCount);
        }
    }

    ~WeakPtr()
    {
        if (!controlBlock) return;
        --(controlBlock->weakCount);
        if (controlBlock->sharedCount <= 0 && controlBlock->weakCount <= 0) {
            delete controlBlock;
            controlBlock = nullptr;
        }
    }

    bool expired()
    {
        return (!controlBlock || controlBlock->sharedCount <= 0);
    }



    WeakPtr<T>& operator=(const WeakPtr<T>& other) noexcept
    {
        if (controlBlock) {
            --(controlBlock->weakCount);
        }
        controlBlock = other.controlBlock;
        if (controlBlock) {
            ++(controlBlock->weakCount);
        }

        return *this;
    }

    WeakPtr<T>& operator=(const SharedPtr<T>& other) noexcept
    {
        if (controlBlock) --(controlBlock->weakCount);
        controlBlock = other.controlBlock;
        if (controlBlock) ++(controlBlock->weakCount);

        return *this;
    }

    WeakPtr<T>& operator=(WeakPtr<T>&& other) noexcept
    {
        if (this->controlBlock) {
            --(controlBlock->weakCount);
        }
        controlBlock = other.controlBlock;
        other.controlBlock = nullptr;
        return *this;
    }

    void reset() noexcept
    {
        if (controlBlock) {
            --(controlBlock->weakCount);
        }
        controlBlock = nullptr;
    }

    void swap(WeakPtr& other) noexcept
    {
        std::swap(controlBlock, other.controlBlock);
    }

    int use_count() const
    {
        if (controlBlock) {
            return controlBlock->sharedCount;
        }
    }

    SharedPtr<T> lockW()
    {
        return (expired() ? SharedPtr<T>() : SharedPtr<T>(*this));
    }
};

#endif // SHAREDPTR_H
