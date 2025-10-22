#include <random>
#include "io.hpp"
#include "sort.hpp"

int main() {
    int array_size;
    int num_limit;
    io::input("Введите размер ", array_size);
    io::input("Введите максимальное число ", num_limit);
    double threshold = sqrt(array_size);
    std::mt19937 mt(time(0));

    int *array = new int[array_size];
    for(int i = 0; i < array_size; i++) array[i] = mt() % num_limit;

    io::print("До сортировки ", array, array_size);
    sorts::modifiedMergeSort(array, 0, array_size - 1, threshold, array_size);
    io::print("После сортировки ", array, array_size); 
}