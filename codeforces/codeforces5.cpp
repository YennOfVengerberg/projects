#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    int maxim = 0, minim = 1'000'000'001;
    for(int i = 0; i < n; i++)
    {
        vector<int> vec_inp(2);
        for(int j = 0; j < 2; j++) 
        {
            cin >> vec_inp[j];
            if (vec_inp[j] <= minim ) minim = vec_inp[j];
            if (vec_inp[j] >= maxim ) maxim = vec_inp[j]; 
        }
        vec.push_back(vec_inp);
    }

    int pos = -1;

    for(int n = 0; n < vec.size(); n++) if (vec[n][0] == minim and vec[n][1] == maxim) pos = n+1;

    cout << pos;
}