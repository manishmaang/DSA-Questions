// PROBLEM : IN THIS PROBLEM WE HAVE TO UNION 2 ARRAYS WITH IN AN ANS ARRAY CONSISTING ONLY UNQUE ELEMENTS
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> brr = {2, 3, 6, 7, 8};
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == brr[j])
                brr[j] = INT_MIN;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i]);
    }
    for (int i = 0; i < brr.size(); i++)
    {
        if (brr[i] != INT_MIN)
            ans.push_back(brr[i]);
    }
    for (auto value : ans)
    {
        cout << value << " ";
    }
    return 0;
}