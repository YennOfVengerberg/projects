#include <iostream>
#include <vector>
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
        for(int i = 0; i < vec.size(); i++) 
        {
            for(int j = 0; j < vec.size(); j++) 
            {   
                if (i == j) continue;
                if(abs(vec[i] - vec[j]) <= 1) 
                {
                    if ( vec[i] <= vec[j] ) 
                    {
                        vec.erase(vec.begin()+i);
                        i = 0;
                        j = 0;
                    }
                    else 
                    {
                        vec.erase(vec.begin()+j);
                        i = 0;
                        j = 1;
                    }
                }
            }
            
        }
        if (vec.size() == 1) cout << "YES" << endl;
        else cout << "NO" << endl;


    }
}