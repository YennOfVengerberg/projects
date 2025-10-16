#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <random>
using namespace std;


vector<int> smooth_Nums(int max_value) 
{
    vector<int> sequence;
    int max_powers_two = log2(max_value); // максимальные степени двойки и тройки
    int max_powers_three = log(max_value) / log(3);

    for (int p = 0; p <= max_powers_two; p++) 
    {
        for (int q = 0; q <= max_powers_three; q++) 
        {
            int step = pow(2, p) * pow(3, q);
            if (step < max_value) sequence.push_back(step);
        }
    }

    sort(sequence.rbegin(), sequence.rend()); // сортировка по убыванию
    return sequence;
}

void shell_sort ( vector <int> &a ) 
{
    int n = a.size();
    vector<int> steps = smooth_Nums(n);
    for (int gap : steps) // перебор интервалов
    {
        for( int i = gap ; i < n ; i++ ) 
        {
            int temp = a[i];
            int j = i ;
            while (j >= gap && a[j-gap] > temp)
            {
                a[j] = a[j - gap]; // смена i элемента на интервальный(ближе к 0)
                j -= gap;
            }
            a[j] = temp; // отсортированное место
        }
    }
}




int main()
{
    mt19937 mt(time(nullptr));
    for(int N = 1000; N <= 1'000'000; N *= 10)
    {
        vector<int> vec(N);
        for(int i = 0; i < N; i++) vec[i] = mt();
        vector<int> vec_copy = vec;

        auto start = chrono::steady_clock::now();
        shell_sort(vec);
        auto end = chrono::steady_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Shell sort for size n " << N << " time elapsed " << elapsed.count() << endl;

        start = chrono::steady_clock::now();
        sort(vec_copy.begin(), vec_copy.end());
        end = chrono::steady_clock::now();
        elapsed = end - start;
        cout << "<algorithm> sort for size n " << N << " time elapsed " << elapsed.count() << endl;
        //for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
    }

}