#ifndef SORTS_HPP
#define SORTS_HPP

namespace sorts {
    void merge(int *array, int left, int mid, int right);
    void insertionSort(int *array, const int array_size);
    void modifiedMergeSort(int *array, int left, int right, int threshold, const int array_size);
}
#endif