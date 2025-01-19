#pragma once

#include "custom_default_delete.h"
#include <cstddef>
#include <type_traits>

namespace ctm
{
template <class T, class Deleter = ctm::default_delete<T>>
class unique_ptr
{
public:
    using element_type = T;
    using pointer = T*;

    constexpr unique_ptr() noexcept = default;

    constexpr unique_ptr(std::nullptr_t) noexcept {}

    explicit unique_ptr(T* p) noexcept:
        ptr_(p) {}

    unique_ptr(unique_ptr&& u) noexcept:
        ptr_(u.ptr_)
    {
        u.ptr_ = nullptr;
    }

    unique_ptr(const unique_ptr& u) = delete;

    ~unique_ptr()
    {
        deleter(ptr_);
    }

    unique_ptr& operator=(unique_ptr&& r) noexcept
    {
        reset(r.ptr_);
        r.ptr_ = nullptr;
        return *this;
    }

    unique_ptr& operator=(std::nullptr_t) noexcept
    {
        deleter(ptr_);
        ptr_ = nullptr;
        return *this;
    }

    unique_ptr& operator=(const unique_ptr& u) = delete;

    pointer release() noexcept
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    pointer get() const noexcept
    {
        return ptr_;
    }

    Deleter& get_deleter() noexcept
    {
        return deleter;
    }

    Deleter& get_deleter() const noexcept
    {
        return deleter;
    }

    void reset(pointer ptr = pointer()) noexcept
    {
        delete ptr_;
        ptr_ = ptr;
    }

    explicit operator bool() const noexcept
    {
        return ptr_ != nullptr;
    }

    typename std::add_lvalue_reference<T>::type operator*() const noexcept(noexcept(*std::declval<pointer>()))
    {
        return *ptr_;
    }

    pointer operator->() const noexcept
    {
        return ptr_;
    }

private:
    T* ptr_ = nullptr;
    Deleter deleter;
};
}