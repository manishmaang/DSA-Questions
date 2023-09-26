// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

// NOTE : WE CAN IMPROVE THIS CODE BY USING MEMOIZATION
#include <bits/stdc++.h>
using namespace std;
int ClimbStairs(int n)
{
    if (n == 2)
    {
        return 2;
    }
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return ClimbStairs(n - 1) + ClimbStairs(n - 2);
}

int main()
{
    cout << "Enter the number of stairs : ";
    int n;
    cin >> n;
    cout << "The number of ways to climb the staris are : " << ClimbStairs(n);
    return 0;
}