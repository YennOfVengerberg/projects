#include <iostream>
#include <vector>
using namespace std;

const int MAX_K = 100000; // максимальная возможная величина K

// Предварительная подготовка
void preprocess(const vector<int>& arr, vector<int>& freq_sums) {
    for (auto x : arr) {
        freq_sums[x]++;
    }
    // Преобразуем в префиксные суммы
    for (int i = 1; i < MAX_K; ++i) {
        freq_sums[i] += freq_sums[i - 1];
    }
}

// обработка за O(1)
int count_in_range(const vector<int>& freq_sums, int l, int r) {
    if (l == 0) return freq_sums[r];
    return freq_sums[r] - freq_sums[l - 1];
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> freq_sums(MAX_K, 0); // Массив для хранения частот
    preprocess(arr, freq_sums);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << count_in_range(freq_sums, l, r) << "\\n";
    }

    return 0;
}
