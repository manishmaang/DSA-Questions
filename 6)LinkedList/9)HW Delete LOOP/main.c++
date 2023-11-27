// VERY VERY IMP QUESTION
// DETECT AND DELETE LOOP : 1)CHECK LOOP IS PRESENT IN LL OR NOT
// 2) STARTING POINT OF LOOP
// 3) REMOVE LOOP
// home work detect loop in ll with help of map
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
bool detectLoop(Nodes *&head, map<Nodes *, bool> &mp)
{
    Nodes *temp = head;

    while (temp != nullptr)
        ;

    return true;
}
int main()
{
    map<Nodes *, bool> mp;
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
    tail->next = head;
    bool l = detectLoop(head, mp);
    return 0;
}
