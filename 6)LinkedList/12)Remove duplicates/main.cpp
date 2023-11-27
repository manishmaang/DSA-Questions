// QUESTION : REMOVE DUPLICATES FROM SOTED LINKED LIST
#include <bits/stdc++.h>
using namespace std;
class nodes
{
public:
    int data;
    nodes *next;

    nodes(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~nodes()
    {
        this->data = 0;
        this->next = nullptr;
    }
};
void print(nodes *&head)
{
    nodes *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void removeD(nodes *&head)
{
    nodes *curr = head;
    while (curr != nullptr)
    {
        if ((curr->next != nullptr) && (curr->data == curr->next->data))
        {
            nodes *temp = curr->next;
            curr->next = curr->next->next;
            temp->next = nullptr;
            delete temp;
            // continue;
        }
        else
        {
            curr = curr->next;
        }
    }
}
int main()
{
    nodes *head = new nodes(10);
    nodes *sec = new nodes(20);
    nodes *third = new nodes(20);
    nodes *forth = new nodes(20);
    nodes *fifth = new nodes(20);
    nodes *tail = new nodes(30);

    head->next = sec;
    sec->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = tail;

    cout << "before removing duplicates : ";
    print(head);

    removeD(head);

    cout << "after removing duplicates ";
    print(head);
    return 0;
}