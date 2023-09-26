// PROBLEM : Print the all the sub-sequences of an array
// HomeWork : Do this question with bit-masking
#include <bits/stdc++.h>
using namespace std;

void printSub(string &s, string b, int i)
{
    if (i >= s.length())
    {
        cout << b << endl;
        return;
    }
    // excluding the current index char in b
    printSub(s, b, i + 1);

    // including the current index char in b
    b.push_back(s[i]);
    printSub(s, b, i + 1);
}
int main()
{
    string s, b = "";
    cout << "Enter a string : ";
    cin >> s;
    int i = 0;
    printSub(s, b, i);
    return 0;
}