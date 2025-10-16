#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{   
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        int a;
        cin >> a;
        vector<int> vec(a);
        for(int j = 0; j < vec.size(); j++) cin >> vec[j];
        sort(vec.begin(), vec.end());
        bool flag = true;
        for(int i = 0; i < vec.size()-1;i++)
        {
            if( abs(vec[i] - vec[i+1] ) > 1)
            {
                flag = false;
                break;
            }
        }
        if (flag == false) cout << "NO" << endl;
        else cout << "YES" << endl;


    }
}