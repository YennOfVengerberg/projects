#include "io.hpp"

void io::printer(const std::string str, int *vec, const int size) {
    std::cout << str << std::endl;
    for(int i = 0; i < size; i++) {
        std::cout << *(vec+i) << " ";
    }
    std::cout << std::endl;
}

void io::inp(const std::string text, int &n) {
    std::cout << text << std::endl;
    std::cin >> n;
}