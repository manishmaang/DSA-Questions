// DETECT LOOP WITH THE HELP OF FLOYD CYCLE DETECTION METHOD
//  IN THIS WE USE A SLOW AND FAST POINTER IF SLOW == FAST LOOP PRESENT
//  FAST == NULLPTR LOOP IS ABSENT
// STARTING POINT OF LOOP : JB LOOP DETECT HO JAYE ( SLOW == FAST ) THEN , SLOW KO WPS HEAD PR LGA DO
// FAST KO USI NODE PR RKHO JHA PR SLOW OR FAST MEET HUE;
// NOW SLOW OR FAST KO EK - EK NODE AAGE BEJO, OR VO LOOP KE STARTING POINT PR MEET KRENGE DUABRA
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
        cout << "node with data : " << this->data << " has been deleted";
        this->data = 0;
        this->next = nullptr;
    }
};
bool detectLoop(Nodes *&head)
{
    if (head == nullptr)
    {
        return false;
    }
    Nodes *temp = head;
    Nodes *slow = head;
    Nodes *fast = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
Nodes *startOFloop(Nodes *&head) // starting point of loop in ll
{

    if (head == nullptr)
    {
        return head;
    }
    Nodes *slow = head;
    Nodes *fast = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            slow = head;
            break;
        }
    }
    // ll me loop hua to while break ho jayega
    Nodes *prev = fast;
    while (slow != fast)
    {
        prev = fast; // prev fast ke just ek piche rahega, pehle prev = fast
        // fast = fast ->next se fast ek bd jayega or prev fast ki previous position me rahega

        slow = slow->next;
        fast = fast->next;
    }
    prev->next = nullptr; // removing the loop by making previous of starting point of loop as null
    return slow;
}
int main()
{
    Nodes *head = new Nodes(10);
    Nodes *first = new Nodes(20);
    Nodes *second = new Nodes(30);
    Nodes *third = new Nodes(40);
    Nodes *fourth = new Nodes(50);
    Nodes *fifth = new Nodes(60);
    Nodes *sixth = new Nodes(70);
    Nodes *seventh = new Nodes(80);
    Nodes *tail = new Nodes(90);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = tail;
    tail->next = fourth;

    bool l = detectLoop(head);
    cout << "loop is present " << l << endl;
    cout << "loop is present in " << startOFloop(head)->data << endl;
    cout << "loop is present " << detectLoop(head);
    return 0;
}