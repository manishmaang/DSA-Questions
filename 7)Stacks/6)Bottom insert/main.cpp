#include <bits/stdc++.h>
using namespace std;
void insertBottom(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    insertBottom(s, target);
    s.push(temp);
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int target;
    cin >> target;
    insertBottom(s, target);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}