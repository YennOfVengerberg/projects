#ifndef SORTS_HPP
#define SORTS_HPP

#include <vector>

namespace sorts
{
    void merge(std::vector<int> &vec, int left, int mid, int right);
    void insertionSort(std::vector<int> &vec);
    void modifiedMergeSort(std::vector<int> &vec, int left, int right, int threshold);
}
#endif