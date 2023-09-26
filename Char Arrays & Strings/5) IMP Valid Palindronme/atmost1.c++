<<<<<<< HEAD
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
#include <bits/stdc++.h>
using namespace std;

bool check(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false; // agr yha false aaya mtlb ek remove krne ke baad bhi palindrome nhi hai isiliye direct false return krdia
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            // ek baar left se or ek baar right se htake check karenge
            return check(s, i + 1, j) || check(s, i, j - 1); // atmost 1 removed
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter string : ";
    cin >> s;
    bool k = validPalindrome(s);
    if (k)
        cout << "palindrome";
    else
        cout << "not palindrome";
    return 0;
=======
// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:

// Input: s = "aba"
// Output: true
#include <bits/stdc++.h>
using namespace std;

bool check(string s, int i, int j)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false; // agr yha false aaya mtlb ek remove krne ke baad bhi palindrome nhi hai isiliye direct false return krdia
        i++;
        j--;
    }
    return true;
}
bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            // ek baar left se or ek baar right se htake check karenge
            return check(s, i + 1, j) || check(s, i, j - 1); // atmost 1 removed
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter string : ";
    cin >> s;
    bool k = validPalindrome(s);
    if (k)
        cout << "palindrome";
    else
        cout << "not palindrome";
    return 0;
>>>>>>> edc2ed130985a34e0e29cc3f47806a5d8c2f15aa
}