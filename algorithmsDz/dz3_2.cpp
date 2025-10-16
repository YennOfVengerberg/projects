#include <iostream>
#include <vector>
using namespace std;

// Функция вычисляет количество интересующих пар и одновременно сортирует массив
long long merge_and_count(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1); // Временный буфер для объединения
    
    int i = left, j = mid + 1, k = 0;
    long long count = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) { // Элементы расположены правильно
            temp[k++] = arr[i++];
        }
        else { // Здесь возникает интересная пара
            temp[k++] = arr[j++];
            count += (mid - i + 1); // Все элементы слева больше текущего элемента справа
        }
    }
    
    // Добавляем оставшиеся элементы
    while(i <= mid)
        temp[k++] = arr[i++];
        
    while(j <= right)
        temp[k++] = arr[j++];
    
    // Копируем временный массив назад в оригинальный
    for(int p = left; p <= right; ++p)
        arr[p] = temp[p-left];
    
    return count;
}

// Рекурсивная функция разделения массива и подсчета пар
long long count_pairs(vector<int>& arr, int left, int right) {
    if(left >= right)
        return 0;
    
    int mid = left + (right - left)/2;
    
    // Подсчет пар внутри двух половинок
    long long x = count_pairs(arr, left, mid);
    long long y = count_pairs(arr, mid+1, right);
    
    // Объединение и подсчет перекрестных пар
    long long z = merge_and_count(arr, left, mid, right);
    
    return x+y+z;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    
    cout << "Количество интересных пар: " << count_pairs(arr, 0, n-1) << endl;
    
    return 0;
}
