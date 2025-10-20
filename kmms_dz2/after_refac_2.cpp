#include <iostream>

int main() {
    const int size = 10;
    double a[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Введите " << i+1 << " элемент " << std::endl;
        std::cin >> a[i];
    }

    bool is_increasing = true;
    for(int i = 0; i < size-1; i++) {
        if (a[i] > a[i + 1]) {
            is_increasing = false;
            break;
        }
    }

    if (is_increasing) {
        std::cout << "Последовательность возрастающая" << std::endl;
    } else {
        std::cout << "Последовательность невозрастающая " << std::endl;
    }
    return 0;
}