/*
Problem Description
A math game is introduced in a school competition to test the skills of students. The game deals with Prime numbers.

The game rules are as follows:

From the given set of distinct natural numbers as input, consider the smallest natural number as q.
Your task is to compute the smallest prime number (p) such that when p is divided by all the distinct numbers in the input, except q, should result q as the remainder.
Constraints
1 < n < 11

p < 10 ^ 10

Input
Input consists of n+1 number of distinct natural numbers separated by spaces.

Output
Print single integer p if such a p exists, else print "None".

Time Limit (secs)
1

Examples
Input

3 4 5 1

Output
61

Explanation
Here the n+1 numbers are 3, 4, 5 and 1 where q=1 (the least of the numbers)

The smallest number that leaves remainder 1 when divided by 3, 4 and 5 is 61 and is prime. Hence, output is 61.

Example 2

Input
3 4 5 2

Output
None

Explanation
Here q=2. Any number that when divided by 4 leaving remainder 2 must be an even number e.g., 6, 10, 14 etc. Hence it can't be prime. Hence, output is "None"*/
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &v, int &q, int p, int &n)
{
    for (int i = 1; i < n; i++)
    {
        if (p % v[i] != q)
            return false;
    }
    return true;
}
bool isprime(long long p)
{
    if (p < 2)
        return false;
    for (int i = 2; i * i <= p; i++)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}
void sprime(vector<int> &v, int &q, int &n)
{
    long long p = v[n - 1] + 1;
    long long m = 10 * 10;
    while (true)
    {
        if (p >= m)
        {
            cout << " None " << endl;
            return;
        }
        if (isprime(p))
        {
            bool k = check(v, q, p, n);
            if (k)
            {
                cout << p << endl;
                return;
            }
        }
        p++;
    }
}
int main()
{
    int n, q;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    q = v[0];
    sprime(v, q, n);
    return 0;
}