// Find the unique element in an array which only appear once in an entire array
// Brute Force
#include <bits/stdc++.h>
using namespace std;

int uele(vector<int> v)
{
    int ans = 0; // 0 xor 0 = 0,0 xor ele =ele isiliye ans ko 0 set kiya hai
    for (int i = 0; i < v.size(); i++)
    {
        ans = ans ^ v[i];
    };
    return ans;
}
int main()
{
    vector<int> v{1, 2, 1, 4, 6, 4, 2, 5, 3, 5};
    int ele = uele(v);
    cout << "Unique element in array is " << ele;
    return 0;
}

// Approach : XOR operation karenge kyuki vo same ke case me 0 ans deta hai or different ke case me 1 deta hai
// means vo same element ko cancel kr deta hai to hum vo v ke element me xor kr denge