#ifndef IO_HPP
#define IO_HPP

#include <iostream>

namespace io {
    void print(const std::string str, int *array, const int array_size);
    void input(const std::string text, int &n);
}
#endif