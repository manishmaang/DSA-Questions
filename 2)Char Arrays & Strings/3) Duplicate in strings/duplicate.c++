<<<<<<< HEAD
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing
// two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made.
// It can be proven that the answer is unique.

// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only
// possible move.The result of this move is that the string is "aaca",of which only "aa" is possible,
// so the final string is "ca".

#include <bits/stdc++.h>
using namespace std;

string Remove_duplicates(string s)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        if (ans.length() > 0)
        {
            if (ans[ans.length() - 1] == s[i])
            {
                ans.pop_back();
            }
            else
                ans.push_back(s[i]);
        }
        else
        {
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}
int main()
{
    string s = "abbaca";
    string ans = Remove_duplicates(s);
    cout << "String without duplicate element is : " << ans << endl;
    return 0;
=======
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing
// two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made.
// It can be proven that the answer is unique.

// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only
// possible move.The result of this move is that the string is "aaca",of which only "aa" is possible,
// so the final string is "ca".

#include <bits/stdc++.h>
using namespace std;

string Remove_duplicates(string s)
{
    string ans = "";
    int i = 0;
    while (i < s.length())
    {
        if (ans.length() > 0)
        {
            if (ans[ans.length() - 1] == s[i])
            {
                ans.pop_back();
            }
            else
                ans.push_back(s[i]);
        }
        else
        {
            ans.push_back(s[i]);
        }
        i++;
    }
    return ans;
}
int main()
{
    string s = "abbaca";
    string ans = Remove_duplicates(s);
    cout << "String without duplicate element is : " << ans << endl;
    return 0;
>>>>>>> edc2ed130985a34e0e29cc3f47806a5d8c2f15aa
}