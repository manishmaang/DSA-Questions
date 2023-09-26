// LEARNING TO DELETE A NODE FROM LINKED LIST
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
    // DESTRUCTOR TO DELETE A NODE
    ~Node()
    {
        this->data = 0;
        this->next = nullptr;
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
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertatPosition(int pos, Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    if (pos == 0 || pos == 1)
    {
        insertathead(head, tail, data);
        return;
    }

    int len = 0;
    len = findlength(head);
    if (pos >= len)
    {
        insertatTail(head, tail, data);
        return;
    }

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

// DELETING A NODE FROM HEAD OF THE LINKED LIST
void deleteNode(Node *&head, Node *&tail, int pos)
{
    // CHECK IF LIST IS EMPTY
    if (head == nullptr)
    {
        cout << "cannot delete node coz list is empty" << endl;
        return;
    }
    if (pos == 0 || pos == 1) // delete at head of the linked list
    {
        // STEP 1 : CREATE A TEMPORARY NODE
        Node *temp = head;

        // STEP 2 :  UPDATE HEAD TO THE NEXT NODE
        head = head->next;

        // STEP 3 : UPDATE TEMP POINTER TO THE NULL
        temp = nullptr; // agr pointer null nhi krenge to vo baki nodes ko bhi delete krte chla jayega

        // STEP 4:  CALL DESTRUCTOR FOR TEMP NODE
        delete temp; // calling destructor
        return;
    }
    int len = findlength(head);
    if (pos >= len) // DELETING THE LAST NODE
    {
        // STEP 1 : FIND THE PREVIOUS NODE
        Node *prev = head;
        int i = 1;
        while (i < pos - 1)
        {
            prev = prev->next;
            i++;
        }
        // STEP 2 : UPDATE THE PREV NEXT TO NULL
        prev->next = nullptr;

        // STEP 3 : UPDATE TAIL NODE
        Node *temp = tail;
        tail = prev;

        // STEP 4 : DELETE TEMP
        delete temp;
        return;
    }
    // DELETING IN BETWEEN THE POSITION
    //  STEP 1 : FIND THE PREVIOUS NODE
    Node *prev = head;
    int i = 1;
    while (i < pos - 1)
    {
        prev = prev->next;
        i++;
    }
    // STEP 2 : MAKE A TEMP JO DELETE KRNE WALE NODE KO POINT KR RHA HO
    Node *temp = prev->next;

    // STEP 3 : UPDATE PREV NEXT
    prev->next = temp->next;

    // STEP 4 : UPDATE TEMP NEXT TO NULL
    temp->next = nullptr;

    // STEP 5 : CALL DESTRUCT FOR TEMP NODE
    delete temp;
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
    cout << endl;
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 7);
    deleteNode(head, tail, 3);
    print(head);
    return 0;
}