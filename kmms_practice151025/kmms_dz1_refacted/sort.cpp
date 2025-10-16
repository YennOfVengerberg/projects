#include "sort.hpp"
void sorts::merge(int *vec, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int *leftVec = new int(size1);
    int *rightVec = new int(size2);
    for (int i = 0; i < size1; i++) leftVec[i] = vec[left + i];
    for (int j = 0; j < size2; j++) rightVec[j] = vec[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    
}

void sorts::insertionSort(int *vec, const int size) {
    for (int i = 1; i < size; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void sorts::modifiedMergeSort(int *vec, int left, int right, int threshold, const int size) {
    if (right - left + 1 <= threshold) insertionSort(vec, size);
    else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            modifiedMergeSort(vec, left, mid, threshold, size);
            modifiedMergeSort(vec, mid + 1, right, threshold, size);
            merge(vec, left, mid, right);
        }
    }
}