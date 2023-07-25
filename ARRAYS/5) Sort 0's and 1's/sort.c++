// PROBLEM : SORT 0'S AND 1'S IN AN ARRAY WITHOUT ANY SORTING ALGO
// HINT USE 2 POINTER APPROACH
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {0, 1, 0, 1, 1, 0, 1, 0, 1, 1};
    int start = 0;
    int i = 0;
    int end = v.size() - 1;
    while (i < end)
    {
        if (v[i] == 0)
        {
            // swap from left
            swap(v[i], v[start]);
            i++;
            start++;
        }

        if (v[i] == 1)
        {
            // swap from right
            swap(v[i], v[end]);
            // i++;
            end--;
        }
    }
    for (auto value : v)
    {
        cout << value << " ";
    }
}