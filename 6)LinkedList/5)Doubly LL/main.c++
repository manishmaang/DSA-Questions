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
    if (head == nullptr) // if ll is empty
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

    // NOTE : ye isiliye krna pda taki current node ka prev newnode se connect ho nhi to vo previous node se
    //  hi connect rehta or back travel me jo node hume add ki hai vo miss ho jati
    Node *current = newnode->next;
    current->prev = newnode;
}
int back(Node *&tail)
{
    int i = 0;
    Node *temp = tail;
    while (temp != nullptr)
    {
        i++;
        temp = temp->prev;
    }
    return i;
}
void deleteNode(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr)
    {
        cout << "cannot delete, LL is empty ";
        return;
    }
    // delete at head
    if (pos == 0 || pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }
    int len = findLength(head);
    if (pos >= len)
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = nullptr;
        tail->next = nullptr;
        delete temp;
        return;
    }
    int i = 1;
    Node *temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *del = temp->next;
    temp->next = del->next;
    del->next->prev = temp;
    del->next = del->prev = nullptr;
    delete del;
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
    print(head);
    insertatTail(head, tail, 40);
    print(head);

    insertatMiddle(head, tail, 25, 4);
    print(head);
    deleteNode(head, tail, 6);
    print(head);
    return 0;
}