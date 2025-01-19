#include "custom_unique_ptr.h"
#include "custom_default_delete.h"
#include <iostream>

struct Abc
{
    int a;
    int b;

    Abc(int a_, int b_):
        a(a_),
        b(b_) {}
};

int main()
{
    ctm::unique_ptr<Abc> p(new Abc(1, 2));

    if (p)
    {
        std::cout << "p has an active pointer" << std::endl;
    }
    else
    {
        std::cout << "p is nullptr" << std::endl;
    }

    p.reset();
    std::cout << "p is resetted." << std::endl;

    if (p)
    {
        std::cout << "p has an active pointer" << std::endl;
    }
    else
    {
        std::cout << "p is nullptr" << std::endl;
    }

    return 0;
}