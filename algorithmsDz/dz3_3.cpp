#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void merge(vector<int> &vec, int left, int mid, int right, vector<int> &vec_ind) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    vector<int> leftVec(size1);
    vector<int> rightVec(size2);

    for (int i = 0; i < size1; i++) leftVec[i] = vec[left + i];
    for (int j = 0; j < size2; j++) rightVec[j] = vec[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            vec_ind[k] = i;
            i++;
        }
        else {
            vec[k] = rightVec[j];
            vec_ind[k] = j;
            j++;
        }
        k++;
    }
    
}

void insertionSortWIndex(vector<int> &vec, vector<int> &vec_ind) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            vec_ind[j+1] = vec_ind[j];
            j--;
        }
        vec[j + 1] = key;
        vec_ind[j + 1] = i;
    }
}

void modifiedMergeSortWIndex(vector<int> &vec, int left, int right, int threshold, vector<int> &vec_ind)
{
    if (right - left + 1 <= threshold) insertionSortWIndex(vec, vec_ind);
    else {
        if (left < right) {
            int mid = left + (right - left) / 2;
            modifiedMergeSortWIndex(vec, left, mid, threshold, vec_ind);
            modifiedMergeSortWIndex(vec, mid + 1, right, threshold, vec_ind);
            merge(vec, left, mid, right, vec_ind);
        }
    }
}

int main() {
    srand(time(nullptr));
    unsigned int S = rand();
    cout << S << endl;
    cout << "введите размер" << endl;
    int n;
    cin >> n;

    vector<int> vec_ind(n);
    vector<int> vec_nums(n);

    for(int i = 0; i < n; i++) {
        cin >> vec_nums[i];
        vec_ind[i] = i;
    }

    /* for(int i = 0; i < n; i++) {
        cout << vec_nums[i] << " ";
        cout << vec_ind[i] << " ";
    }
    cout << endl; */

    modifiedMergeSortWIndex(vec_nums, 0, n-1, 100, vec_ind );
    for(int i = 0; i < n; i++) cout << vec_nums[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << vec_ind[i] << " ";
    cout << endl;

    int pairs = 0;
    for(int i = 0; i < n-1; i++) {
        if (vec_nums[i] + vec_nums[i+1] == S) {
            pairs++;
            cout << vec_ind[i] << ", " << vec_ind[i+1] << endl;
        }
    }
    if (pairs == 0) cout << "нет пар ";

}