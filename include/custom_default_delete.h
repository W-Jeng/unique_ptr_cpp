#pragma once

#include<iostream>

namespace ctm
{
template <class T>
struct default_delete
{
    constexpr default_delete() noexcept = default;

    template <class U>
    default_delete(const default_delete<U>&) noexcept
    {}

    void operator()(T* ptr) const
    {
        delete ptr;
        std::cout << "Deleted the pointer!" << std::endl;
    }

    template<class U>
    void operator()(U* ptr) const
    {
        delete ptr;
    }

};

template <class T>
struct default_delete<T[]>
{
    constexpr default_delete() noexcept = default;

    template <class U>
    default_delete(const default_delete<U[]>&) noexcept
    {}

    void operator()(T* ptr) const
    {
        delete[] ptr;
    }

};

}