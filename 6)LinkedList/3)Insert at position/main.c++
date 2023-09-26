
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

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
int findlength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void insertathead(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node *newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}

void insertatTail(Node *&head, Node *&tail, int data)
{
    if (head == nullptr)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    Node *newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void insertatPosition(int pos, Node *&head, Node *&tail, int data)
{
    if (head == NULL) // check krlenege ki linked list empty to nhi hai
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // IF WE WANNA INSERT AT 1ST POSITION, WE CAN CALL INSERTATHEAD
    if (pos == 0 || pos == 1)
    {
        insertathead(head, tail, data);
        return;
    }

    // IF WE WANNA INSERT AT LAST, WE CAN CALL INSERTATTAIL BUT WE HAVE TO FIND LL LENGTH
    int len = 0;
    len = findlength(head);
    if (pos > len)
    {
        insertatTail(head, tail, data);
        return;
    }

    // IF LINKED IS NOT EMPTY
    Node *newnode = new Node(data);
    int id = 1;
    Node *prev = head;
    while (id < pos - 1)
    {
        id++;
        prev = prev->next;
    }
    newnode->next = prev->next;
    prev->next = newnode;
}

int main()
{

    Node *head = nullptr;
    Node *tail = head;
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertatTail(head, tail, 40);
    insertatTail(head, tail, 50);
    insertathead(head, tail, 0);

    insertatPosition(3, head, tail, 15);
    insertatPosition(8, head, tail, 100);
    insertatPosition(0, head, tail, 101);
    print(head);

    return 0;
}