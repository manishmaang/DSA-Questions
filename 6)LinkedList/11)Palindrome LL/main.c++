//  CHECK IF LL IS PALINDROME OR NOT
// BRUTE FORCE : LL KO TRAVERSE KR LENGE OR SARA DATA EK ARRAY ME COPY KRKE USE PALINDROME CHECK KR LENGE
// TC = O(n)  SC = O(n)
// OPTIMAL : LL KO MIDDLE SE REVERSE KR DENGE AND FIR START SE MIDDLE OR MIDDLE SE END TK
// CHECK KRENGE , TC = O(n)  SC = O(1)
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
};
Nodes *reverseLL(Nodes *head)
{

    Nodes *curr = head;
    Nodes *prev = nullptr;
    Nodes *forward = curr->next;
    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }
    return prev;
}
Nodes *middleLL(Nodes *&head)
{
    if (head == nullptr)
    {
        cout << "ll is empty";
        return head;
    }
    Nodes *slow = head;
    Nodes *fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // cout<<"middle node number : "<<pos<<endl;
    // cout<<"middle node value : "<<slow ->data<<endl;
    return slow;
}
bool palindromeLL(Nodes *&head)
{
    Nodes *temp = head;
    Nodes *mid = middleLL(head);
    Nodes *reversellhead = reverseLL(mid->next);
    // mid->next = reversellhead; // ye ll ko join krna imp nhi hai apne upr hai
    while (reversellhead != nullptr)
    {
        // cout<<"temp data "<<temp ->data<<endl;
        // cout<<"mid data "<<mid ->data <<endl;
        if (temp->data != reversellhead->data)
        {
            return false;
        }
        temp = temp->next;
        reversellhead = reversellhead->next;
    }
    return true;
}
void print(Nodes *&head)
{
    Nodes *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int pos = 0;
    Nodes *head = new Nodes(10);
    Nodes *second = new Nodes(20);
    Nodes *third = new Nodes(30);
    Nodes *fourth = new Nodes(30);
    Nodes *fifth = new Nodes(20);
    Nodes *sixth = new Nodes(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);
    if (palindromeLL(head))
    {
        cout << "ll is valid palindrome " << endl;
    }
    else
    {
        cout << "ll is not valid palindrome" << endl;
    }
    return 0;
}