// QUESTION : return true or false if there is any redundant bracket in the expression
// LOGIC : if there is an operator between a closing and opening bracket then it a valid bracket pair
#include <bits/stdc++.h>
using namespace std;
bool validex(stack<char> &ch, bool op)
{
    // base case
    if (ch.top() == '(')
    {
        ch.pop();
        return op;
    }
    if (ch.top() == '+' || ch.top() == '-' || ch.top() == '*' || ch.top() == '/')
    {
        op = true;
        ch.pop();
        return validex(ch, op);
    }
    else
    {
        op = false;
        return validex(ch, op);
    }
}
int main()
{

    stack<char> ch;
    bool op = false;
    bool f;
    string s;
    cout << "enter your expression ";
    cin >> s;
    int i = 0;
    for (; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            ch.push(s[i]);
        }
        else if (s[i] == ')')
        {
            bool f = validex(ch, op);
            if (f == false)
                break;
        }
    }
    if (i == s.length())
        cout << " there is no redundant brackets ";
    else
        cout << "there is redundant bracket in expression ";
    return 0;
}