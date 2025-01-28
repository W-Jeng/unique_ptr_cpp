#include "custom_unique_ptr.h"
#include<utility>

namespace ctm
{

template< class T, class... Args >
constexpr ctm::unique_ptr<T> make_unique(Args&&... args)
{
    return ctm::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}