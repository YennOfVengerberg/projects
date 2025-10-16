#include <random>
#include "sort.hpp"
#include "io.hpp"

int main() {
    int size;
    int max_roof;
    io::inp("Введите размер ", size);
    int *vec = new int[size];
    io::inp("Введите максимум числа ", max_roof);
    double threshold = sqrt(size);
    std::mt19937 mt(time(0));

    for(int i = 0; i < size; i++) vec[i] = mt() % max_roof;
    io::printer("До сортировки ", vec, size);
    sorts::modifiedMergeSort(vec, 0, size - 1, threshold, size);
    io::printer("После сортировки ", vec, size); 
}