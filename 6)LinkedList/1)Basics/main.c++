#include <bits/stdc++.h>
using namespace std;

class Node // creating a node for linked list
{
public:
    int data;
    Node *next; // pointer to the next node

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    // this not how we declare nodes it is just for understanding how linked list works
    Node *first = new Node();
    Node *second = new Node(10);
    Node *third = new Node(20);
    Node *forth = new Node(30);
    Node *fifth = new Node();

    // just for understanding
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "printing the data stored in linked list " << endl;
    print(first);
    return 0;
}