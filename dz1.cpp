#include <iostream>
#include <vector>
#include <ctime>

using namespace std;
int main()
{
    srand(time(0));
    int size;
    cin >> size;
    vector<int> vec(size);
    for(int i = 0; i < vec.size(); i++) vec[i] = rand();

    for(int i = 0; i < vec.size(); i++ ) cout << vec[i] << " ";
    cout << endl;

    for(int i = 0; i < vec.size()-1; i++)
    {
        if(i % 2 != 0) 
        {
             int temp;
            if (vec[i-1] >= vec[i+1]) temp = i-1;
            else temp = i+1;
            swap(vec[i], vec[temp]);
        }
    }
    
    

    for(int i = 0; i < vec.size(); i++ ) cout << vec[i] << " ";
}