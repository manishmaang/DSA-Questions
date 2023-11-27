#include <bits/stdc++.h>
using namespace std;
// to use stack we must use its library file which is #include <stack>
int main()
{
    // NOTES IMPORTANT !!!!!
    // stack is a data structure which works in lifo order (LAST IN FIRST OUT)
    // we can only access the top element of stack
    // it does not has index based accessing unlike an array

    // creation
    stack<int> st; // stack st of type int

    // insetion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop(); // only the top element will get removed

    // check element on top
    cout << "current top element of stack is " << st.top() << endl;

    // check size of stack
    cout << "size of stack is " << st.size() << endl; // no. of elements in stack

    // check if stack is empty or not
    if (st.empty())
        cout << "stack is empty " << endl;
    else
        cout << "stack is not empty "<<endl;

    st.push(40);
    
    //printing the elements of stack
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}