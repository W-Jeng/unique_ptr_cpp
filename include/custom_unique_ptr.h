#pragma once

#include "custom_default_delete.h"
#include <cstddef>

namespace ctm
{
template <class T, class Delete = ctm::default_delete<T>>
class unique_ptr
{
public:
    using pointer = T;

    constexpr unique_ptr() noexcept = default;

    constexpr unique_ptr(std::nullptr_t) noexcept {}

    explicit unique_ptr(pointer p) noexcept:
        ptr(p) {}




private:
    T* ptr;
};
}