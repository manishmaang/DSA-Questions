<<<<<<< HEAD
// Given a string s, return the number of palindromic substrings in it.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#include <bits/stdc++.h>
using namespace std;
int evenOdd(string s, int i, int j)
{
    int count = 0;
    // jb tk s[i]==s[j] hoga tb tk hi chlega fir humne i-- or j++ kiya to baad me pehli 2 conditions check hongi
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // checking for odd substring
        int ans = evenOdd(s, i, i); // i is a centre index for odd palindrome thats why i=j, or i ke around hum s ko expand krte hai or palindrome check krte hai
        count = count + ans;

        // checking for even substring
        int ans1 = evenOdd(s, i, i + 1); // i and j are centre index for even palindrome or unke around hum s ko expand krte hai or palindrome check krte hai
        count = count + ans1;
    }
    return count;
}

int main()
{
    string s;
    cout << "enter the string : ";
    cin >> s;
    int count = countSubstrings(s);
    cout << "number of palindromes in " << s << " are " << count;
    return 0;
=======
// Given a string s, return the number of palindromic substrings in it.

// Example 1:
// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#include <bits/stdc++.h>
using namespace std;
int evenOdd(string s, int i, int j)
{
    int count = 0;
    // jb tk s[i]==s[j] hoga tb tk hi chlega fir humne i-- or j++ kiya to baad me pehli 2 conditions check hongi
    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstrings(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // checking for odd substring
        int ans = evenOdd(s, i, i); // i is a centre index for odd palindrome thats why i=j, or i ke around hum s ko expand krte hai or palindrome check krte hai
        count = count + ans;

        // checking for even substring
        int ans1 = evenOdd(s, i, i + 1); // i and j are centre index for even palindrome or unke around hum s ko expand krte hai or palindrome check krte hai
        count = count + ans1;
    }
    return count;
}

int main()
{
    string s;
    cout << "enter the string : ";
    cin >> s;
    int count = countSubstrings(s);
    cout << "number of palindromes in " << s << " are " << count;
    return 0;
>>>>>>> edc2ed130985a34e0e29cc3f47806a5d8c2f15aa
}