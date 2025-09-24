#include "sort.hpp"

void sorts::merge(std::vector<int> &vec, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    std::vector<int> leftVec(size1);
    std::vector<int> rightVec(size2);
    for (int i = 0; i < size1; i++) leftVec[i] = vec[left + i];
    for (int j = 0; j < size2; j++) rightVec[j] = vec[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2)
    {
        if (leftVec[i] <= rightVec[j])
        {
            vec[k] = leftVec[i];
            i++;
        }
        else
        {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    
}

void sorts::insertionSort(std::vector<int> &vec)
{
    int n = vec.size();
    for (int i = 1; i < n; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void sorts::modifiedMergeSort(std::vector<int> &vec, int left, int right, int threshold)
{
    if (right - left + 1 <= threshold) insertionSort(vec);
    else
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            modifiedMergeSort(vec, left, mid, threshold);
            modifiedMergeSort(vec, mid + 1, right, threshold);
            merge(vec, left, mid, right);
        }
    }
}