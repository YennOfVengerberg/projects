#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    unsigned int n; 
    cin >> n;
    int *vec = new int[n];
    for(int i = 0; i < n; i++){
        vec[i] = i;
        cout << vec[i];
    }

}