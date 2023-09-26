// FIND THE MIDDLE NODE OF LINKED LIST
// APPROACH : WE CAN TRAVEL WHOLE LL TO COUNT THE NO. OF NODES AND IF IT IS EVEN (N/2) IS ANS
// IF IT IS ODD THEN ((N/2)+1) IS THE ANS TC OF THIS APPROACH IS O(n)

// APPROACH 2 : SLOW AND FAST POINTER
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
        this->next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
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
Node *middle(Node *&head)
{
    if (head == nullptr)
    {
        cout << "ll is empty " << endl;
        return head;
    }
    if (head->next == nullptr) // only single element in ll
    {
        return head;
    }
    // ll has more than one element
    Node *fast = head;
    Node *slow = head;
    while (slow != nullptr && fast != nullptr)
    {
        fast = fast->next;
        if (fast == nullptr)
        {
            break;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    print(first);

    Node *m = middle(first);
    cout << "data of middle node is " << m->data;
    // agr 30 ans me chahiye to head ko head=head->next se start krna padega
    return 0;
}