#include "io.hpp"

void io::print(const std::string str, int *array, const int array_size) {
    std::cout << str << std::endl;
    for(int i = 0; i < array_size; i++) {
        std::cout << *(array+i) << " ";
    }
    std::cout << std::endl;
}

void io::input(const std::string text, int &n) {
    std::cout << text << std::endl;
    std::cin >> n;
}