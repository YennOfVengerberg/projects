#include "sort.hpp"

void sorts::merge(int *array, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int *left_part = new int(size1);
    int *right_part = new int(size2);
    for (int i = 0; i < size1; i++) left_part[i] = array[left + i];
    for (int j = 0; j < size2; j++) right_part[j] = array[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < size1 && j < size2) {
        if (left_part[i] <= right_part[j]) {
            array[k] = left_part[i];
            i++;
        } else {
            array[k] = right_part[j];
            j++;
        }
        k++;
    }
}

void sorts::insertionSort(int *array, const int array_size) {
    for (int i = 1; i < array_size; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void sorts::modifiedMergeSort(int *array, int left, int right, int threshold, const int array_size) {
    if (right - left + 1 <= threshold) {
        insertionSort(array, array_size);
    } else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            modifiedMergeSort(array, left, mid, threshold, array_size);
            modifiedMergeSort(array, mid + 1, right, threshold, array_size);
            merge(array, left, mid, right);
        }
    }
}