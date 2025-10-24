#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int str_size;
    cin >> str_size;
    string str;
    cin >> str;
    int z = count(str.begin(), str.end(), 'z');
    int n = count(str.begin(), str.end(), 'n');
    while ( z != 0 || n != 0)
    {
        for(; n > 0; n--) cout << 1 << " ";
        for (; z > 0; z--) cout << 0 << " ";

    }

}
