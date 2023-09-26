// REVERSE A LINKED LIST start form line 119
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    ~Node()
    {
        cout << "deleting the node of data = " << this->data << endl;
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
void print(Node *&head) // TC is O(n)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int findLength(Node *&head) // TC is 0(n)
{
    int i = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
void insertatHead(Node *&head, Node *&tail, int data) // TC is O(1)
{
    if (head == nullptr) // if ll is empty
    {
        Node *newnode = new Node(data);
        head = newnode;
        // tail = newnode;
        return;
    }
    Node *newnode = new Node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertatTail(Node *&head, Node *&tail, int data) // TC is O(1)
{
    if (head == nullptr) // if ll is empty
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node *newnode = new Node(data);
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void insertatMiddle(Node *&head, Node *&tail, int data, int pos) // TC is O(n)
{
    if (head == nullptr)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    if (pos == 0 || pos == 1)
    {
        insertatHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if (pos > len)
    {
        insertatTail(head, tail, data);
        return;
    }
    Node *newnode = new Node(data);
    Node *temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        i++;
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    Node *current = newnode->next;
    current->prev = newnode;
}
// Code for reversing a LL, Logic by lovebabbar and my own code
// LOGIC : ek previous pointer , ek current pointer , ek next pointer
// current ko previous me point kraenge baki ka kaam recursion smhal lega
Node *reverseL(Node *&previous, Node *&curr)
{
    if (curr == nullptr)
    {
        cout << "LL has been reversed " << endl;
        return previous;
    }
    Node *nextnode = curr->next;
    curr->next = previous;
    return reverseL(curr, nextnode);
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *tail = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = tail;
    tail->prev = second;

    print(head);
    insertatHead(head, tail, 1);
    insertatTail(head, tail, 40);
    insertatMiddle(head, tail, 25, 4);
    print(head);

    Node *previous = nullptr;
    Node *curr = head;
    head = reverseL(previous, curr);
    print(head);
    return 0;
}