// NOTE : when I will study hash table then I can reduce the time complexity of this
// question to O(n) my current TC is O(nlogn)

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <bits/stdc++.h>
using namespace std;

void isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        cout << "It is not a valid anagram ";
        return;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < t.length(); i++)
    {
        if (s[i] != t[i])
        {
            cout << "It is not a valid anagram ";
            return;
        }
    }
    cout << "It is a valid anagram ";
}
int main()
{
    string s, t;
    cout << "Enter a string : ";
    cin >> s;
    cout << "Enter valid or invalid anagram : ";
    cin >> t;
    isAnagram(s, t);
    return 0;
}
