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
    std::cout << "hello world!" << std::endl;
    Abc* ptr = new Abc(1, 2);

    ctm::default_delete<Abc> dd;

    dd(ptr);

    return 0;
}