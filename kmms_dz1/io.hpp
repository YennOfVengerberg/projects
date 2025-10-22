#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <vector>

namespace io
{
    void printer(const std::string str, std::vector<int> vec, const int n);
    void inp(const std::string text, int &n);
}


#endif