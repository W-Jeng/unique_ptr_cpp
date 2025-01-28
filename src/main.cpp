#include "custom_unique_ptr.h"
#include "custom_default_delete.h"
#include <iostream>
#include "custom_make_unique.h"

struct Abc
{
    int a;
    int b;

    Abc(int a_, int b_):
        a(a_),
        b(b_) {}

    void do_something()
    {
        std::cout << "calling from do something, a: " << a << ", b: " << b << std::endl;
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

    ctm::unique_ptr<Abc> z = ctm::make_unique<Abc>(3, 4);
    z -> do_something();

    return 0;
}