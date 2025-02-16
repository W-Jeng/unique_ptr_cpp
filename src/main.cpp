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

    void do_something()
    {
        std::cout << "do something" << std::endl;
    }
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

    p -> do_something();

    auto z = ctm::make_unique<Abc>(2, 3);

    return 0;
}