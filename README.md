# Custom Unique Pointer Implementation

## Overview
This project provides a simplified implementation of `std::unique_ptr` and `std::default_delete`. It includes:
- A custom `default_delete` that deletes dynamically allocated objects and prints a message.
- A custom `unique_ptr` that manages exclusive ownership of a dynamically allocated object.

## Files
- **custom_default_delete.h**: Implements a default deleter that deletes pointers and array pointers.
- **custom_unique_ptr.h**: Implements a unique pointer class that ensures exclusive ownership of dynamically allocated objects.

## Features
### `default_delete<T>`
- Deletes a single object of type `T`.
- Overloaded `operator()` ensures proper deletion.
- Prints a message upon deletion.
- Specialization for array deletion `default_delete<T[]>`.

### `unique_ptr<T>`
- Manages a dynamically allocated object.
- Deleted copy constructor to enforce unique ownership.
- Move constructor and move assignment operator to allow ownership transfer.
- `operator*` and `operator->` for pointer-like access.
- `release()`, `reset()`, and `swap()` for pointer management.
- `make_unique<T>` function for safe object allocation.

## Usage
### Creating and Using `unique_ptr`
```cpp
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
```
### Output
```
p has an active pointer
do something
Deleted the pointer!
Deleted the pointer!
```

## Compilation
Compile your program with:
```sh
mkdir build
cd build
cmake ..
cmake --build .
```

## To run
```sh
./bin/main
```

## Notes
This is obviously a simplified version of unique_ptr and is intended for educational purposes. It does not fully replicate all the features of std::unique_ptr from the C++ standard library.

### Missing Features
Array Support: While the default_delete struct supports arrays, the unique_ptr implementation does not currently provide specialized support for managing arrays (e.g., unique_ptr<T[]>). This could be added in future updates.
