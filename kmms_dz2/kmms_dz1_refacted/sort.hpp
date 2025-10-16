#ifndef SORTS_HPP
#define SORTS_HPP

namespace sorts {
    void merge(int *vec, int left, int mid, int right);
    void insertionSort(int *vec, const int size);
    void modifiedMergeSort(int *vec, int left, int right, int threshold, const int size);
}
#endif