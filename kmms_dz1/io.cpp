#include "io.hpp"

void io::printer(const std::string str, std::vector<int> vec, const int n)
{
    std::cout << str << std::endl;
    for(int i = 0; i < n; i++) std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void io::inp(const std::string text, int &n)
{
    std::cout << text << std::endl;
    std::cin >> n;
}