// VERY VERY IMPORTANT QUESTION
#include <bits/stdc++.h>
using namespace std;
class Nodes
{
public:
    int data;
    Nodes *next;
    Nodes(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Nodes()
    {
        cout << "Node with data : " << this->data << " is deleted";
        this->data = 0;
        this->next = nullptr;
    }
};
void print(Nodes *&head)
{
    Nodes *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int findLen(Nodes *&head)
{
    int i = 0;
    Nodes *temp = head;
    while (temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
Nodes *reverseK(Nodes *&head, int k)
{
    if (head == nullptr) // if ll is empty
    {
        return nullptr;
    }
    int len = findLen(head); // if reversing k nodes is grtr than ll length
    if (len < k)
    {
        return head;
    }
    // ll is not empty and we have a valid k value to reverse in grp
    Nodes *prev = nullptr;
    Nodes *curr = head;
    Nodes *forward = curr->next;
    int i = 0;
    while (i < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }
    if (forward != nullptr) // ll me nodes baki hai abhi
    {
        head->next = reverseK(forward, k);
    }
    return prev;
}
int main()
{
    Nodes *head = new Nodes(10);
    Nodes *second = new Nodes(20);
    Nodes *third = new Nodes(30);
    Nodes *forth = new Nodes(40);
    Nodes *fifth = new Nodes(50);
    Nodes *tail = new Nodes(60);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = tail;
    print(head);

    Nodes *prev = nullptr;
    head = reverseK(head, 4);
    print(head);
    return 0;
}