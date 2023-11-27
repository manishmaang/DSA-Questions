// QUESTION : IMPLEMENT TWO STACKS USING SINGLE ARRAY
//  BRUTE FORCE : DONO STACKS KO HALF - HALF ARRAY DEDO  PROBLEM : MEMORY WASTAGE
//  OPTIMIZE : EK STAKCK KO ARR KI STARTING SE OR DUSRE KO END SE PEECHE WALI DIRECTION ME ALLOCATE KRO
// agr 2 se zyada stack implement krne hai on single arr to size divide by n krke hi ho payenge

#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        top1 = -1;
        top2 = size;
        this->size = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
            cout << "Stack1 is Overflowed" << endl;
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
            cout << "Stack1 underflowed";
        else
            top1--;
    }

    void push2(int data)
    {
        if (top2 - top1 == 1)
            cout << "Stack2 is Overflowed" << endl;
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop2()
    {
        if (top2 == size + 1)
            cout << "Stack1 underflowed";
        else
            top2++;
    }
    // void print()
    // {
    //     cout << "top1 is " << top1 << endl;
    //     cout << "top2 is " << top2 << endl;
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }
};
int main()
{
    Stack s(10);
    // s.push1(10);
    // s.print();
    // s.push1(20);
    // s.print();
    // s.push1(30);
    // s.print();
    // s.push1(40);
    // s.print();

    // s.push2(100);
    // s.print();
    // s.push2(110);
    // s.print();
    return 0;
}