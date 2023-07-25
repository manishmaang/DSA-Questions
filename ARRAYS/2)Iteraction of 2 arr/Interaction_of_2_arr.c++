#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {
        1,
        2,
        3,
        3,
        4,
        6,
        8,
    };
    vector<int> brr = {3, 3, 4, 10}; // agr mark nhi krte to 3 -> 4 baar print hota
    vector<int> crr;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr.size(); j++)
        {
            if (arr[i] == brr[j])
            {
                brr[j] = INT_MIN; // taki ye wala element kisi or se match na ho to avoid duplicates of same number
                crr.push_back(arr[i]);
            }
        }
    }

    // NEW WAY OF WRITING FOR LOOP ONLY FOR PRINTING AN ARRAY NAME =>FOR EACH LOOP
    for (auto value : crr)
    {
        cout << value << " ";
    }
    return 0;
}