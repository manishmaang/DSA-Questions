#include <bits/stdc++.h>
using namespace std;
void bottominsert(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    bottominsert(s, target);
    s.push(temp);
}
// reverse top element ko nikl rha jb tk stack empty nhi ho jata
// fir hum insetatbottom krte hai
// to sbse pehle 10 insert hoga fir insert at bottom se 20 fir 30 fir 40 fir 50
// to ese stack reverse ho jayega
void reverse(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    int target = s.top();
    s.pop();

    // reverse kro stack ko fir insert at bottom
    reverse(s);

    // insert at bottom
    bottominsert(s, target);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}