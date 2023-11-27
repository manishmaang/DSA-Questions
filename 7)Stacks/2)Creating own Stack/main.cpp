// IF WE WANNA CREATE A STACK CLASS FROM SCRATCH THEN WE MUST GIVE IT SOME CERTAIN FUNCTIONS
// PUSH , POP , EMPTY , SIZE , TOP
// WE CAN CREATE STACK THROUGH AN ARRAY (DYNAMIC) OR LL
#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int *arr; // to access the dynamic array(heap)
    int size; // dynamic array bnate time uska size dena pdta hai to ye uske liye
    // NOTE : ye size total no. of elements nhi batata

    int top; // to access the recent element of the stack

public:
    Stack(int size)
    {
        arr = new int[size]; // is line me arr pointer ko memory allocate ho jayegi
        this->size = size;
        top = -1; // kyuki starting me to stack empty rahega
    }

    // functions (behaviour of stack)
    void push(int data)
    {
        if ((size - top) == 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow " << endl;
        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty " << endl;
            // return NULL;
        }
        return arr[top];
    }

    // this function returns the no. of element present in stack
    int getSize()
    {
        return top + 1;
    }
};
int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.getSize() << endl;
    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl
         << s.getSize();
    return 0;
}