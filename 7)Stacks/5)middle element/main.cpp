// find the middle element of stack without removing any element
//  approach : recursion;
#include <bits/stdc++.h>
using namespace std;
int middleElement(stack<int> &s, int &size)
{
    if (s.size() == 0)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        if (s.size() == size)
        {
            return s.top();
        }
        int temp = s.top();
        s.pop();
        int q = middleElement(s, size);
        s.push(temp);
        return q;
    }
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    int size = (s.size() / 2) + 1;
    int q = middleElement(s, size);
    cout << q << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}