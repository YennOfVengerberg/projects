#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> skills(n);
    for (int i = 0; i < n; i++) cin >> skills[i];
    sort(skills.begin(), skills.end());
    int sum = 0;
    for(int i = 0; i < skills.size()-1; i += 2 )
    {
        sum += abs(skills[i] - skills[i+1]);
    }
    cout << sum;
}