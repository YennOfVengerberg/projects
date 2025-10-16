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

    for(int i = 1; i < vec.size(); i++) {
        if(i % 2 != 0) {
            if (vec[i] > vec[i-1]) swap(vec[i], vec[i-1]);
        } else {
            if (vec[i] < vec[i-1])swap(vec[i], vec[i-1]);
        }

    }
    
    

    for(int i = 0; i < vec.size(); i++ ) cout << vec[i] << " ";
}