#include <random>
#include "sort.hpp"
#include "io.hpp"


using namespace std;

int main()
{
    vector<int> vec;
    int n;
    int max_roof;
    io::inp("Введите размер массива ", n);
    io::inp("Введите верхний предел чисел ", max_roof);
    double threshold = sqrt(n);
    mt19937 mt(time(0));

    for(int i = 0; i < n; i++) vec.push_back(mt() % max_roof);
    io::printer("До сортиорвки ", vec, n);
    sorts::modifiedMergeSort(vec, 0, n - 1, threshold);
    io::printer("Отсортированный массив: ", vec, n); 

}