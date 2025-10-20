#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

void merge(vector<int> &vec, int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    vector<int> leftVec(size1);
    vector<int> rightVec(size2);
    
    for (int i = 0; i < size1; i++) leftVec[i] = vec[left + i];
    for (int j = 0; j < size2; j++) rightVec[j] = vec[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2){
        if (leftVec[i] <= rightVec[j]){
            vec[k] = leftVec[i];
            i++;
        }
        else{
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    
}

void insertionSort(vector<int> &vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void modifiedMergeSort(vector<int> &vec, int left, int right, int threshold)
{
    if (right - left + 1 <= threshold) insertionSort(vec);
    else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            modifiedMergeSort(vec, left, mid, threshold);
            modifiedMergeSort(vec, mid + 1, right, threshold);
            merge(vec, left, mid, right);
        }
    } 
}

int main()
{
    vector<int> vec;
    int n;
    cout << "Введите число элементов: ";
    cin >> n;
    double threshold = 0;
    mt19937 mt(time(0));
    for(int i = 0; i < n; i++) {
        vec.push_back(mt() % 10000); // лимит 10000 для примера, 10^7
        //cout << vec[i] << " ";
    }
    chrono::duration<double> before = 1h;
    for(int i = 1; i < sqrt(n); i++) {
        auto start = chrono::steady_clock::now();
        vector<int> vec_copy = vec;
        modifiedMergeSort(vec_copy, 0, n - 1, i);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed = end - start;
        if (elapsed < before) {
            before = elapsed;
            threshold = i;
            cout << before.count() << " "<< threshold << endl;
        }
    }
    //cout << endl << "Отсортированный массив: "; 
    //for (int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << endl << " граница " << threshold;
    // 1000 - 18-31, 10000 - 38-93, 100'000+ ~ sqrt(n)
    // в среднем граница перехода(m) стремится к sqrt(n)
}