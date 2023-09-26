// //TYPE : COIN CHANGE PROBLEM BASED ON INCLUDE AND EXCLUDE PATTERN
// // PROBLEM 1 : WE ARE GIVEN AN ARRAY OF DISTINCT INT ELEMENTS AND A TARGET, WE HAVE TO FIND THE MINIMUM NUMBER OF
// //           ELEMENTS REQUIRED TO REACH THE TARGET
// // EXAMPLE : arr = [1,2,3]  target = 5     ANS = 2 coz to reach 5 we only need 2 elements which are [2,3]
// #include <bits/stdc++.h>
// using namespace std;
// int solve(vector<int> &arr, int target)
// {
//     // base cases
//     if (target == 0) // mere pass 0 hai or muje 0 banana hai to muje 0 element lagenge(koi element nhi lagega)
//     {
//         return 0;
//     }
//     if (target < 0)
//     {
//         return INT_MAX;
//     }
//     // ek case solve krlo
//     int mini = INT_MAX;
//     for (int i = 0; i < arr.size(); i++) // ek target ke liye arr ki sare element ki call ja rhi hai
//     {
//         int ans = solve(arr, target - arr[i]); // is ans me jo value aayegi vo target-arr[i] ke liye aayegi

//         if (ans != INT_MAX)
//             ans += 1; // ans me target-arr[i] ki value aayi thi to use shi krne ke liye +1 kiya kyuki target tk
//             //phochne ke liye ek element or lagega sbse pehla element(see in recursiev tree)
//         mini = min(mini, ans);
//     }
//     return mini;
// }
// int main()
// {
//     vector<int> arr;
//     int n;
//     cout << "enter the size of array : ";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int j;
//         cin >> j;
//         arr.push_back(j);
//     }
//     int target;
//     cout << "enter target : ";
//     cin >> target;
//     cout << "minimum number of element required to reach target is : " << solve(arr, target);
//     return 0;
// }

// PROBLEM 2 : HUME EK ROD DI GYI HAI OF SIZE N HUME USE MAX NO. OF SEGMENTS ME BAATNA HAI VO BHI X,Y,Z LENGTH ME\
// AGR SEGMENTS ME NHI BAAT SKTE TO 0 RETURN KRNA HAI (X,Y,Z LENGTH QUESTION ME PEHEL SE GIVEN HONGE)

#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &v)
{
    if (n == 0)
    {
        return 0;
    }

    int maxi = INT_MIN;

    for (int i = 0; i < v.size(); i++)
    {
        int ans = 0;
        if (n - v[i] >= 0)
        {
            ans = solve(n - v[i], v) + 1;
            maxi = max(ans, maxi);
        }
    }
    return maxi;
}

int main()
{
    int n = 7;
    vector<int> v{3, 2, 2}; // ISKA ANS 3 HOGA KYUKI 7 KO HUM MAX 3 SEGMENTS ME BAAT SKTE HAI (3+2+2=7)
    int m = solve(n, v);
    if (m < 0)
        m = 0;
    cout << m;
    return 0;
}