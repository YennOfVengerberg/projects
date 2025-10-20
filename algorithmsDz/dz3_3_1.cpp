#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool binary_search(const vector<int> &vec, int left, int right, int key, int S) {
    if( left > right ) {
        return false;
    }
    int mid = left + (right - left) / 2;
    if (vec[mid] + key == S) {
        return true;
    }
    else if (vec[mid] + key < S) {
        return binary_search(vec, mid + 1, right, key, S);
    } else {
        return binary_search(vec, left, mid - 1, key, S);
    }
}

int main() {
    srand(time(nullptr));
    unsigned int S = rand();
    cout << S << endl;
    cout << "введите размер " << endl;
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cout << "введите ключ " << endl;
    int key;
    cin >> key;
    int pairs = 0;
    for(int i = 0; i < vec.size();i++) {
        if(binary_search(vec, 0, n-1, vec[i], S)) pairs++;
    }
    cout << "количество пар: " << pairs/2 << endl;
}