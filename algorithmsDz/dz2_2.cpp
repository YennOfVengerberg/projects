#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    int n, q, k;
    cin >> n >> k >> q; // n Длина k лимит чисел q количество запросов
    vector<int> vec(n);
    mt19937 mt(time(nullptr));
    for (int i = 0; i < n; i++) vec[i] = mt() % (k-1);

    int cntr = 0;
    for(; q > 0; q--)
    {
        int l, r;
        cout << "set range l to r " << endl; // отрезок
        cin >> l >> r;
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] <= r && vec[i] >= l) cntr++; // 
        }

    }

    cout << cntr;

}