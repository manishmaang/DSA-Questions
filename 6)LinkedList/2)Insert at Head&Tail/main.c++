// LINKED LIST IS HINDI JO BOL RHE HAI WHI KRNA HAI BSS

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

// create a node at head mtlb new node head ke pehle banana hai or vo new node head bn jayega
void insertathead(Node *&head, Node *&tail, int data) // TC is O(1)
{
    if (head == nullptr) // check if it is first node
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    // STEP 1 : CREATE A NEW Node
    Node *newnode = new Node(data);

    // STEP 2 : NEW NODE KE NEXT KO HEAD PE POINT KRDO
    newnode->next = head;

    // STEP 4 : HEAD KO NEW NODE PR LE AAO
    head = newnode;
}

// Insert at tail of linked list means new node last me aayegi
void insertatTail(Node *&head, Node *&tail, int data) // TC is O(1)
{
    if (head == nullptr) // check if it is first node
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    // STEP 1 : CREATE A NEW NODE
    Node *newnode = new Node(data);

    // STEP 2 : TAIL KE NEXT KO NEWNODE ME ASSIGN KRDO
    tail->next = newnode;

    // STEP 3 : NEW NODE KO TAIL BNA DO
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

int main()
{

    Node *head = nullptr; // head = null ho to bhi chalega, jb head me koi node nhi ho tb bhi chalega
    Node *tail = head;
    insertathead(head, tail, 20);
    insertathead(head, tail, 30);
    insertatTail(head, tail, 40);
    insertatTail(head, tail, 50);
    insertathead(head, tail, 0);
    insertathead(head, tail, -1);
    print(head);
    return 0;
}