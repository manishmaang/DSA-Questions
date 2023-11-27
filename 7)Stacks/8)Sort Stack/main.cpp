// sort stack
// brute force : copy data in array and then sort array and paste data in stack again
// can also do using recursion
#include <bits/stdc++.h>
using namespace std;
void insertsortorder(stack<int> &s, int &target)
{
    // base case
    if (s.empty())
    {
        s.push(target);
        return;
    }

    // another base case
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }

    // normal case
    int top = s.top();
    s.pop();
    insertsortorder(s, target);

    // back tracking jo pop kiya tha use wps push krdo
    s.push(top);
}
void sortstack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    // normal case
    int top = s.top();
    s.pop();

    sortstack(s);
    insertsortorder(s, top);
}

int main()
{
    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(10);
    s.push(50);
    s.push(40);
    sortstack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}