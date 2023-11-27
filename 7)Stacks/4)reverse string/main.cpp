// QUESTION : REVERSE A STRING WITH THE HELP OF A STACK
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> st;
    string s;
    cout << "enter a string : ";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}